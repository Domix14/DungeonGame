#include "Game.h"

#include "utils.h"
#include "StaticEntity.h"
#include "Engine.h"
#include <raylib.h>


Game::Game(Engine* inEngine) :
	engine(inEngine)
{
}

void Game::Start()
{
	for (size_t i = 0; i < 12; i++)
	{
		Entity* entity = GetEngine()->AddEntity<StaticEntity>("wall_top_mid");
		entity->SetPosition({ (float)i * 64 + 64, 64 });
		entity = GetEngine()->AddEntity<StaticEntity>("wall_mid");
		entity->SetPosition({ (float)i * 64 + 64, 128 });
		entity = GetEngine()->AddEntity<StaticEntity>("floor_1");
		entity->SetPosition({ (float)i * 64 + 64, 192});
		entity = GetEngine()->AddEntity<StaticEntity>("floor_1");
		entity->SetPosition({ (float)i * 64 + 64, 256 });
	}
	//StaticEntity* wall = dynamic_cast<StaticEntity*>(GetEngine()->AddEntity<StaticEntity>("wall_mid"));
}

Engine* const Game::GetEngine() const
{
	return engine;
}
