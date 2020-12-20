#include "FontHolder.hpp"

FontHolder::FontHolder(std::string_view rootPath)
{
	for (std::size_t i = 0; i < c_paths.size(); i++)
	{
		m_resources.insert({static_cast<FontId>(i), std::make_unique<sf::Font>()});
		bool loaded = m_resources.at(static_cast<FontId>(i))->loadFromFile(std::string{rootPath}.append(c_paths[i]));
		
		if (!loaded)
		{
			throw "Error loading font";
		}
	}
}
