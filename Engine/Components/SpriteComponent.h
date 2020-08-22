#pragma once
#include "RenderComponent.h"

namespace Engine
{
	class Sprite : public RenderComponent
	{
	public:
		virtual void Create(void* data = nullptr) override;
		virtual void Destroy() override;

		void Read(const rapidjson::Value& val);

		virtual void Update() override;
		virtual void Draw() override;

	protected:
		std::string textureName;
		SDL_Rect rect{ 0,0,0,0 };


		//class Texture* texture;
	};
}