#pragma once
#include "Components/Component.h"

namespace Engine
{
	class Player : public Component
	{
	public:


	private:


		// Inherited via Component
		virtual void Create(void* data = nullptr) override;

		virtual void Destroy() override;

		virtual void Update() override;

	};
}