#pragma once
#include "Component.h"
#include "Math/Vector2.h"

namespace Engine
{
	class Physics : public Component
	{
	public:
		virtual void Create(void* data = nullptr) override;
		virtual void Destroy() override;

		virtual void Update() override;

		void SetForce(const Vector2& force) { this->force = force; }

	protected:
		Vector2 velocity;
		Vector2 force;
		float drag{ 1 };
		float mass{ 1 };
		float density{ 1 };
	};
}
