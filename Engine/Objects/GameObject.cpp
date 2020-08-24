#include "pch.h"
#include "GameObject.h"
#include "Objectfactory.h"
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

	void GameObject::Read(const rapidjson::Value& value)
	{
		//TEST
		//ASSERT(value.IsObject());

		json::Get(value, "name", name);

		json::Get(value, "position", transform.position);
		json::Get(value, "scale", transform.scale);
		json::Get(value, "angle", transform.angle);

		const rapidjson::Value& componentsValue = value["Components"];
		if (componentsValue.IsArray())
		{
			ReadComponents(componentsValue);
		}
	}


	void GameObject::ReadComponents(const rapidjson::Value& value)
	{
		for (rapidjson::SizeType i = 0; i < value.Size(); i++)
		{
			//TEST
			//ASSERT(value.IsObject());

			const rapidjson::Value& componentValue = value[i];
			if (componentValue.IsObject())
			{
				std::string typeName;
				json::Get(componentValue, "type", typeName);

				Component* component = ObjectFactory::Instance().Create<Component>(typeName);
				if (component)
				{
					component->Create(this);
					component->Read(componentValue);
					components.push_back(component);
				}
			}
		}
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
