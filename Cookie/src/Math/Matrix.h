#pragma once

#include "../Core/Core.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Cookie::Math
{
	struct Matrix
	{
		float m00, m10, m20, m30;
		float m01, m11, m21, m31;
		float m02, m12, m22, m32;
		float m03, m13, m23, m33;

		Matrix()
		{
			setIdentity();
		}

		Matrix(
			float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33)
		{
			this->m00 = m00; this->m01 = m01; this->m02 = m02; this->m03 = m03;
			this->m10 = m10; this->m11 = m11; this->m12 = m12; this->m13 = m13;
			this->m20 = m20; this->m21 = m21; this->m22 = m22; this->m23 = m23;
			this->m30 = m30; this->m31 = m31; this->m32 = m32; this->m33 = m33;
		}

		~Matrix() = default;

		void invert()
		{

		}

		void setIdentity()
		{
			m00 = 1; m01 = 0; m02 = 0; m03 = 0;
			m10 = 0; m11 = 1; m12 = 0; m13 = 0;
			m20 = 0; m21 = 0; m22 = 1; m23 = 0;
			m30 = 0; m31 = 0; m32 = 0; m33 = 1;
		}
	};
}
