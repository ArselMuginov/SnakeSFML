#include "Anchor.hpp"
#include <stdexcept>

const Anchor Anchor::TopLeft{0.0f, 0.0f};
const Anchor Anchor::Top{0.5f, 0.0f};
const Anchor Anchor::TopRight{1.0f, 0.0f};
const Anchor Anchor::Left{0.0f, 0.5f};
const Anchor Anchor::Center{0.5f, 0.5f};
const Anchor Anchor::Right{1.0f, 0.5f};
const Anchor Anchor::BottomLeft{0.0f, 1.0f};
const Anchor Anchor::Bottom{0.5f, 1.0f};
const Anchor Anchor::BottomRight{1.0f, 1.0f};

constexpr Anchor::Anchor(float x, float y) :
	m_x{x},
	m_y{y}
{
	if (x < 0 || x > 1 || y < 0 || y > 1)
	{
		throw std::out_of_range{"Anchor value(s) not in range"};
	}
}

constexpr float Anchor::x()
{
	return m_x;
}

constexpr float Anchor::y()
{
	return m_y;
}
