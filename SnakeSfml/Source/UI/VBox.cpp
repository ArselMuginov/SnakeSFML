#include "VBox.hpp"

namespace ui
{
	void VBox::update()
	{
		sf::FloatRect bounds = background.getLocalBounds();
		sf::FloatRect boundsPadded(
			bounds.left + padding.left,
			bounds.top + padding.top,
			bounds.width - padding.left - padding.right,
			bounds.height - padding.top - padding.down
		);
		sf::Vector2f currentPosition(boundsPadded.left, boundsPadded.top);
		
		if (stretchContent)
		{
			// TODO: implement
		}
		else
		{
			for (const auto& element : m_children)
			{
				element->setPosition(currentPosition);
				currentPosition.y += element->getGlobalBounds().height + margin;
			}
		}
	}
}