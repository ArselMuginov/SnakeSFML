#pragma once
#include "Locale.hpp"

class LocaleManager
{
public:
	LocaleManager();

	const std::map<std::string, sf::String>& getLocaleNames();
	const std::filesystem::path& getLocalePath(const std::string& localeKey);

private:
	const std::filesystem::path m_localesFolder;
	const std::filesystem::path m_dataFileName;
	const std::filesystem::path m_nameFileName;
	std::map<std::string, sf::String> m_localeNames;
	std::map<std::string, std::filesystem::path> m_localePaths;
};
