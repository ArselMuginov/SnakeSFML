#include "FontHolder.hpp"

FontHolder::FontHolder(const std::string& rootPath)
{
	for (std::size_t i = 0; i < c_paths.size(); i++)
	{
		m_resources.insert({static_cast<FontId>(i), std::make_unique<sf::Font>()});
		bool loaded = m_resources.at(static_cast<FontId>(i))->loadFromFile(rootPath + std::string{c_paths[i]});
		
		if (!loaded)
		{
			throw "Error loading font";
		}
	}
}
