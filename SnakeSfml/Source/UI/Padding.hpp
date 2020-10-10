#pragma once

namespace ui
{
	struct Padding
	{
		Padding();
		Padding(float padding);
		Padding(float vertical, float horizontal);
		Padding(float top, float left, float down, float right);

		float top;
		float left;
		float down;
		float right;
	};
}
