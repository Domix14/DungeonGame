#include "Game.h"

#include "utils.h"
#include "StaticEntity.h"
#include "AnimatedEntity.h"
#include "Player.h"
#include "Engine.h"
#include <raylib.h>


Game::Game(Engine* inEngine) :
	engine(inEngine)
{
}

void Game::Start()
{
	// Top walls
	for (size_t i = 0; i < 12;++i)
	{
		Entity* entity = GetEngine()->AddEntity<StaticEntity>("wall_top_mid");
		entity->SetPosition({ (float)i * 48 + 96, 48 });
		entity->SetCollisionType(CollisionType::Static);
		entity = GetEngine()->AddEntity<StaticEntity>("wall_mid");
		entity->SetPosition({ (float)i * 48 + 96, 96 });
		
	}

	for (size_t i = 0; i < 7; ++i)
	{
		Entity* entity = GetEngine()->AddEntity<StaticEntity>("wall_side_mid_left");
		entity->SetPosition({ 48,(float)i * 48 + 96 });
		entity->SetCollisionType(CollisionType::Static);
	}


	
	// Floor
	for(size_t i = 0;i < 12;++i)
	{
		for(size_t j = 0; j < 6;++j)
		{
			Entity* entity = GetEngine()->AddEntity<StaticEntity>("floor_1");
			entity->SetPosition({ (float)i * 48 + 96, (float)j * 48 + 144 });
		}
	}


	std::vector<std::vector<std::string>> animations = { {"big_zombie_run_anim_f0", "big_zombie_run_anim_f1", "big_zombie_run_anim_f2", "big_zombie_run_anim_f3"} };
	Entity* entity = GetEngine()->AddEntity<Player>(animations);
	entity->SetPosition({ 128, 128 });
	entity->SetCollisionType(CollisionType::Dynamic);
}

Engine* const Game::GetEngine() const
{
	return engine;
}
