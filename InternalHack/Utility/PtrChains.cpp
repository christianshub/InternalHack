#include "PtrChains.h"



uintptr_t FindAddress(uintptr_t base, std::vector<unsigned int> offsets)
{
    if (offsets.size() == 0)
    {
        return base;
    }

    uintptr_t address = base + offsets[0];

    for (unsigned int i = 1; i < offsets.size(); ++i)
    {
        address = *(uintptr_t*)address;
        address += offsets[i];
    }

    return address;
}

uintptr_t FindAddress(uintptr_t base, std::vector<unsigned int> offsets, std::ostream& out)
{
    out << "base:              0x" << std::uppercase << std::hex << base << std::endl;
    out << "offsets[0]:        0x" << std::uppercase << std::hex << offsets[0] << std::endl;
    out << "base + offsets[0]: 0x" << std::uppercase << std::hex << (base + offsets[0]) << std::endl;

    uintptr_t address = base + offsets[0];
    uintptr_t oldAddr = address;
    out << "\n-- Loop:      \n" << std::endl;

    // Multiple offset given
    for (unsigned int i = 1; i < offsets.size(); ++i)
    {
        out << "offsets[" << i << "]: 0x" << std::uppercase << std::hex << offsets[i] << std::endl;
        oldAddr = address;

        address = *(uintptr_t*)address;

        out << "0x" << std::uppercase << std::hex << oldAddr << " -> 0x" << address << std::endl;
 
        oldAddr = address;

        address += offsets[i];

        out << "End addy:   0x" << std::uppercase << std::hex << address << " (== 0x" << oldAddr << " + 0x" << offsets[i] << ")" << "\n" << std::endl;
    }

    return address;
}
