#pragma once
#include "Layout.hpp"

namespace ui
{
	class HBox : public Layout
	{
	public:
		using Layout::Layout;

		template <class... Ts>
		static std::unique_ptr<HBox> create(Ts&&... args);

		virtual void update();

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};
}
