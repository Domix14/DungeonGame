#pragma once

class Engine;

class Game
{
public:
	Game(Engine* inEngine);
	void Start();

protected:
	Engine* const GetEngine() const;


private:
	Engine* engine;

};

