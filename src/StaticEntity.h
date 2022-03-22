#pragma once

#include "Entity.h"

#include <string>

class StaticEntity : public Entity
{
public:
	StaticEntity(Engine* engine, const std::string& textureName);

	virtual void Draw(float scale) override;
	virtual void Update(float deltaTime) override;
	virtual void OnCollision(Entity* entity) override;

private:
	Texture2D* texture;
};

