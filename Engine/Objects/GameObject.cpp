#include "pch.h"
#include "GameObject.h"
#include "Components/Component.h"
#include "Components/RenderComponent.h"

namespace Engine
{
	void GameObject::Create(void* data)
	{
		engine = static_cast<Engine*>(data);
	}

	void GameObject::Destroy()
	{
		RemoveAllComponents();
	}

	void GameObject::Read(const rapidjson::Value& val)
	{
		json::Get(val, "name", name);

		json::Get(val, "position", transform.position );
		json::Get(val, "scale", transform.scale );
		json::Get(val, "angle", transform.angle );
	}

	void GameObject::Update()
	{
		for (Component* c : components)
		{
			c->Update();
		}
	}

	void GameObject::Draw()
	{
		for (Component* c : components)
		{
			RenderComponent* rc = GetComponent<RenderComponent>();
			if (rc) rc->Draw();
		}
	}

	void GameObject::AddComponent(Component* c)
	{
		components.push_back(c);
	}

	void GameObject::RemoveComponent(Component* c)
	{
		auto iter = std::find(components.begin(), components.end(), c);
		if (iter != components.end())
		{
			(*iter)->Destroy();
			delete (*iter);
			components.erase(iter);
		}
	}

	void GameObject::RemoveAllComponents()
	{
		for (Component* c : components)
		{
			c->Destroy();
			delete c;
		}
		components.clear();
	}
}
