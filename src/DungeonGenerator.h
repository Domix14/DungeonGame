#pragma once

#include <raylib.h>

struct Room
{
	Vector2 position;
	Vector2 dimension;
};

class DungeonGenerator
{
public:
	Room GetRandomRoom(Vector2 minDimensions, Vector2 maxDimensions, Vector2 minPos, Vector2 maxPos);
	
	
};

