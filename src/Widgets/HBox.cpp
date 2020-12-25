#include "HBox.hpp"
#include <cmath>

void HBox::updateLayout()
{
	// Position background according to border thickness
	float outlineThickness = m_background.getOutlineThickness();
	m_background.setPosition(outlineThickness, outlineThickness);

	// Calculate area available for child widgets
	sf::FloatRect layoutBounds = getLocalBounds();
	sf::FloatRect areaAvailable{
		layoutBounds.left + padding.left,
		layoutBounds.top + padding.top,
		layoutBounds.width - padding.left - padding.right,
		layoutBounds.height - padding.top - padding.bottom
	};

	// Calculate minimal width occupied by child widgets
	float minimalWidth = 0;
	for (const auto& element : m_children)
	{
		minimalWidth += element->getLocalBounds().width + spacing;
	}
	minimalWidth -= spacing;

	// Calculate starting X position of child widgets according to minimal width and area available
	float currentX = areaAvailable.left + areaAvailable.width / 2.f - minimalWidth / 2.f;

	// Position child widgets
	float halfHeightAvailable = areaAvailable.height / 2.f;
	for (const auto& element : m_children)
	{
		sf::FloatRect elementBounds = element->getLocalBounds();
		element->setPosition(
			std::round(currentX),
			std::round(halfHeightAvailable - elementBounds.width / 2.f)
		);
		currentX = elementBounds.width + spacing;
	}
}
