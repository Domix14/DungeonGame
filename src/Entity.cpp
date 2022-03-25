#include "Entity.h"

Entity::Entity(Engine* inEngine) :
	engine(inEngine),
	position({0, 0}),
	bDestroyed(false),
	collisionType(CollisionType::NoCollision),
	scale(3)
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

void Entity::Move(Vector2 dPos)
{
	position.x += dPos.x;
	position.y += dPos.y;
}

void Entity::SetVelocity(Vector2 newVelocity)
{
	velocity = newVelocity;
}

Vector2 Entity::GetVelocity() const
{
	return velocity;
}

void Entity::SetScale(float newScale)
{
	scale = newScale > 0 ? newScale : scale;
}

float Entity::GetScale() const
{
	return scale;
}

CollisionType Entity::GetCollisionType() const
{
	return collisionType;
}

void Entity::SetCollisionType(CollisionType newCollisionType)
{
	collisionType = newCollisionType;
}

Engine* const Entity::GetEngine() const
{
	return engine;
}
