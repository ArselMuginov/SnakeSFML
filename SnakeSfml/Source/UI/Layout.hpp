#pragma once
#include "Padding.hpp"
#include "UIElement.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <vector>
#include <memory>

namespace ui
{
	class Layout : public UIElement
	{
	public:
		Layout();

		void addElement(std::unique_ptr<UIElement> element);
		void removeElement(size_t index);
		virtual void update() = 0;
		virtual sf::FloatRect getLocalBounds() const;

		const UIElement& operator[](size_t index) const;
		
		Padding padding;
		float margin;
		bool stretchContent;
		sf::RectangleShape background;

	protected:
		std::vector<std::unique_ptr<UIElement>> m_children;
	};
}
