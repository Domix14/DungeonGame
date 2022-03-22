#pragma once

#include <raylib.h>

class Engine;

class Entity
{
public:
	Entity(Engine* engine);

	virtual void Draw(float scale) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void OnCollision(Entity* entity) = 0;

	bool IsDestroyed() const;
	virtual void Destroy();

	Vector2 GetPosition();
	void SetPosition(Vector2 newPosition);

protected:
	const Engine* GetEngine() const;

private:
	Engine* engine;

	Vector2 position;
	bool bDestroyed;
};

