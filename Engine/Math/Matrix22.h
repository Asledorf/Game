#pragma once
#include"Vector2.h"

namespace Engine
{
	struct Matrix22
	{
		float m[2][2]; //col then row
		//[0][0] [1][0]
		//[0][1] [1][1]

		Matrix22() = default;
		//Matrix22() {};
		Matrix22(const Vector2& col1, const Vector2& col2)
		{
			m[0][0] = col1[0]; m[1][0] = col2[0];
			m[0][1] = col1[1]; m[1][1] = col2[1];
		}


		// SCALE
		void Scale(float s)
		{
			m[0][0] = s; m[1][0] = 0;
			m[0][1] = 0; m[1][1] = s;
		}
		void Scale(float x, float y)
		{
			m[0][0] = x; m[1][0] = 0;
			m[0][1] = 0; m[1][1] = y;
		}
		void Scale(const Vector2& v) 
		{
			m[0][0] = v.x; m[1][0] = 0;
			m[0][1] = 0; m[1][1] = v.y;
		}

		//ROTATION
		void Rotate(float a)
		{
			m[0][0] = std::cos(a); m[1][0] = std::sin(a);
			m[0][1] = -std::sin(a); m[1][1] = std::cos(a);
		}

		//IDENTITY
		void SetIdentity()
		{
			m[0][0] = 1; m[1][0] = 0;
			m[0][1] = 0; m[1][1] = 1;
		}

		Matrix22 operator * (const Matrix22& mx)
		{
			Matrix22 result;

			result.m[0][0] = m[0][0] * mx.m[0][0] + m[1][0] * mx.m[0][1];
			result.m[1][0] = m[0][0] * mx.m[1][0] + m[1][0] * mx.m[1][1];
			result.m[0][1] = m[0][1] * mx.m[0][0] + m[1][1] * mx.m[0][1];
			result.m[1][1] = m[0][1] * mx.m[1][0] + m[1][1] * mx.m[1][1];

			return result;

		}

		Vector2 operator* (const Vector2& v)
		{
			Vector2 result;

			result.x = v.x * m[0][0] + v.y * m[0][1];
			result.y = v.x * m[1][0] + v.y * m[1][1];

			return result;
		}		
		friend Vector2 operator * (const Vector2& v, const Matrix22& mx)
		{
			Vector2 result;

			result.x = v.x * mx.m[0][0] + v.y * mx.m[0][1];
			result.y = v.x * mx.m[1][0] + v.y * mx.m[1][1];

			return result;
		}
	};


}