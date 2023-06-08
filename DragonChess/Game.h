#pragma once
#include <algorithm>
#include <map>
#include "game/board.h"
#include "renderer/plain/RessourceManager.h"
#include "game/moves/factory.h"


class Game
{
public: 
	Game();
	~Game();
	virtual void run();
	virtual void onEvent(game::pieces::Abstract* sender);
	::game::Board& getBoard();
protected:
	::game::Board board;
	::game::pieces::Abstract* ActivePiece;
	void showMoves();
	void hideMoves();
	::game::Moves getMovesFromCapture(::game::moves::Capture capture, std::vector<::game::moves::Capture> captureList);
	bool VectorContains(std::vector<::game::Moves> moves, game::Moves targetMove);
	bool VectorContains(std::vector<::game::moves::Capture> captures, game::moves::Capture targetCapture);
};

