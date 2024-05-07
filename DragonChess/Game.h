#pragma once
#include <algorithm>
#include <map>
#include "game/board.h"
#include "renderer/plain/RessourceManager.h"
#include "game/moves/factory.h"
#include "player/abstract.h"


class Game
{
public: 
	Game();
	~Game();
	virtual void run();
	virtual void onEvent(game::pieces::Abstract* sender);
	::game::Board& getBoard();
	static bool isThreatened(int x,int y,int z, ::game::Board *board=NULL);
	void setPlayer1(::player::Abstract *player1);
	void setPlayer2(::player::Abstract *player2);
protected:
	::game::Board board;
	::game::pieces::Abstract* ActivePiece;
	void showMoves();
	void hideMoves();
	::game::Moves getMovesFromCapture(::game::moves::Capture capture, std::vector<::game::moves::Capture> captureList);
	bool VectorContains(std::vector<::game::Moves> moves, game::Moves targetMove);
	bool VectorContains(std::vector<::game::moves::Capture> captures, game::moves::Capture targetCapture);
	std::string ActiveColor;
	::player::Abstract* ActivePlayer;
	::player::Abstract* player1;
	::player::Abstract* player2;
};

