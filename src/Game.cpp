#include "Game.h"

#include "utils.h"
#include <raylib.h>

void Game::Launch()
{
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "DungeonGame");
	SetTargetFPS(60);
	MainLoop();
	
}

void Game::MainLoop()
{

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		EndDrawing();
	}
	
	CloseWindow();
}
