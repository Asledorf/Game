#pragma once
#include <SDL_image.h>
namespace Engine
{
	struct Cars
	{
		//CAR RECTS

	//name						= {	x,	y,	w,	h	};
	//------------------------------------------------
	//limos
		SDL_Rect limo_black		= { 7,	16,	52,	135 };
		SDL_Rect limo_white		= { 7,	192,52,	135 };
		//cars
		SDL_Rect car_black		= { 67,	17,	47,	91	};
		SDL_Rect car_yellow		= { 65,	120,51,	100 };
		SDL_Rect car_pink		= { 127,120,51,	100 };
		SDL_Rect car_orange		= { 189,120,51,	100 };
		//trucks
		SDL_Rect truck_red		= { 247,20,	52,	92	};
		SDL_Rect truck_blue		= { 308,20,	52,	92	};
		SDL_Rect truck_yellow	= { 367,20,	52,	92	};
		SDL_Rect truck_white	= { 247,123,52,	92	};
		SDL_Rect truck_black	= { 308,123,52,	92	};
		SDL_Rect truck_grey		= { 367,123,52,	92	};
		//vans
		SDL_Rect van_teal		= { 64,	223,55,	106 };
		SDL_Rect van_blue		= { 124,223,55,	106 };
		SDL_Rect van_red		= { 186,223,55,	106 };
		SDL_Rect van_black		= { 248,223,55,	106 };
		SDL_Rect van_utility	= { 308,223,55,	106 };
		SDL_Rect van_silver		= { 366,223,55,	106 };
		//charger
		SDL_Rect charger_black	= { 10,	346,45,	86	};
		SDL_Rect charger_yellow	= { 65,	346,45,	86	};
		SDL_Rect charger_red	= { 122,346,45,	86	};
		SDL_Rect charger_white	= { 178,346,45,	86	};
		SDL_Rect charger_plain	= { 236,346,45,	86	};
		//racer
		SDL_Rect racer_white	= { 7,	446,51,	96	};
		SDL_Rect racer_red		= { 72,	446,51,	96	};
		SDL_Rect racer_blue		= { 137,446,51,	96	};
		SDL_Rect racer_black	= { 200,446,51,	96	};
		//special
		SDL_Rect police			= { 129,16,	49,	93	};
		SDL_Rect ambulance		= { 189,16,	50,	97	};
		SDL_Rect fire_truck		= { 426,21, 60, 137 };
	};
}