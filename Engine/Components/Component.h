#pragma once
#include "Objects/GameObject.h"


namespace Engine
{
	//class GameObject;

	class Component : public Object
	{
	public:
		virtual void Update() = 0;

		friend class GameObject;

	protected:
		class GameObject* owner{ nullptr };
	};


}
