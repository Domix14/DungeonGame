#pragma once

#include <vector>
#include <string>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

class Entity;
class Game;
class ResourceManager;

class Engine
{
public:
	Engine();
	~Engine();

	void Launch(Game* newGame, const std::string& title);
	const Game* GetGame() const;
	ResourceManager* const GetResourceManager() const;

	template<class T, typename... Types>
	Entity* AddEntity(Types... args)
	{
		entities.push_back(new T(this, args...));
		return entities.back();
	}
	

	

private:

	void MainLoop();
	void DrawEntities();
	void UpdateEntities(float deltaTime);

	Game* game;
	ResourceManager* resourceManager;
	std::vector<Entity*> entities;
};

