#include "Padding.hpp"

namespace ui
{
	Padding::Padding() :
		top(0),
		left(0),
		down(0),
		right(0)
	{
	}
	
	Padding::Padding(float padding) :
		top(padding),
		left(padding),
		down(padding),
		right(padding)
	{
	}
	
	Padding::Padding(float vertical, float horizontal) :
		top(vertical),
		left(horizontal),
		down(vertical),
		right(horizontal)
	{
	}
	
	Padding::Padding(float top, float left, float down, float right) :
		top(top),
		left(left),
		down(down),
		right(right)
	{
	}
}
