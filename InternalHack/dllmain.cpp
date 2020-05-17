#include "windows.h"

DWORD WINAPI InternalHack(HINSTANCE);

BOOL APIENTRY DllMain(HINSTANCE moduleHandle, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)InternalHack, moduleHandle, 0, nullptr));
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

DWORD WINAPI InternalHack(HINSTANCE moduleHandle)
{
    int offsetAmmo = 0x150;
    int baseOffset = 0x10F4F4;

    uintptr_t pModuleBase = (uintptr_t)GetModuleHandle(L"ac_client.exe");
    uintptr_t pBaseAddress = *(uintptr_t*)(pModuleBase + baseOffset);
    uintptr_t pAmmo = pBaseAddress + offsetAmmo;
    int* ammo = (int*)pAmmo;
    *ammo = 1337;

    FreeLibraryAndExitThread(moduleHandle, 0);
    return 0;
}