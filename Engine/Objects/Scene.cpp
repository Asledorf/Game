#include "pch.h"
#include "Scene.h"
#include "GameObject.h"
#include "Objectfactory.h"

namespace Engine
{
	void Scene::Create(void* data)
	{
		engine = static_cast<Engine*>(data);
	}

	void Scene::Destroy()
	{
		RemoveAllGameObj();
	}

	void Scene::Read(const rapidjson::Value& value)
	{
		const rapidjson::Value& objectValue = value["GameObject"];
		if (objectValue.IsObject())
		{
			std::string typeName;
			json::Get(value, "type", typeName);
			GameObject* gameObject = ObjectFactory::Instance().Create<GameObject>(typeName);

			if (gameObject)
			{
				gameObject->Create(engine);
				gameObject->Read(objectValue);
				AddGameObj(gameObject);
			}
		}
	}

	void Scene::Update()
	{
		for (auto gameObject : gameObjects)
		{
			gameObject->Update();
		}
	}

	void Scene::Draw()
	{
		for (auto gameObject : gameObjects)
		{
			gameObject->Draw();
		}
	}

	GameObject* Scene::Find(const std::string& name)
	{
		for (auto gameObject : gameObjects)
		{
			//! compare game object name to name parameter (==)
			if (gameObject->name == name)
			{
				return gameObject;
			}
		}

		return nullptr;
	}

	void Scene::AddGameObj(GameObject* gameObject)
	{
		gameObjects.push_back(gameObject);
	}

	void Scene::RemoveGameObj(GameObject* gameObject)
	{
		auto iter = std::find(gameObjects.begin(), gameObjects.end(), gameObject);
		if (iter != gameObjects.end())
		{
			(*iter)->Destroy();
			delete (*iter);
			gameObjects.erase(iter);
		}
	}

	void Scene::RemoveAllGameObj()
	{
		for (GameObject* c : gameObjects)
		{
			c->Destroy();
			delete c;
		}
		gameObjects.clear();
	}
}