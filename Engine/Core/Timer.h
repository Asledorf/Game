#pragma once
#include <chrono>

namespace Engine
{
	class Timer
	{
	public:
		using clock = std::chrono::high_resolution_clock;
		using clock_duration = std::chrono::duration<clock::rep, std::nano>;

		Timer() : timePoint{ clock::now() } {}

		void Reset();
		clock::rep ElapsedTicks();
		clock::rep TicksPerSecond();

		double ElapsedSeconds();

	protected:
		clock::time_point timePoint;

	};

	class FrameTimer : public Timer
	{
	public:
		void Tick();

		float DT() { return dt; }

	protected:
		float dt;
	private:

	};
}
