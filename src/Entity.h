#pragma once
class Entity
{
public:
	virtual void Draw() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void OnCollision(Entity* entity) = 0;

	bool IsDestroyed();
	virtual void Destroy();

protected:
	

private:
	bool bDestroyed;
};

