#include "FontHolder.hpp"
#include "Utility/Paths.hpp"
#include <filesystem>
#include <sstream>

FontHolder::FontHolder()
{
	for (std::size_t i = 0; i < c_paths.size(); i++)
	{
		m_resources.insert({
			static_cast<FontId>(i),
			std::make_unique<sf::Font>()
		});
	}
}

void FontHolder::load(FontId id) const
{
	std::filesystem::path fontPath{Paths::fonts / c_paths[static_cast<std::size_t>(id)]};
	bool loaded = m_resources.at(id)->loadFromFile(fontPath.string());

	if (!loaded)
	{
		std::ostringstream oss;
		oss << "Cannot load font: " << fontPath;
		throw std::runtime_error{oss.str()};
	}
}
