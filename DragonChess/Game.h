#pragma once
#include "game/board.h"
#include "renderer/plain/RessourceManager.h"
class Game
{
public: 
	Game();
	~Game();
	virtual void run();
	virtual void render();
	virtual void onEvent();
protected:
	::game::Board board;
	::renderer::plain::RessourceManager renderer;
};

