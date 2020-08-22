#include "pch.h"
#include "Color.h"


namespace Engine
{

    std::istream& operator>>(std::istream& s, Color& c)
    {
		std::string line;
		std::getline(s, line);
		//{r,g,b}
		//std::cout << line << '\n';

		if (line.find("{") != std::string::npos)
		{
			//r in
			std::string cr = line.substr(line.find("{") + 1, line.find(",") - line.find("{") - 1);
			c.r = std::stof(cr);

			//shift line to target the G color component
			line = line.substr(line.find(",") + 1, line.find("}") - line.find(","));

			//g in
			std::string cg = line.substr(0,line.find(","));
			c.g = std::stof(cg);
			
			//b in
			std::string cb = line.substr(line.find(",") + 1, line.find("}") - line.find(",") - 1);
			c.b = std::stof(cb);

		}
        return s;
    }

	std::ostream& operator<<(std::ostream& s, Color& c)
	{
		s << "" << c.a << " " << c.r << " " << c.g << " " << c.b;
		return s;
	}
}
