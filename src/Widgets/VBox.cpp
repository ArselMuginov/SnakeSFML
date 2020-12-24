#include "VBox.hpp"
#include <cmath>

void VBox::updateLayout()
{
	float outlineThickness = background.getOutlineThickness();
	background.setPosition(outlineThickness, outlineThickness);
	
	sf::FloatRect bounds = getLocalBounds();
	sf::FloatRect boundsPadded{
		bounds.left + padding.left,
		bounds.top + padding.top,
		bounds.width - padding.left - padding.right,
		bounds.height - padding.top - padding.bottom
	};
	sf::Vector2f currentPosition{
		std::round(boundsPadded.left),
		std::round(boundsPadded.top)
	};

	if (stretchContent)
	{
		// TODO: implement
	}
	else
	{
		for (const auto& element : m_children)
		{
			element->setPosition(currentPosition);
			currentPosition.y += int(element->getGlobalBounds().height + spacing);
		}
	}
}
