#include "pch.h"
#include "PhysicsComponent.h"
#include "Objects/GameObject.h"


namespace Engine
{
	void Physics::Create(void* data)
	{
		owner = static_cast<GameObject*>(data);

		drag = .95f;
	}

	void Physics::Destroy()
	{

	}

	void Physics::Update()
	{
		velocity += force * owner->engine->GetTimer().DT();
		velocity *= drag;
		owner->transform.position += velocity;// *owner->engine->GetTimer().DT();
	}
}