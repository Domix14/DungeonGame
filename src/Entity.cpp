#include "Entity.h"

bool Entity::IsDestroyed()
{
	return bDestroyed;
}

void Entity::Destroy()
{
	bDestroyed = true;
}
