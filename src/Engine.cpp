#include "Engine.h"

#include <raylib.h>
#include "Entity.h"
#include "Game.h"
#include "ResourceManager.h"

Engine::Engine()
{
	resourceManager = new ResourceManager();
}

Engine::~Engine()
{
	delete resourceManager;
}

void Engine::Launch(Game* newGame, const std::string& title)
{
	game = newGame;
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, title.c_str());
	SetTargetFPS(60);

	game->Start();

	MainLoop();
}

const Game* Engine::GetGame() const
{
	return game;
}

ResourceManager* const Engine::GetResourceManager() const
{
	return resourceManager;
}

void Engine::MainLoop()
{
	while (!WindowShouldClose())
	{
		UpdateEntities(0);

		ClearBackground(RAYWHITE);

		DrawEntities();

		EndDrawing();
	}
}

void Engine::DrawEntities()
{
	for (auto entity : entities)
	{
		if (!entity->IsDestroyed())
		{
			entity->Draw(4);
		}
	}
}

void Engine::UpdateEntities(float deltaTime)
{
	for (auto entity : entities)
	{
		if (!entity->IsDestroyed())
		{
			entity->Update(deltaTime);
		}
	}
}
