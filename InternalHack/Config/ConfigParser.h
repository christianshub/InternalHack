#pragma once

#include <windows.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

/// <summary>
/// Replaces upper case letters to lower case
/// </summary>
std::string ToLowercase(std::string& str);

/// <summary>
/// Replaces all substrings in a string
/// </summary>
std::string ReplaceAllSubStr(std::string& mainStr, std::string toBeReplaced, std::string replaceWith);

/// <summary>
/// 
/// </summary>
std::vector<unsigned int> ParseOffsets(const std::string);
