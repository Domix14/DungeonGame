#pragma once
#include "AnimatedEntity.h"
class Player : public AnimatedEntity
{
public:
	Player(Engine* engine, const std::vector<std::vector<std::string>>& animationsNames);
	
	virtual void Draw() override;
	virtual void Update(float deltaTime) override;
};

