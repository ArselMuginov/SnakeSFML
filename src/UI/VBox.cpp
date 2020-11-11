#include "UI/VBox.hpp"

namespace ui
{
	template <class... Ts>
	std::unique_ptr<VBox> VBox::create(Ts&&... args)
	{
		return std::make_unique<VBox>(std::forward<Ts>(args)...);
	}

	void VBox::update()
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
				currentPosition.y += int(element->getGlobalBounds().height + margin);
			}
		}
	}

	void VBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
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
