#pragma once
#include "pch.h"
#include "Vector2.h"
#include "Color.h"
#include "Transform.h"
#include "Random.h"

namespace Engine
{
	namespace Math
	{
		
		const static float HALF_PI = 3.14159265358979323846264338327950288419f * 0.5f;
		const static float PI = 3.14159265358979323846264338327950288419f;
		const static float TAU = PI * 2;

		const static float RAD_TO_DEG = 180.0f / PI;
		const static float DEG_TO_RAD = PI / 180.0f; 

		inline float rad_to_deg(const float rad)
		{
			return rad * 180 / PI;
		}

		inline float deg_to_rad(const float deg)
		{
			return deg * PI / 180.0f;
		}

		template<typename T>
		inline float Clamp(T p, T min, T max)
		{
			if (p < min) { p = min; }
			if (p > max) { p = max; }
			return p;
		}

		template<typename T>
		inline Vector2 Clamp/*<Vector2>*/(Vector2 v, Vector2 min, Vector2 max)
		{
			v.x = Clamp(v.x, min.x, max.x);
			v.y = Clamp(v.y, min.y, max.y);
			return v;
		}

		template<typename T>
		inline T Lerp(T a, T b, float f)
		{
			f = Clamp(f, 0.0f, 1.0f);
			return (a + ((b - a) * f));
		}
	}
}