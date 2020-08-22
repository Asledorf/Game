#pragma once
#include "Object.h"
#include "Math/Transform.h"
#include "Engine.h"

namespace Engine
{
	class Component;

	class GameObject : public Object
	{
	public:
		// Inherited via Object
		virtual void Create(void* data = nullptr) override;
		virtual void Destroy() override;

		void Read(const rapidjson::Value& val) override;

		void Update();
		void Draw();

		template<typename T>
		T* GetComponent();

		void AddComponent(Component* c);
		void RemoveComponent(Component* c);
		void RemoveAllComponents();

		Transform transform;
		Engine* engine;
		std::string name;

	protected:
		std::vector<Component*> components;
	};

	template<typename T>
	T* GameObject::GetComponent()
	{
		T* t = { nullptr };
		for (auto c : components)
		{
			t = dynamic_cast<T*>(c);
			if (t) break;
		}
		return t;
	}
}