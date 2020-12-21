#pragma once
#include <SFML/System/Vector2.hpp>

namespace sf
{
	template <typename T>
	Vector2<T> operator *(const Vector2<T>& left, const Vector2<T>& right)
	{
		return Vector2<T>(left.x * right.x, left.y * right.y);
	}

	template <typename T>
	Vector2<T>& operator *=(Vector2<T>& left, const Vector2<T>& right)
	{
		left.x *= right.x;
		left.y *= right.y;

		return left;
	}
}
