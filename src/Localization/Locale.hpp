#pragma once
#include <SFML/System/String.hpp>
#include <codecvt>
#include <filesystem>
#include <fstream>
#include <map>

class Locale
{
public:
	Locale();
	void load(const std::filesystem::path& path);
	void unload();
	const sf::String& operator()(std::pair<std::string, std::string> key) const;
private:
	std::map<std::pair<std::string, std::string>, sf::String> m_data;
};
