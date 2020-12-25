#include "HBox.hpp"
#include <cmath>

void HBox::updateLayout()
{
	float outlineThickness = m_background.getOutlineThickness();
	m_background.setPosition(outlineThickness, outlineThickness);

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
			currentPosition.x += int(element->getGlobalBounds().width + spacing);
		}
	}
}
