#include "pch.h"
#include "Timer.h"

namespace Engine
{
//TIMER
	void Timer::Reset()
	{
		timePoint = { clock::now() };
	}
	
	Timer::clock::rep Timer::ElapsedTicks()
	{
		clock_duration duration = clock::now() - timePoint;

		return duration.count();
	}
	
	Timer::clock::rep Timer::TicksPerSecond()
	{
		return clock_duration::period::den;
	}
	double Timer::ElapsedSeconds()
	{
		return ElapsedTicks() / static_cast<double>(TicksPerSecond());
	}


//FRAME TIMER
	void FrameTimer::Tick()
	{
		dt = static_cast<float>(ElapsedSeconds());
		timePoint = clock::now();
	}
}
