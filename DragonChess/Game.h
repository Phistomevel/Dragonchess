#pragma once
#include "game/board.h"
#include "renderer/plain/Render.h"
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
	::renderer::plain::Render renderer;
};

