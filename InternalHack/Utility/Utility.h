#pragma once

#include <windows.h>
#include <vector>
#include <iostream>
#include "../Config/Config.h"

uintptr_t FindAddress(uintptr_t ptr, std::vector<unsigned int> offsets);
uintptr_t FindAddress(uintptr_t ptr, std::vector<unsigned int> offsets, std::ostream& out);
