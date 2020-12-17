#pragma once

struct Padding
{
	Padding();
	Padding(float padding);
	Padding(float vertical, float horizontal);
	Padding(float top, float right, float bottom, float left);

	float top;
	float right;
	float bottom;
	float left;
};
