#pragma once

#include <SDL.h>

#include <math.h>
#include <windows.h>
#include <iostream>

namespace Engine
{
	struct Color
	{
		float r, g, b, a;

		//CTOR
		//default (solid black)
		Color() : r{ 0 }, g{ 0 }, b{ 0 }, a{ 1 } {}
		//Custom solid color
		Color(float r, float g, float b) : r{ r }, g{ g }, b{ b }, a{ 1 } {}
		//Custom with aplha
		Color(float r, float g, float b, float a) : r{ r }, g{ g }, b{ b }, a{ a } {}
		//Grayscale solid color
		Color(float f) : r{ f }, g{ f }, b{ f }, a{ 1 } {}
		//Grayscale with alpha
		Color(float f, float a) : r{ f }, g{ f }, b{ f }, a{ a } {}

		//FULL SETTERS (methods without alpha param keep current value)
		//default (solid black)
		void Set() { this->r = 0; this->g = 0; this->b = 0; this->a = 1; }
		//Custom solid color
		void Set(float r, float g, float b) { this->r = r; this->g = g; this->b = b;}
		//Custom with aplha
		void Set(float r, float g, float b, float a) { this->r = r; this->g = g; this->b = b; this->a = a; }
		//Grayscale solid color
		void Set(float f) { this->r = f; this->g = f; this->b = f; }
		//Grayscale with alpha
		void Set(float f, float a) { this->r = f; this->g = f; this->b = f; this->a = a; }

		//COMPONENT SETTERS
		void SetR(float r) { this->r = r; }
		void SetG(float g) { this->g = g; }
		void SetB(float b) { this->b = b; }
		void SetA(float a) { this->a = a; }


		//ACCESS operators
		float& operator [] (size_t index) { return (&r)[index % 3]; }
		const float& operator [] (size_t index) const { return (&r)[index % 3]; }

		//COLOR operators
		Color operator + (const Color& c) const { return { r + c.r, g + c.g, b + c.b }; }
		Color operator - (const Color& c) const { return { r - c.r, g - c.g, b - c.b }; }
		Color operator * (const Color& c) const { return { r * c.r, g * c.g, b * c.b }; }
		Color operator / (const Color& c) const { return { r / c.r, g / c.g, b / c.b }; }

		Color& operator += (const Color& c) { { r += c.r, g += c.g; b += c.b; return *this; } }
		Color& operator -= (const Color& c) { { r -= c.r, g -= c.g; b -= c.b; return *this; } }
		Color& operator *= (const Color& c) { { r *= c.r, g *= c.g; b *= c.b; return *this; } }
		Color& operator /= (const Color& c) { { r /= c.r, g /= c.g; b /= c.b; return *this; } }

		//FLOAT operators
		Color operator + (float s) const { return { r + s, g + s, b + s}; }
		Color operator - (float s) const { return { r - s, g - s, b - s}; }
		Color operator * (float s) const { return { r / s, g / s, b / s}; }
		Color operator / (float s) const { return { r * s, g * s, b * s}; }

		Color& operator += (float s) { { r += s, g += s, b += s; return *this; } }
		Color& operator -= (float s) { { r -= s, g -= s, b -= s; return *this; } }
		Color& operator *= (float s) { { r *= s, g *= s, b *= s; return *this; } }
		Color& operator /= (float s) { { r /= s, g /= s, b /= s; return *this; } }




		friend std::istream& operator >> (std::istream& s, Color& c);
		friend std::ostream& operator << (std::ostream& s, Color& v);

		//void corrector() { this->r = fmod(r, 255); this->g = fmod(g, 255); this->b = fmod(b, 255); }
		//{ return (0x00 << (int)(std::hex) << (static_cast<int>(r) << 16 | static_cast<int>(g) << 8 | static_cast<int>(b))); }

		SDL_Color pack8888() const; 
		operator SDL_Color() const { return pack8888(); }

	};

	inline SDL_Color Color::pack8888() const
	{
		SDL_Color color;

		color.r = static_cast<BYTE>(r * 255);
		color.g = static_cast<BYTE>(g * 255);
		color.b = static_cast<BYTE>(b * 255);
		color.a = static_cast<BYTE>(a * 255);

		return color;
	}
}
