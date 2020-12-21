#include "LocaleManager.hpp"
#include <fstream>

LocaleManager::LocaleManager(std::string_view rootPath) :
	c_localesFolder{std::string{rootPath} + "data/Locales"},
	c_dataFileName{"data"},
	c_nameFileName{"name"},
	m_localeNames{},
	m_localePaths{}
{
	for (const auto& entry : std::filesystem::directory_iterator(c_localesFolder))
	{
		std::string localeKey = entry.path().filename().string();

		std::ifstream nameFile(entry.path() / c_nameFileName);
		std::string localeName;
		nameFile >> localeName;

		m_localeNames.insert({ localeKey, localeName });
		m_localePaths.insert({ localeKey, entry.path() / c_dataFileName });
	}
}

const std::unordered_map<std::string, sf::String>& LocaleManager::getLocaleNames()
{
	return m_localeNames;
}

const std::filesystem::path& LocaleManager::getLocalePath(std::string_view localeKey)
{
	const auto& iter = m_localePaths.find(std::string{localeKey});
	if (iter == m_localePaths.end())
	{
		throw std::invalid_argument{"No locale found with specified key"};
	}
	return iter->second;
}
