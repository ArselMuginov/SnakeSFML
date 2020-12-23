#include "Locale.hpp"
#include <fstream>

Locale::Locale() : m_data{}
{
}

Locale::Locale(const std::filesystem::path& path) : m_data{}
{
	load(path);
}

void Locale::load(const std::filesystem::path& path)
{
	std::ifstream localeFile(path);
	std::string line;
	std::string sectionName = "";

	while (std::getline(localeFile, line))
	{
		// Empty or comment
		if (line.empty() || line[0] == '#')
		{
			continue;
		}

		// Section
		if (line[0] == '[')
		{
			sectionName = line.substr(1, line.length() - 2);
			continue;
		}

		// Key value line
		auto splitPos = line.find('=');
		std::string key = line.substr(0, splitPos);
		sf::String value = sf::String::fromUtf8(line.begin() + splitPos + 1, line.end());
		m_data.insert({ std::make_pair(sectionName, key), value });
	}
}

void Locale::unload()
{
	m_data.clear();
}

const sf::String& Locale::operator()(std::string_view section, std::string_view key) const
{
	return m_data.at({std::string{section}, std::string{key}});
}
