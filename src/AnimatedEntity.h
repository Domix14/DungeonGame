#pragma once
#include "Entity.h"

#include <unordered_map>

class AnimatedEntity : public Entity
{
public:
	AnimatedEntity(Engine* engine, const std::vector<std::vector<std::string>>& animationsNames);
	
	virtual void Draw(float scale) override;
	virtual void Update(float deltaTime) override;
	virtual void OnCollision(Entity* entity) override;

	void SelectAnimation(size_t animationID);
	void UpdateAnimation();
	virtual Rectangle GetCollisionRect() override;

protected:
	void DrawAnimation(float scale);
	
private:
	std::vector<std::vector<Texture2D*>> animations;
	size_t selectedAnimation;
	size_t animationFrame;
	size_t prescaler;
	size_t prescalerCounter;
};

