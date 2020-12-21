#include "Anchor.hpp"
#include <utility>

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
	checkRange();
}

constexpr float Anchor::x()
{
	return m_x;
}

constexpr float Anchor::y()
{
	return m_y;
}

Anchor& Anchor::operator=(Anchor other) noexcept
{
	std::swap(m_x, other.m_x);
	std::swap(m_y, other.m_y);
	checkRange();
	return *this;
}

constexpr void Anchor::checkRange()
{
	if (m_x < 0 || m_x > 1 || m_y < 0 || m_y > 1)
	{
		throw "Anchor values not in range";
	}
}
