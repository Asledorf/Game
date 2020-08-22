#include "pch.h"

void Assert
(
	//params
	bool condition, 
	const std::string& conditionString, 
	const std::string& fileName, 
	int line, 
	const std::string& funcName, 
	const std::string message
)
{
	if (!condition)
	{
		std::cout << "Assertion failed: " << conditionString << '\n';
		if (!message.empty())
		{
			std::cout << message << '\n';
		}
		std::cout << "File: " << fileName << '\n';
		std::cout << "Fnunction: " << funcName << '\n';
		std::cout << "Line: " << line << '\n\n';

		abort();
	}
}
