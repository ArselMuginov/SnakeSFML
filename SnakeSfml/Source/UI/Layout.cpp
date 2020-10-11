#include "Layout.hpp"

namespace ui
{
	Layout::Layout() :
		padding(),
		margin(0),
		stretchContent(false),
		background(),
		m_children()
	{
	}

	void Layout::addElement(std::unique_ptr<UIElement> element)
	{
		m_children.push_back(std::move(element));
	}

	void Layout::removeElement(size_t index)
	{
		m_children.erase(std::next(m_children.begin(), index));
	}

	sf::FloatRect Layout::getLocalBounds() const
	{
		return background.getLocalBounds();
	}

	const UIElement& Layout::operator[](size_t index) const
	{
		return *m_children[index];
	}
}
