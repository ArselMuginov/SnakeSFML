#pragma once
#include "Localization/Locale.hpp"
#include <SFML/System/String.hpp>
#include <filesystem>
#include <string_view>
#include <unordered_map>

class LocaleManager
{
public:
	LocaleManager(std::string_view rootPath);

	const std::unordered_map<std::string, sf::String>& getLocaleNames();
	const std::filesystem::path& getLocalePath(std::string_view localeKey);

private:
	const std::filesystem::path c_localesFolder;
	const std::filesystem::path c_dataFileName;
	const std::filesystem::path c_nameFileName;
	std::unordered_map<std::string, sf::String> m_localeNames;
	std::unordered_map<std::string, std::filesystem::path> m_localePaths;
};
