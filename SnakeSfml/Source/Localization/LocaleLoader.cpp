#include "LocaleLoader.hpp"

LocaleLoader::LocaleLoader() : m_localePath(std::filesystem::path("Resources") / "Locale"), m_localeFileName(std::filesystem::path("main.locale")), m_locales(), m_currentLocaleMap()
{
	for (const auto& entry : std::filesystem::directory_iterator(m_localePath))
	{
		m_locales[sf::String(entry.path().filename().wstring())] = entry.path();
	}
}

LocaleLoader::~LocaleLoader()
{
}

void LocaleLoader::loadLocale(const sf::String& localeKey)
{
	std::wifstream localeFile(m_locales[localeKey] / m_localeFileName);
	localeFile.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));

	std::wstring line;
	sf::String sectionName = L"";
	while (std::getline(localeFile, line))
	{
		// Empty or comment
		if (line.empty() or line[0] == L'#')
		{
			continue;
		}

		// Section
		if (line[0] == L'[')
		{
			sectionName = line.substr(1, line.length() - 2);
			continue;
		}

		// Key value line
		auto splitPos = line.find(L'=');
		sf::String key = line.substr(0, splitPos);
		sf::String value = line.substr(splitPos + 1);
		m_currentLocaleMap[std::make_pair(sectionName, key)] = value;
	}
}

sf::String LocaleLoader::getString(const sf::String& section, const sf::String& key)
{
	return m_currentLocaleMap[std::make_pair(section, key)];
}
