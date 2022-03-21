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

		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
	}
	
	CloseWindow();
}
