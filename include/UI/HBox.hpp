#pragma once
#include "Layout.hpp"

namespace ui
{
	class HBox : public Layout
	{
	public:
		using Layout::Layout;
		virtual void update();

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};
}
