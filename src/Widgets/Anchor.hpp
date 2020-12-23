#pragma once

class Anchor
{
public:
	constexpr Anchor(float x, float y);
	constexpr float x();
	constexpr float y();

	static const Anchor TopLeft;
	static const Anchor Top;
	static const Anchor TopRight;
	static const Anchor Left;
	static const Anchor Center;
	static const Anchor Right;
	static const Anchor BottomLeft;
	static const Anchor Bottom;
	static const Anchor BottomRight;

private:
	float m_x;
	float m_y;
};
