#pragma once
#include "pch.h"

#include "Graphics/Renderer.h"
#include "Resources/ResourceManager.h"
#include "Input/InputSystem.h"
#include "Core/Timer.h"
#include "Core/Json.h"

#include <vector>

namespace Engine
{

	class System;

	class Engine
	{
	public:
		bool Startup();
		void Shutdown();

		void Update();
		
		template<typename T>
		T* GetSystem();

		FrameTimer& GetTimer() { return frameTimer; }
	protected:
		std::vector<System*> systems;
		FrameTimer frameTimer;

	};


	template<typename T>
	T* Engine::GetSystem()
	{
		T* t = { nullptr };
		for (auto c : systems)
		{
			t = dynamic_cast<T*>(c);
			if (t != nullptr) { break; }
		}
		return t;
	}
}