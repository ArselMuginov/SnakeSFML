#pragma once
#include "Layout.hpp"

namespace ui
{
	class HBox : public Layout
	{
	public:
		virtual void update();

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};
}
