#include "pch.h"
#include "Objectfactory.h"
#include "Components/PhysicsComponent.h"
#include "Components/SpriteComponent.h"
namespace Engine
{
	void ObjectFactoryImpl::Initialize()
	{
		ObjectFactory::Instance().Register("GameObject",Object::Instantiate<GameObject>);
		ObjectFactory::Instance().Register("Physics",	Object::Instantiate<Physics>);
		ObjectFactory::Instance().Register("Sprite",	Object::Instantiate<Sprite>);
	}
}