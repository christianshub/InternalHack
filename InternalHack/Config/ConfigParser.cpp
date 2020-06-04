#include "ConfigParser.h"

std::string ToLowercase(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(),
		[](unsigned char c) { return std::tolower(c); });

	return str;
}


std::string ReplaceAllSubStr(std::string& mainStr, const std::string toBeReplaced, const std::string replaceWith)
{
	size_t pos = std::string::npos;
	while ((pos = mainStr.find(toBeReplaced)) != std::string::npos)
	{
		mainStr.replace(pos, toBeReplaced.length(), replaceWith);
	}

	return mainStr;
}

unsigned int ParseNumerics(const std::string num)
{
	if (num != "1")
	{
		return 0;
	}

	return 1;
}

std::vector<std::string> ParseSignatures(const std::string signatures)
{
	std::vector<std::string> container = {};
	std::string sig = signatures;

	// To lower case
	ToLowercase(sig);

	// Remove spaces
	ReplaceAllSubStr(sig, " ", "");

	// Check for non-hex
	if (sig.find_first_not_of("abcdef0123456789,?") != std::string::npos)
	{
		std::cout << "Error, signature can only contain hex letters and numbers: abcdef0123456789" << std::endl;
		std::exit(1);
	}

	// Insert signatures into container
	std::stringstream ss(sig);
	while (ss.good()) {
		std::string substr;
		std::getline(ss, substr, ',');
		container.push_back(substr);
	}

	// Make sure each sig is divisble by 2.
	for (size_t i = 0; i < container.size(); i++)
	{
		if (container[i].length() % 2 != 0)
		{
			std::cout << "Incorrect signature size" << std::endl;
			std::exit(1);
		}
	}

	return container;
}

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