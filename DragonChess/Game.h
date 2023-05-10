#pragma once
#include "game/board.h"
#include "renderer/plain/RessourceManager.h"
class Game
{
public: 
	Game();
	~Game();
	virtual void run();
	virtual void onEvent(CView* sender);
protected:
	::game::Board board;
	::game::board::Position ActivePiece;
};

