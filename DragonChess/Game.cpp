#include "Game.h"

Game::Game() {
	this->ActivePiece=NULL;
	this->ActiveColor = "blue";
}
Game::~Game() {}
void Game::run() {

}

bool Game::isThreatened(int x, int y, int z, ::game::Board *board) {
	if (board == NULL) {
		board = &this->board;
	}
	std::vector<std::string> allTypes = { ::game::pieces::Abstract::BASILISK,
	::game::pieces::Abstract::CLERIC,
	::game::pieces::Abstract::DWARF,
	::game::pieces::Abstract::DRAGON,
	::game::pieces::Abstract::ELEMENTAL,
	::game::pieces::Abstract::GRIFFON,
	::game::pieces::Abstract::HERO,
	::game::pieces::Abstract::KING,
	::game::pieces::Abstract::MAGE,
	::game::pieces::Abstract::OLIPHANT,
	::game::pieces::Abstract::PALADIN,
	::game::pieces::Abstract::SYLPH,
	::game::pieces::Abstract::THIEF,
	::game::pieces::Abstract::UNICORN,
	::game::pieces::Abstract::WARRIOR,
	};
	std::vector<::game::moves::Capture> threatsToCheck;
	for (auto pieceType : allTypes) {
		::game::moves::Abstract&  moveTypeObj = ::game::moves::Factory::getMyMoves(pieceType);
		threatsToCheck = moveTypeObj.getThreatsInverted(*board, board->getPieceByField(x, y, z));
		for (auto currthreat : threatsToCheck) {
			if (currthreat.capture.x+x>=0&& currthreat.capture.x+x<12&&
				currthreat.capture.y+y>=0&& currthreat.capture.y+y<8&&
				currthreat.capture.z+z>=0&& currthreat.capture.z+z<3){
				if (board->getPieceByField(currthreat.capture.x+x, currthreat.capture.y+y, currthreat.capture.z+z).getType() == pieceType&&
					board->getPieceByField(currthreat.capture.x+x, currthreat.capture.y+y, currthreat.capture.z+z).getColor()!=board->getPieceByField(x,y,z).getColor()) {
					return true;
				}
			}
		}
	}
	return false;

}

void Game::showMoves() {
	if (this->ActivePiece->getPetrifiedBy() != ::game::pieces::Abstract::UNDEFINED)
	{
		if (this->ActivePiece->getPetrifiedBy() != this->ActivePiece->getColor()) {
			return;
		}
	}
	std::vector<::game::Moves>	ActiveMoves;
	std::vector<::game::moves::Capture> ActiveCaptures;
	::game::moves::Abstract& moveTypeObj = ::game::moves::Factory::getMyMoves(this->ActivePiece->getType());
	ActiveMoves = moveTypeObj.getMoves(this->board, *this->ActivePiece);
	ActiveCaptures = moveTypeObj.getCaptures(this->board, *this->ActivePiece);
	for (auto CurrCapture : ActiveCaptures) {
		::game::Board boardAfterCapture(this->board);
		

		boardAfterCapture.getPieceByField(CurrCapture.capture.x,CurrCapture.capture.y,CurrCapture.capture.z).setType(::game::pieces::Abstract::UNDEFINED);
		std::string typeOfMovingPiece = ActivePiece->getType();
		boardAfterCapture.getPieceByField(ActivePiece->getPosition().x, ActivePiece->getPosition().y, ActivePiece->getPosition().z);
		::game::Moves targetMove = CurrCapture.move;
		boardAfterCapture.getPieceByField(targetMove.x, targetMove.y, targetMove.z).setType(typeOfMovingPiece);
		boardAfterCapture.getPieceByField(targetMove.x, targetMove.y, targetMove.z).setColor(this->ActivePiece->getColor());
		::game::pieces::Abstract& king =boardAfterCapture.getKing(this->ActiveColor);

		if (!this->isThreatened(king.getPosition().x, king.getPosition().y, king.getPosition().z,&boardAfterCapture)) {
			this->board.getPieceByField((CurrCapture.capture.x), (CurrCapture.capture.y), (CurrCapture.capture.z)).setState(::game::pieces::Abstract::TYPE_CAPTURE);
			this->board.getPieceByField((CurrCapture.capture.x), (CurrCapture.capture.y), (CurrCapture.capture.z)).Invalidate();
		}
		/*if (this->ActivePiece->getType() == ::game::pieces::Abstract::KING)
		{
			if (!this->isThreatened((CurrCapture.move.x), (CurrCapture.move.y), (CurrCapture.move.z))) {
				this->board.getPieceByField((CurrCapture.capture.x), (CurrCapture.capture.y), (CurrCapture.capture.z)).setState(::game::pieces::Abstract::TYPE_CAPTURE);
				this->board.getPieceByField((CurrCapture.capture.x), (CurrCapture.capture.y), (CurrCapture.capture.z)).Invalidate();
			}
		}
		else {
			this->board.getPieceByField((CurrCapture.capture.x), (CurrCapture.capture.y), (CurrCapture.capture.z)).setState(::game::pieces::Abstract::TYPE_CAPTURE);
			this->board.getPieceByField((CurrCapture.capture.x), (CurrCapture.capture.y), (CurrCapture.capture.z)).Invalidate();
		}*/
	}
	for (auto CurrMove : ActiveMoves) {
		::game::Board boardAfterCapture(this->board);
		//TODO: copy constructor vom board ändern, damit pieces initialisiert werden.


		std::string typeOfMovingPiece = ActivePiece->getType();
		boardAfterCapture.getPieceByField(ActivePiece->getPosition().x, ActivePiece->getPosition().y, ActivePiece->getPosition().z).setType(::game::pieces::Abstract::UNDEFINED);
		boardAfterCapture.getPieceByField(CurrMove.x, CurrMove.y, CurrMove.z).setType(typeOfMovingPiece);
		boardAfterCapture.getPieceByField(CurrMove.x, CurrMove.y, CurrMove.z).setColor(this->ActivePiece->getColor());
		::game::pieces::Abstract& king = boardAfterCapture.getKing(this->ActiveColor);
		//TODO: manage threats after theoretical move is made

		//std::vector<::game::moves::Capture> recursiveCaptures;

		if (!this->isThreatened(king.getPosition().x, king.getPosition().y, king.getPosition().z, &boardAfterCapture)) {
			this->board.getPieceByField((CurrMove.x), (CurrMove.y), (CurrMove.z)).setState(::game::pieces::Abstract::TYPE_MOVE);
			this->board.getPieceByField((CurrMove.x), (CurrMove.y), (CurrMove.z)).Invalidate();
		}

		/*
		if (this->ActivePiece->getType() == ::game::pieces::Abstract::KING)
		{
			if (!this->isThreatened((CurrMove.x), (CurrMove.y), (CurrMove.z))) {
				this->board.getPieceByField((CurrMove.x), (CurrMove.y), (CurrMove.z)).setState(::game::pieces::Abstract::TYPE_MOVE);
				this->board.getPieceByField((CurrMove.x), (CurrMove.y), (CurrMove.z)).Invalidate();
			}
		}
		else {
			this->board.getPieceByField((CurrMove.x), (CurrMove.y), (CurrMove.z)).setState(::game::pieces::Abstract::TYPE_MOVE);
			this->board.getPieceByField((CurrMove.x), (CurrMove.y), (CurrMove.z)).Invalidate();
		}
		*/
	}
}
void Game::hideMoves() {

	std::vector<::game::Moves>	ActiveMoves;
	std::vector<::game::moves::Capture> ActiveCaptures;
	::game::moves::Abstract& moveTypeObj = ::game::moves::Factory::getMyMoves(this->ActivePiece->getType());
	ActiveMoves = moveTypeObj.getMoves(this->board, *this->ActivePiece);
	ActiveCaptures = moveTypeObj.getCaptures(this->board, *this->ActivePiece);
	for (auto CurrCapture : ActiveCaptures) {
		this->board.getPieceByField((CurrCapture.capture.x), (CurrCapture.capture.y), (CurrCapture.capture.z)).setState(::game::pieces::Abstract::TYPE_DEFAULT);
		this->board.getPieceByField((CurrCapture.capture.x), (CurrCapture.capture.y), (CurrCapture.capture.z)).Invalidate();
	}
	for (auto CurrMove : ActiveMoves) {
		this->board.getPieceByField((CurrMove.x), (CurrMove.y), (CurrMove.z)).setState(::game::pieces::Abstract::TYPE_DEFAULT);
		this->board.getPieceByField((CurrMove.x), (CurrMove.y), (CurrMove.z)).Invalidate();
	}
}
::game::Moves Game::getMovesFromCapture(::game::moves::Capture capture, std::vector<::game::moves::Capture> captureList) {
	std::map<::game::Moves, ::game::Moves> capturesToMoves;
	for (auto element : captureList)
	{
		capturesToMoves.emplace(element.capture,element.move);//TODO fix whatever is going on with the mage and the dragon
	}
	//if()
	return capturesToMoves.at(capture.capture);
	//return moves.at(std::find(captures.begin(),captures.end(),capture.move));
	return NULL;
}

void Game::onEvent(game::pieces::Abstract* sender) {
	std::vector<::game::Moves>	ActiveMoves;
	std::vector<::game::moves::Capture> ActiveCaptures;
	if (!this->ActivePiece) {
		if (sender->getType() != game::pieces::Abstract::UNDEFINED&&sender->getColor()==this->ActiveColor) {
			this->ActivePiece = sender;
			this->showMoves();
		}
		else {
			sender->OnRButtonDown(NULL, NULL);
		}
		return;
	}
	::game::moves::Abstract& moveTypeObj = ::game::moves::Factory::getMyMoves(this->ActivePiece->getType());
	ActiveMoves = moveTypeObj.getMoves(this->board, *this->ActivePiece);
	ActiveCaptures = moveTypeObj.getCaptures(this->board, *this->ActivePiece);
	showMoves();
	//get moves of active piece

	if (this->ActivePiece!=NULL&&this->ActivePiece->getType()!=game::pieces::Abstract::UNDEFINED/*check if leads to a valid move*/) {
			
		if (sender->getState() == ::game::pieces::Abstract::TYPE_MOVE || sender->getState() == ::game::pieces::Abstract::TYPE_CAPTURE) {
			if (this->ActivePiece->getType() == ::game::pieces::Abstract::BASILISK)
			{
				this->board.getPieceByField(this->ActivePiece->getPosition().x, this->ActivePiece->getPosition().y, this->ActivePiece->getPosition().z + 1).setPetrified(::game::pieces::Abstract::UNDEFINED);
				this->board.getPieceByField(sender->getPosition().x, sender->getPosition().y, sender->getPosition().z + 1).setPetrified(ActivePiece->getColor());
			}
			//petrify the piece above, if the type is basilisk


			if (sender->getState() == ::game::pieces::Abstract::TYPE_CAPTURE) {

				this->hideMoves();

				
				


				sender->setType(::game::pieces::Abstract::UNDEFINED);
				std::string typeOfMovingPiece = ActivePiece->getType();
				ActivePiece->setType(::game::pieces::Abstract::UNDEFINED);
				::game::Moves targetMove = this->getMovesFromCapture(::game::moves::Capture(::game::Moves(sender->getPosition().x, sender->getPosition().y, sender->getPosition().z)),ActiveCaptures);
				this->board.getPieceByField(targetMove.x, targetMove.y, targetMove.z).setType(typeOfMovingPiece);
				this->board.getPieceByField(targetMove.x, targetMove.y, targetMove.z).setColor(this->ActivePiece->getColor());
				this->ActivePiece->OnRButtonDown(NULL,NULL);
				this->ActivePiece->Invalidate();
				if (this->ActiveColor=="red")
				{
					this->ActiveColor = "blue";
				}
				else {
					this->ActiveColor = "red";
				}
			}
			else
			{
				this->hideMoves();


				sender->setType(this->ActivePiece->getType());
				sender->setColor(this->ActivePiece->getColor());
				sender->setState(::game::pieces::Abstract::TYPE_DEFAULT);
				this->ActivePiece->setState(::game::pieces::Abstract::TYPE_DEFAULT);
				this->ActivePiece->setType(::game::pieces::Abstract::UNDEFINED);
				this->ActivePiece->Invalidate();
				this->ActivePiece = NULL;
				if (this->ActiveColor == "red")
				{
					this->ActiveColor = "blue";
				}
				else {
					this->ActiveColor = "red";
				}
			}
			
			if (sender->getType()==::game::pieces::Abstract::WARRIOR)
			{
				if (sender->getColor() == ::game::pieces::Abstract::COLOR_BLACK)
				{
					if (sender->getPosition().y == 0)
					{
						sender->setType(::game::pieces::Abstract::HERO);
					}
					
				}
				else
				{
					if (sender->getPosition().y == 7)
					{
						sender->setType(::game::pieces::Abstract::HERO);
					}
				}
				
			}
			//turn warriors into heroes if they reach the last rowthis->ActivePiece->setType(game::pieces::Abstract::UNDEFINED);
			
			/*Move piece to new position*/
			
			sender->Invalidate();
			return;
		}
	}
	if (sender == this->ActivePiece) {
		sender->setState(::game::pieces::Abstract::TYPE_DEFAULT);
		this->hideMoves();
		this->ActivePiece = NULL;
		return;
	}
	if (sender->getType()!=game::pieces::Abstract::UNDEFINED&&sender->getColor()==this->ActiveColor) {
		if (this->ActivePiece!=NULL) {
			ActivePiece->OnRButtonDown(NULL, NULL);
		}
		this->hideMoves();
		this->ActivePiece = sender;
		this->showMoves();
		return;
	}
	else {
		sender->OnRButtonDown(NULL, NULL);
	}
	//sender.OnRButtonDown(NULL,NULL);
	//this->board.getPieceByField(this->ActivePiece.x, this->ActivePiece.y, this->ActivePiece.z).OnRButtonDown(NULL,NULL);
}
game::Board& Game::getBoard() {
	return (this->board);
}



bool Game::VectorContains(std::vector<::game::Moves> moves, game::Moves targetMove) {
	return (std::find(moves.begin(), moves.end(), targetMove) != moves.end());
}

bool Game::VectorContains(std::vector<::game::moves::Capture> captures, game::moves::Capture targetCapture) {
	return (std::find(captures.begin(), captures.end(), targetCapture) != captures.end());
}