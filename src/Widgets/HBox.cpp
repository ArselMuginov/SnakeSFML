#include "HBox.hpp"

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
