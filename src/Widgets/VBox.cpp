#include "VBox.hpp"
#include <cmath>

void VBox::updateLayout()
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

	// Calculate minimal height occupied by child widgets
	float minimalHeight = 0;
	for (const auto& element : m_children)
	{
		minimalHeight += element->getLocalBounds().height + spacing;
	}
	minimalHeight -= spacing;

	// Calculate starting Y position of child widgets according to minimal height and area available
	float currentY = std::round(areaAvailable.top + areaAvailable.height / 2.f - minimalHeight / 2.f);

	// Position child widgets
	float halfWidthAvailable = areaAvailable.width / 2.f;
	for (const auto& element : m_children)
	{
		sf::FloatRect elementBounds = element->getLocalBounds();
		element->setPosition(
			std::round(halfWidthAvailable - elementBounds.width / 2.f),
			std::round(currentY)
		);
		currentY += elementBounds.height + spacing;
	}
}
