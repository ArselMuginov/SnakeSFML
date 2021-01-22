#pragma once
#include "Resource/ResourceHolder.hpp"
#include <SFML/Graphics/Font.hpp>
#include <array>
#include <string_view>

enum class FontId
{
	Default,
	ZhCN
};

class FontHolder : public ResourceHolder<FontId, sf::Font>
{
public:
	FontHolder();

private:
	static constexpr std::array<std::string_view, 2> c_paths{
		"NotoSans/Regular.ttf",
		"NotoSansSC/Regular.otf"
	};
};
