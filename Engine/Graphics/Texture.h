#pragma once
#include "Math/Vector2.h"
#include "Resources/Resource.h"
#include <SDL.h>
#include <string>

namespace Engine
{
	class Texture : public Resource
	{
	public:
		
		bool Create(const std::string&, void*) override;
		void Destroy() override;

		void Draw(const Vector2& position,	const Vector2& scale = { 1, 1 }, float angle = 0);
		void Draw(const SDL_Rect& source ,	const Vector2& position, const Vector2& scale = { 1, 1 }, float angle = 0);

		Vector2 GetSize() const;

	protected:
		SDL_Texture*	texture		{ nullptr };
		SDL_Renderer*	renderer	{ nullptr };
	};
}
