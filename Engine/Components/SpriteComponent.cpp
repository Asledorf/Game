#include "pch.h"
#include "SpriteComponent.h"
#include "Objects/GameObject.h"
#include "Graphics/Texture.h"
#include "Graphics/Cars.h"

namespace Engine
{

	void Sprite::Create(void* data)
	{
		owner = static_cast<GameObject*>(data);

	}
	
	void Sprite::Destroy()
	{

	}

	void Sprite::Read(const rapidjson::Value& val)
	{
		json::Get(val,	"texture",	textureName);
		json::Get(val,	"origin",	origin);
		json::Get(val,	"rect",		rect);
	}
	
	void Sprite::Update()
	{

	}
	
	void Sprite::Draw()
	{
		Texture* texture = owner->engine->GetSystem<ResourceManager>()->Get<Texture>(textureName, owner->engine->GetSystem<Renderer>());
		texture->Draw(rect, owner->transform.position, owner->transform.angle, Vector2::one * owner->transform.scale, origin);
	}
}
