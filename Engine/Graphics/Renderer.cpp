#include "pch.h"
#include "Renderer.h"


namespace Engine
{
	
	bool Renderer::Startup()
	{
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
			return false;
		}

		IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);


	    return true;
	}
	
	void Renderer::Shutdown()
	{
	
	}
	
	void Renderer::Update()
	{
	}
	bool Renderer::Create(const std::string name, int w, int h)
	{
		this->window = SDL_CreateWindow(name.c_str(), 100, 100, w, h, SDL_WINDOW_SHOWN /*| SDL_WINDOW_BORDERLESS*/);
		if (this->window == nullptr)
		{
			std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
			return false;
		}

		this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (this->renderer == nullptr)
		{
			std::cout << "SDL_CreateRenderer Error (renderer.cpp): " << SDL_GetError() << std::endl;
			return false;
		}


		return true;
	}
	void Renderer::BeginFrame()
	{
		SDL_RenderClear(renderer);
	}	
	void Renderer::EndFrame()
	{
		SDL_RenderPresent(renderer);
	}
}
