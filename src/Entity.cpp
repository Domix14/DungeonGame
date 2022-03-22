#include "Entity.h"

Entity::Entity(Engine* inEngine) :
	engine(inEngine),
	position({0, 0}),
	bDestroyed(false)
{

}

bool Entity::IsDestroyed() const
{
	return bDestroyed;
}

void Entity::Destroy()
{
	bDestroyed = true;
}

Vector2 Entity::GetPosition()
{
	return position;
}

void Entity::SetPosition(Vector2 newPosition)
{
	position = newPosition;
}

const Engine* Entity::GetEngine() const
{
	return engine;
}
