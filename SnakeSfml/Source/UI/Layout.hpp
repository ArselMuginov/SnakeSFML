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
		enum class Style
		{
			Invisible,
			WhiteBorder,
			BlackBorder
		};

		Layout();
		Layout(const sf::Vector2f& size);

		void addElement(std::unique_ptr<UIElement> element);
		void removeElement(size_t index);
		virtual void update() = 0;
		virtual sf::FloatRect getLocalBounds() const;
		void setStyle(Style style);

		const UIElement& operator[](size_t index) const;
		
		Padding padding;
		float margin;
		bool stretchContent;
		sf::RectangleShape background;

	protected:
		std::vector<std::unique_ptr<UIElement>> m_children;
	};
}
