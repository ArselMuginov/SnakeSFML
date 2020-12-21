#include "FontHolder.hpp"
#include <sstream>

FontHolder::FontHolder(std::string_view rootPath)
{
	for (std::size_t i = 0; i < c_paths.size(); i++)
	{
		FontId fontId{static_cast<FontId>(i)};
		std::string fontPath{rootPath};
		fontPath.append(c_paths[i]);

		m_resources.insert({fontId, std::make_unique<sf::Font>()});
		bool loaded = m_resources.at(fontId)->loadFromFile(fontPath);
		
		if (!loaded)
		{
			std::ostringstream oss;
			oss << "Cannot load font: " << fontPath;
			throw std::runtime_error{oss.str()};
		}
	}
}
