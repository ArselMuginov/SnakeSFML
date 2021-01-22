#include "Locale.hpp"
#include "Utility/Paths.hpp"
#include <fstream>

std::unordered_map<std::string, sf::String> Locale::m_localeNames;
std::unordered_map<std::string, std::filesystem::path> Locale::m_localePaths;

Locale::Locale(std::string_view startupLocaleKey) : m_data{}
{
	for (const auto& entry : std::filesystem::directory_iterator(Paths::locales))
	{
		std::string localeKey = entry.path().filename().string();

		std::ifstream nameFile(entry.path() / c_nameFileName);
		std::string localeName;
		nameFile >> localeName;

		m_localeNames.insert({localeKey, localeName});
		m_localePaths.insert({localeKey, entry.path() / c_dataFileName});
	}

	load(startupLocaleKey);
}

void Locale::load(std::string_view localeKey)
{
	const auto& iter = m_localePaths.find(std::string{localeKey});
	if (iter == m_localePaths.end())
	{
		throw std::invalid_argument{"No locale found with specified key"};
	}

	std::ifstream localeFile(iter->second);
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
		m_data.insert({std::make_pair(sectionName, key), value});
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
