#include "pch.h"
#include "Engine.h"
#include "Objects/GameObject.h"
#include "Graphics/Texture.h"

#include "Components/PlayerComponent.h"
#include "Core/Factory.h"
#include "Objects/Objectfactory.h"

Engine::Engine engine;


const int WIDTH = 840;
const int HEIGHT = 650;
const std::string NAME = "CAR GAME";

int main(int, char**)
{
	Engine::ObjectFactory::Instance().Initialize();

	//startup
	Engine::Timer timer;
	engine.Startup();

	/// PLAYER CREATION

	//create player and link it to engine
	Engine::GameObject* player = Engine::ObjectFactory::Instance().Create<Engine::GameObject>("GameObject");
	player->Create(&engine);

	//read in player
	rapidjson::Document doc;
	Engine::json::Load("player.txt", doc);
	player->Read(doc);

	//create blank component
	Engine::Component* component;

	//register components
	Engine::ObjectFactory::Instance().Register("Player", Engine::Object::Instantiate<Engine::Player>);

	//create & add components
	component = Engine::ObjectFactory::Instance().Create<Engine::Component>("Physics");
	component->Create(player);
	player->AddComponent(component);

	component = Engine::ObjectFactory::Instance().Create<Engine::Component>("Sprite");
	component->Create(player);
	player->AddComponent(component);
	Engine::json::Load("sprite.txt", doc);
	component->Read(doc);

	component = Engine::ObjectFactory::Instance().Create<Engine::Component>("Player");
	component->Create(player);
	player->AddComponent(component);

	/// SETUP
	std::cout << timer.ElapsedTicks() << '\n';
	std::cout << timer.ElapsedSeconds();


	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

	Engine::Texture* background = engine.GetSystem<Engine::ResourceManager>()->Get<Engine::Texture>("background.png", engine.GetSystem<Engine::Renderer>());
	Engine::Vector2 velocity{ 0,0 };

	SDL_Event event;
	bool quit = false;
	while (!quit)
	{
		if (engine.GetSystem<Engine::InputSystem>()->GetButtonState(SDL_SCANCODE_ESCAPE) == Engine::InputSystem::eButtonState::PRESSED) quit = true;

		/// UPDATE
		engine.Update();
		player->Update();

		/// DRAW
		engine.GetSystem<Engine::Renderer>()->BeginFrame();	// begin draw frame

		background->Draw({ 0,0 });
		player->Draw();

		engine.GetSystem<Engine::Renderer>()->EndFrame();	// end draw frame

		/// QUIT EVENT
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		default:
			break;
		}
	}
	engine.Shutdown();
	return 0;
}
