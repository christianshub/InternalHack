#include "ConfigParser.h"

std::vector<unsigned int> ParseOffsets(const std::string input)
{
	//std::vector<std::string> strContainer = {};
	std::vector<unsigned int> uintContainer = {};
	std::string rawString = input;
	
	// Remove spaces
	ReplaceAllSubStr(rawString, " ", "");

	// Insert into vector, comma seperated
	std::stringstream ss(rawString);
	while (ss.good()) {
		std::string substr;
		std::getline(ss, substr, ',');
		uintContainer.push_back(std::stoul(substr, nullptr, 16));
	}

	return uintContainer;
}