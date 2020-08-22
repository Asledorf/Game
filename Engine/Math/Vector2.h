#pragma once
#include<cmath>
#include<iostream>

namespace Engine
{
	struct Vector2
	{


		float x, y;

		Vector2() : x{ 0 }, y{ 0 } {}
		Vector2(float x, float y) : x{ x }, y{ y } {}
		Vector2(int x, int y) : x{static_cast<float>( x )}, y{ static_cast<float>( y )} {}

		float& operator [] (size_t i) { return (&x)[i%2]; } 
		const float& operator [] (size_t i) const { return (&x)[i%2]; } 

		void set(float x, float y) { this->x = x; this->y = y; }

		Vector2 operator + (const Vector2& v) const { return { x + v.x, y + v.y }; }
		Vector2 operator - (const Vector2& v) const { return { x - v.x, y - v.y }; }			
		Vector2 operator / (const Vector2& v) const { return { x / v.x, y / v.y }; }
		Vector2 operator * (const Vector2& v) const { return { x * v.x, y * v.y }; }
		Vector2& operator += (const Vector2& v) {{ x += v.x, y += v.y; return *this; } }
		Vector2& operator -= (const Vector2& v) {{ x -= v.x, y -= v.y; return *this; } }
		Vector2& operator *= (const Vector2& v) {{ x *= v.x, y *= v.y; return *this; } }
		Vector2& operator /= (const Vector2& v) {{ x /= v.x, y /= v.y; return *this; } }

		Vector2 operator + (float s) const { return { x + s, y + s }; }
		Vector2 operator - (float s) const { return { x - s, y - s }; }
		Vector2 operator / (float s) const { return { x / s, y / s }; }
		Vector2 operator * (float s) const { return { x * s, y * s }; }
		Vector2& operator += (float v) { { x += v, y += v; return *this; } }
		Vector2& operator -= (float v) { { x -= v, y -= v; return *this; } }
		Vector2& operator *= (float v) { { x *= v, y *= v; return *this; } }
		Vector2& operator /= (float v) { { x /= v, y /= v; return *this; } }

		Vector2 operator - () { return Vector2{ -x,-y }; }

		friend std::istream& operator >> (std::istream& s ,Vector2& v);
		friend std::ostream& operator << (std::ostream& s, Vector2& v);


		float length() const;
		float lengthSqr() const;

		Vector2 NORMALIZED() const;
		void normalize();

		static float distance(const Vector2& v1, const Vector2& v2);
		static Vector2 rotate(const Vector2& v, float rad);
		
		static const Vector2 left;
		static const Vector2 right;
		static const Vector2 up;
		static const Vector2 down;
		static const Vector2 forward;
		static const Vector2 one;
		static const Vector2 zero;
		static const Vector2 half;
	};

	inline float Vector2::length() const
	{
		return std::sqrt((x * x) + (y * y));
	}
	inline float Vector2::lengthSqr() const
	{
		return (x * x) + (y * y);
	}
	inline Vector2 Vector2::NORMALIZED() const 
	{
		float len = length();
		return (len == 0.0f) ? Vector2{.0f,.0f} : (*this / length());
	}
	inline void Vector2::normalize()
	{
		float len = length();
		if (len == .0f)
		{
			x = y = 0.0f;
		}
		else
		{
			*this /= len;
		}
	}

	inline float Vector2::distance(const Vector2& v1, const Vector2& v2) 
	{
		Vector2 v = v1 - v2;
		return v.length();
	}

	inline Vector2 Vector2::rotate(const Vector2& v, float rad)
	{
		float x = v.x * std::cos(rad) - v.y * std::sin(rad);
		float y = v.x * std::sin(rad) + v.y * std::cos(rad);

		return {x,y};
	}
}