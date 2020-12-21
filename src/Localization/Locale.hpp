#pragma once
#include <SFML/System/String.hpp>
#include <filesystem>
#include <map>
#include <string_view>

class Locale
{
public:
	Locale();
	Locale(const std::filesystem::path& path);
	void load(const std::filesystem::path& path);
	void unload();
	const sf::String& operator()(std::string_view section, std::string_view key) const;
private:
	std::map<std::pair<std::string, std::string>, sf::String> m_data;
};
