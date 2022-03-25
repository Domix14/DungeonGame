#pragma once

#include <raylib.h>

class Engine;

enum class CollisionType
{
	NoCollision,
	Static,
	Dynamic
};

class Entity
{
public:
	Entity(Engine* engine);

	virtual void Draw() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void OnCollision(Entity* entity) = 0;

	bool IsDestroyed() const;
	virtual void Destroy();

	Vector2 GetPosition();
	void SetPosition(Vector2 newPosition);
	void Move(Vector2 dPos);
	void SetVelocity(Vector2 newVelocity);
	Vector2 GetVelocity() const;
	void SetScale(float newScale);
	float GetScale() const;

	CollisionType GetCollisionType() const;
	void SetCollisionType(CollisionType newCollisionType);
	virtual Rectangle GetCollisionRect() = 0;
	
	
protected:
	Engine* const GetEngine() const;

private:
	Engine* engine;

	Vector2 velocity;
	Rectangle collisionRect;
	Vector2 position;
	CollisionType collisionType;
	float scale;
	bool bDestroyed;
};

