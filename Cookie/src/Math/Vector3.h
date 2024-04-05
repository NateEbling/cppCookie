#pragma once

#include "../Core/Core.h"

namespace Cookie::Math
{
	struct Vector3
	{
		float x;
		float y;
		float z;

		Vector3()
		{
			x = 0;
			y = 0;
			z = 0;
		}

		Vector3(const Vector3& vector) = default;

		Vector3(const float x, const float y, const float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Vector3(const int x, const int y, const int z)
		{
			this->x = static_cast<float>(x);
			this->y = static_cast<float>(y);
			this->z = static_cast<float>(z);
		}

		Vector3(const U32 x, const U32 y, const U32 z)
		{
			this->x = static_cast<float>(x);
			this->y = static_cast<float>(y);
			this->z = static_cast<float>(z);
		}

		~Vector3() = default;

		Vector3 operator+(const Vector3& b) const
		{
			return Vector3
			(
				this->x + b.x,
				this->y + b.y,
				this->z + b.z
			);
		}

		Vector3 operator*(const Vector3& b) const
		{
			return Vector3(x * b.x, y * b.y, z * b.z);
		}

		Vector3 operator-(const Vector3& b) const
		{
			return Vector3(x - b.x, y - b.y, z - b.z);
		}

		Vector3 operator/(const Vector3& b) const
		{
			return Vector3(x / b.x, y / b.y, z / b.z);
		}

		float length() const
		{
			return sqrt(x * x + y * y + z * z);
		}

		void normalize()
		{
			x = x / length();
			y = y / length();
			z = z / length();
		}
	};
}
