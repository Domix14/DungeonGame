#include "Engine.h"

#include "Entity.h"

void Engine::AddEntity(Entity* newEntity)
{
	if (newEntity)
	{
		entities.push_back(newEntity);
	}
}

void Engine::DrawEntities()
{
	for (auto entity : entities)
	{
		if (!entity->IsDestroyed())
		{
			entity->Draw();
		}
	}
}

void Engine::UpdateEntities(float deltaTime)
{
	for (auto entity : entities)
	{
		if (!entity->IsDestroyed())
		{
			entity->Update(deltaTime);
		}
	}
}
