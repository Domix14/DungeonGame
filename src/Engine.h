#pragma once

#include <vector>

class Entity;

class Engine
{
	void AddEntity(Entity* newEntity);

private:

	void DrawEntities();
	void UpdateEntities(float deltaTime);


	std::vector<Entity*> entities;
};

