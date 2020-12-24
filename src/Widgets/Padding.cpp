#include "Padding.hpp"

Padding::Padding() :
	top{0},
	right{0},
	bottom{0},
	left{0}
{
}

Padding::Padding(float padding) :
	top{padding},
	right{padding},
	bottom{padding},
	left{padding}
{
}

Padding::Padding(float vertical, float horizontal) :
	top{vertical},
	right{horizontal},
	bottom{vertical},
	left{horizontal}
{
}

Padding::Padding(float top, float right, float bottom, float left) :
	top{top},
	right{right},
	bottom{bottom},
	left{left}
{
}
