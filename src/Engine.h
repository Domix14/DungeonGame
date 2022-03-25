#pragma once

#include <vector>
#include <string>

#include <raylib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define GRID_SIZE 48

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
	void SetCameraPosition(Vector2 pos);

	template<class T, typename... Types>
	Entity* AddEntity(Types... args)
	{
		entities.push_back(new T(this, args...));
		CalculateStaticCollisions();
		return entities.back();
	}
	

	

private:

	void MainLoop();
	void DrawEntities();
	void UpdateEntities(float deltaTime);
	void CalculateStaticCollisions();
	void UpdateDynamicCollisions(float deltaTime);
	void DrawCollisions();

	Camera2D camera;
	Game* game;
	ResourceManager* resourceManager;
	std::vector<Entity*> entities;

	std::vector<std::vector<uint8_t>> staticCollisions;
};

