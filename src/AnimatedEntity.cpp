#include "AnimatedEntity.h"

#include "Engine.h"
#include "ResourceManager.h"

AnimatedEntity::AnimatedEntity(Engine* engine, const std::vector<std::vector<std::string>>& animationsNames) :
	Entity(engine), selectedAnimation(0), animationFrame(0), prescaler(5), prescalerCounter(0)
{
	for(const auto& anim : animationsNames)
	{
		animations.emplace_back(std::vector<Texture2D*>());
		for(const auto& animName : anim)
		{
			animations.back().emplace_back();
			GetEngine()->GetResourceManager()->GetTexture(animations.back().back(), animName);
		}
	}
}

void AnimatedEntity::Draw(float scale)
{
	DrawAnimation(scale);
}

void AnimatedEntity::Update(float deltaTime)
{
	UpdateAnimation();
}

void AnimatedEntity::OnCollision(Entity* entity)
{
}

void AnimatedEntity::SelectAnimation(size_t animationID)
{
	animationFrame = 0;
	selectedAnimation = animationID;
}

void AnimatedEntity::UpdateAnimation()
{
	prescalerCounter++;
	if(prescalerCounter == prescaler)
	{
		prescalerCounter = 0;
		animationFrame++;
		if (animationFrame == animations[selectedAnimation].size())
		{
			animationFrame = 0;
		}
	}
}

Rectangle AnimatedEntity::GetCollisionRect()
{
	Rectangle rectangle;
	rectangle.height = animations[selectedAnimation][animationFrame]->height - 10;
	rectangle.width = animations[selectedAnimation][animationFrame]->width - 10;
	rectangle.x = GetPosition().x + 10;
	rectangle.y = GetPosition().y + 10;
	return rectangle;
}

void AnimatedEntity::DrawAnimation(float scale)
{
	DrawTextureEx(*animations[selectedAnimation][animationFrame], GetPosition(), 0, scale, { 255,255,255,255 });
}
