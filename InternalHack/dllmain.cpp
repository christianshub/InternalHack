#include <iostream>
#include "windows.h"
#include "Keys.h"
#include "Utility/Utility.h"
#include "Config/Config.h"
#include "Config/ConfigParser.h"


DWORD __stdcall Hack(HMODULE hModule)
{
    // Hijack Console
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    std::cout << "\n======================  INTERNAL HACK INJECTED  ======================" << std::endl;
    std::cout << "Press '8'         Activate ammunition hack" << std::endl;

    std::cout << "Press '9'         Detach hack from process" << std::endl;
    std::cout << "======================================================================" << "\n" << std::endl;

    uintptr_t pModuleBase = (uintptr_t) GetModuleHandle(NULL); // We get the base from where we are, inside L"ac_client.exe"

    while (true)
    {
        if (GetAsyncKeyState(KeyPress::VK_8) & 1)
        {
            // Config.ini check and parse it's offsets
            std::string filePath = VerifyINI("Hack", "config.ini", { "[Config]", "Ammunition=" });
            std::string rawAmmoOffs = ReadKey("Config", "Ammunition", filePath);
            std::vector<unsigned int> ammoOffs = ParseOffsets(rawAmmoOffs);

            // Get pointer chain iteration output
            std::string fileName = GetDesktopPath() + "\\pointerChains.txt";
            std::ofstream fout(fileName);

            // Iterate pointer chain
            uintptr_t pAmmo = FindAddress(pModuleBase, ammoOffs, fout);

            fout.close();

            // Change value
            *(int*) pAmmo = 1337;
        }

        if (GetAsyncKeyState(KeyPress::VK_9) & 1)
        {
            std::cout << "Detaching... " << std::endl;
            Sleep(3000);
            break;
        }
        Sleep(100);
    }

    fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Hack, hModule, 0, 0));
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


//// moduleBase: 400000, playerbase ptr: moduleBase + 0x10F4F4
//std::cout << "moduleBase: " << std::uppercase << std::hex << pModuleBase << std::endl;
//
//// Address 0x50F4F4
//std::cout << "localPlayer pointer (moduleBase + 0x10F4F4)" << std::uppercase << std::hex << (pModuleBase + 0x10F4F4) << std::endl;
//
//// 0x50F4F4 contains a ptr, pointing to playerbase.
//uintptr_t pBaseAddress = *(uintptr_t*)(pModuleBase + 0x10F4F4);
//
//std::cout << "pBaseAddress: " << std::uppercase << std::hex << (pBaseAddress) << std::endl;
//
//int offsetAmmo = 0x150;
//
//uintptr_t pAmmo = pBaseAddress + offsetAmmo;
//std::cout << "pAmmo: " << std::uppercase << std::hex << (pAmmo) << std::endl;
//
//int* ammo = (int*)pAmmo;
//*ammo = 1337;