#pragma once

#include "../Core/Core.h"

namespace Cookie::Math
{
	struct Vector4
	{
		float x;
		float y;
		float z;
		float w;

		Vector4()
		{
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		}

		~Vector4() = default;

		Vector4(const float x, const float y, const float z, const float w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		Vector4(const int x, const int y, const int z, const int w)
		{
			this->x = static_cast<float>(x);
			this->y = static_cast<float>(y);
			this->z = static_cast<float>(z);
			this->w = static_cast<float>(w);
		}

		Vector4(const U32 x, const U32 y, const U32 z, const U32 w)
		{
			this->x = static_cast<float>(x);
			this->y = static_cast<float>(y);
			this->z = static_cast<float>(z);
			this->w = static_cast<float>(w);
		}

		Vector4 operator+(const Vector4& b) const
		{
			return Vector4
			(
				this->x + b.x,
				this->y + b.y,
				this->z + b.z,
				this->w + b.w
			);
		}

		Vector4 operator*(const Vector4& b) const
		{
			return Vector4(x * b.x, y * b.y, z * b.z, w * b.w);
		}

		Vector4 operator-(const Vector4& b) const
		{
			return Vector4(x - b.x, y - b.y, z - b.z, w - b.w);
		}

		Vector4 operator/(const Vector4& b) const
		{
			return Vector4(x / b.x, y / b.y, z / b.z, w / b.w);
		}

		float length() const
		{
			return sqrt(x * x + y * y + z * z + w * w);
		}

		void normalize()
		{
			float L = length();
			
			x = x / L;
			y = y / L;
			z = z / L;
			w = w / L;
		}
	};
}
