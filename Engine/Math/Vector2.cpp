#include "pch.h"
#include "Vector2.h"
#include <string>



namespace Engine
{
	Vector2 const Vector2::left		= Vector2{ -1,0 };
	Vector2 const Vector2::right	= Vector2{ 1,0 };
	Vector2 const Vector2::up		= Vector2{ 0,-1 };
	Vector2 const Vector2::down		= Vector2{ 0,1 };
	Vector2 const Vector2::forward	= Vector2{ 0,-1 };
	Vector2 const Vector2::one		= Vector2{ 1,1 };
	Vector2 const Vector2::zero		= Vector2{ 0,0 };

	std::ostream& operator << (std::ostream& s, Vector2& v)
	{
		s << "{ " << v.x << " , " << v.y << " }" ;
		return s;
	}

	std::istream& operator>>(std::istream& s, Vector2& v)
	{
		// TODO: insert return statement here
		std::string line; 
		std::getline(s, line);
		std::cout << line << '\n';

		if (line.find("{") != std::string::npos)
		{
			//x in
			std::string vx = line.substr(line.find("{") + 1 , line.find(",") - line.find("{") - 1 );
			v.x = std::stof(vx);

			//y in
			std::string vy = line.substr(line.find(",") + 1 , line.find("}") - line.find(",") - 1 );
			v.y = std::stof(vy);
			

		}
		return s;
	}
}