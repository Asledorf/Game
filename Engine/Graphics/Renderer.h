#pragma once
#include "Core/System.h"

namespace Engine
{
	class Renderer : public System
	{
	public:
		// Inherited via System
		virtual bool Startup() override;
		virtual void Shutdown() override;
		virtual void Update() override;

		bool Create(const std::string name, int w, int h);

		void BeginFrame();
		void EndFrame();

		friend class Texture;

	protected:

		SDL_Window*		window		{ nullptr };
		SDL_Renderer*	renderer	{ nullptr };

	};
}