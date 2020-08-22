#pragma once
#include <map>
#include <functional>
namespace Engine
{
	template<typename T_Base, typename T_Key>

	class Factory
	{
	public:
		using func_t = std::function<T_Base* ()>; 


		template<typename T = T_Base>

		T* Create(T_Key key);
		void Register(T_Key key, func_t function);


	protected:
		std::map<T_Key, func_t> registry;
	};


	template<typename T_Base, typename T_Key>
	template<typename T>
	inline T* Factory<T_Base, T_Key>::Create(T_Key key)
	{
		T* object{ nullptr };
		auto iter = registry.find(key);
		if (iter != registry.end())
		{
			object = dynamic_cast<T*>(iter->second());
		}
		return object;
	}

	template<typename T_Base, typename T_Key>
	inline void Factory<T_Base, T_Key>::Register(T_Key key, func_t function)
	{
		registry[key] = function;
	}
}