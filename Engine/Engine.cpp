#include "pch.h"
#include "Engine.h"

bool Engine::Engine::Startup()
{
    //create systems
    systems.push_back(new Renderer);
    systems.push_back(new InputSystem);
    systems.push_back(new ResourceManager);
    //start up systems
    for (auto sys : systems)
    {
        sys->Startup();
    }
    //create window 
    GetSystem<Renderer>()->Create("GAME",840,650);


    return true;
}

void Engine::Engine::Shutdown()
{
    for (auto sys : systems)
    {
        sys->Shutdown();
        delete sys;
    }
    systems.clear();

    IMG_Quit();
    SDL_Quit();
}

void Engine::Engine::Update()
{
    frameTimer.Tick();

    for (auto sys : systems)
    {
        sys->Update();
    }
}
