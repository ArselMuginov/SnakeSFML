#pragma once
#include <codecvt>
#include <filesystem>
#include <fstream>
#include <map>
#include <SFML/System/String.hpp>

namespace
{
	namespace stdfs = std::filesystem;
}

class LocaleLoader
{
public:
	LocaleLoader();

	void loadLocale(const sf::String& localeKey);
	sf::String getString(const sf::String& section, const sf::String& key);

private:
	const stdfs::path m_localePath;
	const stdfs::path m_localeFileName;
	std::map<sf::String, stdfs::path> m_locales;
	std::map<std::pair<sf::String, sf::String>, sf::String> m_currentLocaleMap;
};
