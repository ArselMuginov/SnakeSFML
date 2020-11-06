#include "UI/HBox.hpp"

namespace ui
{
	void HBox::update()
	{
		sf::FloatRect bounds = background.getLocalBounds();
		sf::FloatRect boundsPadded(
			bounds.left + padding.left,
			bounds.top + padding.top,
			bounds.width - padding.left - padding.right,
			bounds.height - padding.top - padding.bottom
		);
		sf::Vector2f currentPosition(int(boundsPadded.left), int(boundsPadded.top));

		if (stretchContent)
		{
			// TODO: implement
		}
		else
		{
			for (const auto& element : m_children)
			{
				element->setPosition(currentPosition);
				currentPosition.x += int(element->getGlobalBounds().width + margin);
			}
		}
	}

	void HBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		states.texture = nullptr;

		target.draw(background, states);
		for (const auto& child : m_children)
		{
			target.draw(*child, states);
		}
	}
}
