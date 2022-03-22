
#include "Game.h"
#include "Engine.h"

int main()
{
    Engine engine;
    Game newGame(&engine);
    engine.Launch(&newGame, "Dungeon Game");

    return 0;
}