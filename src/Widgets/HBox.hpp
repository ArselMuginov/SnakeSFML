#pragma once
#include "Widgets/Layout.hpp"

class HBox : public Layout
{
public:
	using Layout::Layout;
	virtual void update();

	template <class... Ts>
	static std::unique_ptr<HBox> create(Ts&&... args)
	{
		return std::make_unique<HBox>(std::forward<Ts>(args)...);
	}
};
