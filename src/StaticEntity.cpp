#include "StaticEntity.h"

#include "Engine.h"
#include "ResourceManager.h"
#include "utils.h"

StaticEntity::StaticEntity(Engine* engine, const std::string& textureName) :
	Entity(engine)
{

	if (!engine->GetResourceManager()->GetTexture(texture, textureName))
	{
		LOG("[ERROR]: Unable to load " + textureName + " texture");
	}
}

void StaticEntity::Draw(float scale)
{
	DrawTextureEx(*texture, GetPosition(), 0, scale, { 255,255,255,255 });
}

void StaticEntity::Update(float deltaTime)
{
}

void StaticEntity::OnCollision(Entity* entity)
{
}

Rectangle StaticEntity::GetCollisionRect()
{
	Rectangle rectangle;
	rectangle.height = texture->height;
	rectangle.width = texture->width;
	rectangle.x = GetPosition().x;
	rectangle.y = GetPosition().y;
	return rectangle;
}
