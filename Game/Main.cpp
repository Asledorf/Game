#include "pch.h"
#include "Engine.h"
#include "Objects/GameObject.h"
#include "Graphics/Texture.h"
#include "Components/PlayerComponent.h"
#include "Core/Factory.h"
#include "Objects/Objectfactory.h"
#include "Objects/Scene.h"

Engine::Engine engine;
Engine::Scene scene;

int main(int, char**)
{
	Engine::Timer timer;
	engine.Startup();

	Engine::ObjectFactory::Instance().Initialize();
	Engine::ObjectFactory::Instance().Register("Player", Engine::Object::Instantiate<Engine::Player>);

	scene.Create(&engine);
	rapidjson::Document document;
	Engine::json::Load("scene.txt", document);
	//at this point document is an object
	scene.Read(document);

	/// SETUP
	std::cout << timer.ElapsedTicks() << '\n';
	std::cout << timer.ElapsedSeconds();

	SDL_Event event;
	bool quit = false;
	while (!quit)
	{
		/// QUIT EVENT
		if (engine.GetSystem<Engine::InputSystem>()->GetButtonState(SDL_SCANCODE_ESCAPE) == Engine::InputSystem::eButtonState::PRESSED) quit = true;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		default:
			break;
		}

		/// UPDATE
		engine.Update();
		scene.Update();

		/// DRAW
		engine.GetSystem<Engine::Renderer>()->BeginFrame();	// begin draw frame

		scene.Draw();

		engine.GetSystem<Engine::Renderer>()->EndFrame();	// end draw frame
	}
	scene.Destroy();
	engine.Shutdown();
	return 0;
}
