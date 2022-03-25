#pragma once

#include "Entity.h"

#include <string>

class StaticEntity : public Entity
{
public:
	StaticEntity(Engine* engine, const std::string& textureName);

	virtual void Draw() override;
	virtual void Update(float deltaTime) override;
	virtual void OnCollision(Entity* entity) override;
	virtual Rectangle GetCollisionRect() override;

private:
	Texture2D* texture;
};

