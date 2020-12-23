#pragma once
#include "Widgets/Layout.hpp"

class VBox : public Layout
{
public:
	using Layout::Layout;
	virtual void updateLayout();

	template <class... Ts>
	static std::unique_ptr<VBox> create(Ts&&... args)
	{
		return std::make_unique<VBox>(std::forward<Ts>(args)...);
	}
};
