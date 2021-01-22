#include "FontHolder.hpp"
#include "Utility/Paths.hpp"
#include <filesystem>
#include <sstream>

FontHolder::FontHolder()
{
	for (std::size_t i = 0; i < c_paths.size(); i++)
	{
		FontId fontId{static_cast<FontId>(i)};
		std::filesystem::path fontPath{Paths::fonts / c_paths[i]};

		m_resources.insert({fontId, std::make_unique<sf::Font>()});
		bool loaded = m_resources.at(fontId)->loadFromFile(fontPath.string());

		if (!loaded)
		{
			std::ostringstream oss;
			oss << "Cannot load font: " << fontPath;
			throw std::runtime_error{oss.str()};
		}
	}
}
