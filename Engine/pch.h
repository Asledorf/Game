// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here


#include "framework.h"
#include "Math/Math.h"

	//SDL libraries
#include <SDL.h>
#include <SDL_image.h>

	//data types
#include <string>

	//IO
#include <fstream>
#include <iostream>

	//containers
#include <vector>
#include <array>
#include <list>
#include <map>

	//time
#include <chrono>
	
	//asserts
#include <cassert>
#include "core/assert.h"

#endif //PCH_H