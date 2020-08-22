#pragma once
#include "Component.h"
namespace Engine
{
	class RenderComponent : public Component
	{
	public:
		virtual void Draw() = 0;
	private:

	};
}
