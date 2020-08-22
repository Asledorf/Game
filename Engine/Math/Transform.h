#pragma once
#include "Vector2.h"

namespace Engine
{

	struct Transform
	{
		Vector2 position;
		float scale;
		float angle;

		Transform() : position{0,0}, scale{0}, angle{0} {}
		Transform(Vector2& p, float s = 1 , float a = 0) : position{p}, scale{s}, angle{a} {}

		//bool Load(const std::string& filename);

		friend std::istream& operator >> (std::istream& stream, Transform& tf);
	};
}