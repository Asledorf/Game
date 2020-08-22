#pragma once
#include<random>

namespace Engine 
{
		inline float random() 
		{
			return rand() / static_cast<float>( RAND_MAX);
		}

		inline float random(float min, float max)
		{
			if (min > max)
			{
				std::swap(min,max);
			}
			return min + (max - min) * random();
		}		
		
		inline float random(float max)
		{
			return max * random();
		}
}