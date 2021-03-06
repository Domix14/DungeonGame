#include "Player.h"

#include "Engine.h"

Player::Player(Engine* engine,const std::vector<std::vector<std::string>>& animationsNames) :
AnimatedEntity(engine, animationsNames)
{
}

void Player::Draw()
{
	DrawAnimation();
}

void Player::Update(float deltaTime)
{
	UpdateAnimation();
	SetVelocity({ 0,0 });
	if (IsKeyDown(KEY_D)) SetVelocity({ 2, 0 });
	if (IsKeyDown(KEY_S)) SetVelocity({ 0, 2 });
	if (IsKeyDown(KEY_A)) SetVelocity({ -2, 0 });
	if (IsKeyDown(KEY_W)) SetVelocity({ 0, -2 });
	GetEngine()->SetCameraPosition(GetPosition());

	if (abs(GetVelocity().x) > 0 || abs(GetVelocity().y) > 0)
	{
		SelectAnimation(1);
	}
	else
	{
		SelectAnimation(0);
	}
}
