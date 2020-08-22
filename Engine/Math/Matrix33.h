#pragma once
#include"Vector2.h"

namespace Engine
{
	struct Matrix33
	{
		float m[3][3]; //col then row
		//[0][0] [1][0] [2][0]
		//[0][1] [1][1] [2][1]
		//[0][2] [1][2] [2][2]

		// SCALE
		void Scale(float s)
		{
			m[0][0] = s; m[1][0] = 0; m[2][0] = 0;
			m[0][1] = 0; m[1][1] = s; m[2][1] = 0;
			m[0][2] = 0; m[1][2] = 0; m[2][2] = 1;
		}
		void Scale(float x, float y)
		{
			m[0][0] = x; m[1][0] = 0; m[2][0] = 0;
			m[0][1] = 0; m[1][1] = y; m[2][1] = 0;
			m[0][2] = 0; m[1][2] = 0; m[2][2] = 1;

		}
		void Scale(const Vector2& v)
		{
			m[0][0] = v.x; m[1][0] =   0; m[2][0] = 0;
			m[0][1] =   0; m[1][1] = v.y; m[2][1] = 0;
			m[0][2] =   0; m[1][2] =   0; m[2][2] = 1;
		}

		//ROTATION
		void Rotate(float a)
		{
			m[0][0] =  std::cos(a);	m[1][0] = std::sin(a);	m[2][0] = 0;
			m[0][1] = -std::sin(a);	m[1][1] = std::cos(a);	m[2][1] = 0;
			m[0][2] = 0;			m[1][2] = 0;			m[2][2] = 1;
		}

		//TRANSLATE
		void Translate(const Vector2& v)
		{
			m[0][0] = 1;	m[1][0] = 0;	m[2][0] = 0;
			m[0][1] = 0;	m[1][1] = 1;	m[2][1] = 0;
			m[0][2] = v.x;	m[1][2] = v.y;	m[2][2] = 1;

		}

		//IDENTITY
		void SetIdentity()
		{
			m[0][0] = 1; m[1][0] = 0; m[2][0] = 0;
			m[0][1] = 0; m[1][1] = 1; m[2][1] = 0;
			m[0][2] = 0; m[1][2] = 0; m[2][2] = 1;
		}

		Matrix33 operator * (const Matrix33& mx)
		{
			Matrix33 result;

			result.m[0][0] = m[0][0] * mx.m[0][0] + m[1][0] * mx.m[0][1] + m[2][0] * mx.m[0][2];
			result.m[0][1] = m[0][1] * mx.m[0][0] + m[1][1] * mx.m[0][1] + m[2][1] * mx.m[0][2];
			result.m[0][2] = m[0][2] * mx.m[0][0] + m[1][2] * mx.m[0][1] + m[2][2] * mx.m[0][2];

			result.m[1][0] = m[0][0] * mx.m[1][0] + m[1][0] * mx.m[1][1] + m[2][0] * mx.m[1][2];
			result.m[1][1] = m[0][1] * mx.m[1][0] + m[1][1] * mx.m[1][1] + m[2][1] * mx.m[1][2];
			result.m[1][2] = m[0][2] * mx.m[1][0] + m[1][2] * mx.m[1][1] + m[2][2] * mx.m[1][2];

			result.m[2][0] = m[0][0] * mx.m[2][0] + m[1][0] * mx.m[2][1] + m[2][0] * mx.m[2][2];
			result.m[2][1] = m[0][1] * mx.m[2][0] + m[1][1] * mx.m[2][1] + m[2][1] * mx.m[2][2];
			result.m[2][2] = m[0][2] * mx.m[2][0] + m[1][2] * mx.m[2][1] + m[2][2] * mx.m[2][2];

			return result;
		}

		Vector2 operator* (const Vector2& v)
		{
			Vector2 result;

			result.x = v.x * m[0][0] + v.y * m[0][1] + m[0][2];
			result.y = v.x * m[1][0] + v.y * m[1][1] + m[1][2];

			return result;
		}
		friend Vector2 operator * (const Vector2& v, const Matrix33& mx)
		{
			Vector2 result;

			result.x = v.x * mx.m[0][0] + v.y * mx.m[0][1] + mx.m[0][2];
			result.y = v.x * mx.m[1][0] + v.y * mx.m[1][1] + mx.m[1][2];

			return result;
		}
	};


}