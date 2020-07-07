#pragma once
#include <filesystem>
#include <map>
#include <fstream>
#include <codecvt>
#include <SFML/System/String.hpp>

class LocaleLoader
{
public:
	LocaleLoader();
	~LocaleLoader();

	void loadLocale(const sf::String& localeKey);
	sf::String getString(const sf::String& section, const sf::String& key);

private:
	const std::filesystem::path m_localePath;
	const std::filesystem::path m_localeFileName;
	std::map<sf::String, std::filesystem::path> m_locales;
	std::map<std::pair<sf::String, sf::String>, sf::String> m_currentLocaleMap;
};
