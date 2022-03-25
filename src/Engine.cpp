#include "Engine.h"

#include <raylib.h>
#include "Entity.h"
#include "Game.h"
#include "ResourceManager.h"

Engine::Engine()
{
	resourceManager = new ResourceManager();
	camera.target = { 0,0 };
	camera.rotation = 0;
	camera.offset = { 0, 0 };
	camera.zoom = 1;
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

void Engine::SetCameraPosition(Vector2 pos)
{
	camera.target = pos;
}

void Engine::MainLoop()
{
	while (!WindowShouldClose())
	{
		UpdateEntities(0);
		UpdateDynamicCollisions(GetFrameTime());
		
		ClearBackground(RAYWHITE);
		
		BeginMode2D(camera);
		DrawEntities();
		DrawCollisions();
		EndMode2D();
		
		EndDrawing();
	}
}

void Engine::DrawEntities()
{
	for (auto entity : entities)
	{
		if (!entity->IsDestroyed())
		{
			entity->Draw(3);
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

void Engine::CalculateStaticCollisions()
{
	float maxWidth = 0;
	float maxHeight = 0;

	for(const auto& entity : entities)
	{
		if(entity->GetCollisionType() == CollisionType::Static)
		{
			float width = entity->GetCollisionRect().x + entity->GetCollisionRect().width;
			float height = entity->GetCollisionRect().y + entity->GetCollisionRect().height;
			maxWidth = width > maxWidth ? width : maxWidth;
			maxHeight = height > maxHeight ? height : maxHeight;
		}
	}
	
	maxWidth += GRID_SIZE;
	maxHeight += GRID_SIZE;

	staticCollisions.resize(static_cast<size_t>(maxWidth / GRID_SIZE));
	for(auto& column: staticCollisions)
	{
		column.resize(static_cast<size_t>(maxHeight / GRID_SIZE));
	}

	for (const auto& entity : entities)
	{
		if (entity->GetCollisionType() == CollisionType::Static)
		{
			Rectangle rect = entity->GetCollisionRect();
			staticCollisions[entity->GetCollisionRect().x / GRID_SIZE][entity->GetCollisionRect().y / GRID_SIZE] = 1;
		}
	}
}

void Engine::UpdateDynamicCollisions(float deltaTime)
{
	for(auto& entity : entities)
	{
		if(entity->GetCollisionType() == CollisionType::Dynamic)
		{
			// Check for collisions with static entities
			Vector2 velocity = entity->GetVelocity();
			Rectangle rect = entity->GetCollisionRect();
			rect.x += velocity.x * deltaTime;
			rect.y += velocity.y * deltaTime;
			if(velocity.x > 0)
			{
				size_t x = static_cast<size_t>((rect.x + rect.width) / GRID_SIZE);
				size_t y = static_cast<size_t>((rect.y) / GRID_SIZE);
				if(staticCollisions[x][y]) //TODO: Add safety checks
				{
					velocity.x = 0;
				}
			}
			else if(velocity.x < 0)
			{
				size_t x = static_cast<size_t>((rect.x) / GRID_SIZE);
				size_t y = static_cast<size_t>((rect.y) / GRID_SIZE);
				if (staticCollisions[x][y])
				{
					velocity.x = 0;
				}
			}

			if (velocity.y > 0)
			{
				size_t x = static_cast<size_t>((rect.x) / GRID_SIZE);
				size_t y = static_cast<size_t>((rect.y + rect.height) / GRID_SIZE);
				if (staticCollisions[x][y])
				{
					velocity.y = 0;
				}
			}
			else if (velocity.y < 0)
			{
				size_t x = static_cast<size_t>((rect.x) / GRID_SIZE);
				size_t y = static_cast<size_t>((rect.y) / GRID_SIZE);
				if (staticCollisions[x][y])
				{
					velocity.y = 0;
				}
			}

			Vector2 pos = entity->GetPosition();
			pos.x += velocity.x;
			pos.y += velocity.y;
			entity->SetPosition(pos);
		}
	}
}

void Engine::DrawCollisions()
{
	for(size_t i = 0;i < staticCollisions.size();i++)
	{
		for(size_t j = 0;j < staticCollisions[i].size();j++)
		{
			if(staticCollisions[i][j] == 1)
			{
				DrawRectangle(i * 48, j * 48, 48, 48, RED);
			}
		}
	}
}
