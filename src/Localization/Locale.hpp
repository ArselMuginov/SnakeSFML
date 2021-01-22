#pragma once
#include <SFML/System/String.hpp>
#include <filesystem>
#include <map>
#include <string_view>
#include <unordered_map>

class Locale
{
public:
	Locale(std::string_view startupLocaleKey);
	void load(std::string_view localeKey);
	void unload();
	const sf::String& operator()(std::string_view section, std::string_view key) const;

private:
	static constexpr std::string_view c_dataFileName{"data"};
	static constexpr std::string_view c_nameFileName{"name"};

	static std::unordered_map<std::string, sf::String> m_localeNames;
	static std::unordered_map<std::string, std::filesystem::path> m_localePaths;

	std::map<std::pair<std::string, std::string>, sf::String> m_data;
};
