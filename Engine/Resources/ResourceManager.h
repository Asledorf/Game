#pragma once
#include "core/System.h"
#include "Resource.h"
#include <map>

namespace Engine
{
	class ResourceManager : public System
	{
	public:
		// Inherited via System
		virtual bool Startup()	override;
		virtual void Shutdown()	override;
		virtual void Update()	override;

		template<typename T>
		T* Get(const std::string& name, void* data = nullptr);

		void RemoveAll();


	protected:
		std::map<std::string, Resource*> resources;
	};
	template<typename T>
	inline T* ResourceManager::Get(const std::string& name, void* data)
	{
		T* resource = dynamic_cast<T*>(resources[name]);
		if (!resource)
		{
			resource = new T;
			resource->Create(name, data);
			resources[name] = resource;
		}

		return resource;
	}
}