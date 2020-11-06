#include "Localization/LocaleManager.hpp"

LocaleManager::LocaleManager() :
	m_localesFolder("../resources/Locales"),
	m_dataFileName("data"),
	m_nameFileName("name"),
	m_localeNames(),
	m_localePaths()
{
	for (const auto& entry : std::filesystem::directory_iterator(m_localesFolder))
	{
		std::string localeKey = entry.path().filename().string();

		std::ifstream nameFile(entry.path() / m_nameFileName);
		std::string localeName;
		nameFile >> localeName;

		m_localeNames.insert({ localeKey, localeName });
		m_localePaths.insert({ localeKey, entry.path() / m_dataFileName });
	}
}

const std::map<std::string, sf::String>& LocaleManager::getLocaleNames()
{
	return m_localeNames;
}

const std::filesystem::path& LocaleManager::getLocalePath(const std::string& localeKey)
{
	if (m_localePaths.find(localeKey) == m_localePaths.end())
	{
		throw "No locale found with specified key";
	}

	return m_localePaths.at(localeKey);
}
