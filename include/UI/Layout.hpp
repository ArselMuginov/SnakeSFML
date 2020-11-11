#pragma once
#include "Padding.hpp"
#include "UIElement.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <vector>
#include <memory>
#include <cstddef>

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

		template <class... Ts>
		static std::unique_ptr<Layout> create(Ts&&... args);

		void addElement(std::unique_ptr<UIElement> element);
		void removeElement(std::size_t index);
		virtual void update() = 0;
		virtual sf::FloatRect getLocalBounds() const;
		void setStyle(Style style);

		const UIElement& operator[](std::size_t index) const;
		
		Padding padding;
		float margin;
		bool stretchContent;
		sf::RectangleShape background;

	protected:
		std::vector<std::unique_ptr<UIElement>> m_children;
	};
}
