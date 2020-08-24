#include "pch.h"
#include "Scene.h"
#include "GameObject.h"
#include "Objectfactory.h"
#include <string>

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
		const rapidjson::Value& objectsValue = value["GameObjects"];
		//std::cout << objectsValue.GetString();
		if (objectsValue.IsArray())
		{
			ReadGameObjects(objectsValue);
		}

		//const rapidjson::Value& objectValue = value["GameObject"];
		//if (objectValue.IsObject())
		//{
		//	//TEST
		//	ASSERT(value.IsObject());

		//	std::string typeName;
		//	//json::Get(value, "type", typeName);
		//	json::Get(objectValue, "type", typeName);

		//	//json::Get(value, value["GameObject"]["type"].GetString(), typeName);
		//	GameObject* gameObject = ObjectFactory::Instance().Create<GameObject>(typeName);// create from object factory, use typeName as the key
		//	ASSERT(gameObject);
		//		if (gameObject)
		//		{
		//			gameObject->Create(engine);
		//			// call game object read (pass in objectValue)
		//			gameObject->Read(objectValue);
		//			// call AddGameObject passing in the game object
		//			AddGameObj(gameObject);
		//		}
		//}
	}

	void Scene::ReadGameObjects(const rapidjson::Value& value)
	{
		for (rapidjson::SizeType i = 0; i < value.Size(); i++)
		{
			const rapidjson::Value& objectValue = value[i];
			ASSERT(objectValue.IsObject());
			if (objectValue.IsObject())
			{
				std::string typeName;
				json::Get(objectValue, "type", typeName);
				//json::Get(value, "type", typeName);
				//json::Get(value, value["GameObject"]["type"].GetString(), typeName);
				GameObject* gameObject = ObjectFactory::Instance().Create<GameObject>(typeName);
				if (gameObject)
				{
					gameObject->Create(engine);
					gameObject->Read(objectValue);
					AddGameObj(gameObject);
				}
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