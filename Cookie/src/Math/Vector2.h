#pragma once

#include "pch.h"

namespace Cookie::Math
{
	struct Vector2
	{
		float x;
		float y;

		Vector2()
		{
			x = 0;
			y = 0;
		}

		Vector2(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

		Vector2(int x, int y)
		{
			this->x = static_cast<float>(x);
			this->y = static_cast<float>(y);
		}

		Vector2(U32 x, U32 y)
		{
			this->x = static_cast<float>(x);
			this->y = static_cast<float>(y);
		}

		~Vector2() = default;

		Vector2 operator+(const Vector2& b) const
		{
			return Vector2
			(
				this->x + b.x,
				this->y + b.y
			);
		}

		Vector2 operator*(const Vector2& b) const
		{
			return Vector2(x * b.x, y * b.y);
		}

		Vector2 operator-(const Vector2& b) const
		{
			return Vector2(x - b.x, y - b.y);
		}

		Vector2 operator/(const Vector2& b)
		{
			return Vector2(x / b.x, y / b.y);
		}

		float Length() const
		{
			return sqrt(x * x + y * y);
		}

		static inline float Distance(const Vector2& a, const Vector2& b)
		{
			return (b - a).Length();
		}
	};
}
