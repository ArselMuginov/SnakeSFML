#pragma once
#include "Widgets/Layout.hpp"

class VBox : public Layout
{
public:
	using Layout::Layout;

	template <class... Ts>
	static std::unique_ptr<VBox> create(Ts&&... args);

	virtual void update();

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
