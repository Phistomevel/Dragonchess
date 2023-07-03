#include "nomoves.h"
#include "../board.h"
namespace game {
	namespace moves {
		NoMoves::~NoMoves() {};
		std::vector<::game::Moves> NoMoves::getMovesRaw(::game::Board &board, ::game::pieces::Abstract& ActivePiece) {
			std::vector<::game::Moves> ret;
			return ret;
		};
		std::vector<::game::moves::Capture> NoMoves::getCapturesRaw(::game::Board &board, ::game::pieces::Abstract& ActivePiece) {
			std::vector<::game::moves::Capture> ret;
			return ret;
		};
		std::vector<::game::moves::Capture> NoMoves::getThreatsInverted(::game::Board &board, ::game::pieces::Abstract& ActivePiece) {
			std::vector<::game::moves::Capture> ret;
			return ret;
		};
	}
}