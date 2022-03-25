#include "DungeonGenerator.h"

Room DungeonGenerator::GetRandomRoom(Vector2 minDimensions, Vector2 maxDimensions, Vector2 minPos, Vector2 maxPos)
{
	Room room;
	room.dimension.x = GetRandomValue(minDimensions.x, maxDimensions.x);
	room.dimension.y = GetRandomValue(minDimensions.y, maxDimensions.y);
	room.position.x = GetRandomValue(minPos.x, maxPos.x);
	room.position.y = GetRandomValue(minPos.y, maxPos.y);
	return room;
}

