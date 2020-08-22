#include "pch.h"
#include "PlayerComponent.h"
#include "Components/PhysicsComponent.h"

namespace Engine
{
	void Player::Create(void* data)
	{
		owner = static_cast<GameObject*>(data);

	}
	
	void Player::Destroy()
	{
	}
	
	void Player::Update()
	{	
		//controller
		//STEERING
		if (owner->engine->GetSystem<InputSystem>()->GetButtonState(SDL_SCANCODE_LEFT) == InputSystem::eButtonState::HELD || owner->engine->GetSystem<InputSystem>()->GetButtonState(SDL_SCANCODE_A) == InputSystem::eButtonState::HELD)
		{
			owner->transform.angle -= 200.0f * owner->engine->GetTimer().DT();
		}
		if (owner->engine->GetSystem<InputSystem>()->GetButtonState(SDL_SCANCODE_RIGHT) == InputSystem::eButtonState::HELD || owner->engine->GetSystem<InputSystem>()->GetButtonState(SDL_SCANCODE_D) == InputSystem::eButtonState::HELD)
		{
			owner->transform.angle += 200.0f * owner->engine->GetTimer().DT();
		}
		//FORWARD MOTION
		Vector2 force{ 0,0 };
		if (owner->engine->GetSystem<InputSystem>()->GetButtonState(SDL_SCANCODE_W) == InputSystem::eButtonState::HELD)
		{
			force = Vector2::forward * 1000.0f * owner->engine->GetTimer().DT();
		}
		if (owner->engine->GetSystem<InputSystem>()->GetButtonState(SDL_SCANCODE_SPACE) == InputSystem::eButtonState::PRESSED)
		{
			force = Vector2::forward * 10000.0f * owner->engine->GetTimer().DT();
		}
		force = Vector2::rotate(force, Math::deg_to_rad(owner->transform.angle));

		Physics* phys = owner->GetComponent<Physics>();
		if (phys)
		{
			phys->SetForce(force);
		}
		owner->GetComponent<Physics>()->SetForce(force);


	}
}

