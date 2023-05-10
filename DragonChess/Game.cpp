#include "Game.h"

Game::Game() {}
Game::~Game() {}
void Game::run() {

}
void Game::onEvent(CView* sender) {
	this->board.getPieceByField(this->ActivePiece.x, this->ActivePiece.y, this->ActivePiece.z).OnRButtonDown(NULL,NULL);
}
