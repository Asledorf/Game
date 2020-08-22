#pragma once
#include "Objects/Object.h"

namespace Engine
{
	class Engine;
	class GameObject;

	class Scene : public Object
	{
	public:
		// Inherited via Object
		virtual void Create(void* data = nullptr) override;
		virtual void Destroy() override;

		void Read(const rapidjson::Value& value) override;

		void ReadGameObjects(const rapidjson::Value& value);

		void Update() override;
		void Draw();

		GameObject* Find(const std::string& name);

		void AddGameObj			(GameObject* gameObject);
		void RemoveGameObj		(GameObject* gameObject);
		void RemoveAllGameObj	();

	protected:
		Engine* engine{ nullptr };
		std::list<GameObject*> gameObjects;
	};
}