#include "nomoves.h"
namespace game {
	namespace moves {
		NoMoves::~NoMoves() {};
		std::vector<::game::Moves> NoMoves::getMoves(::game::Board board, ::game::pieces::Abstract& ActivePiece) {
			std::vector<::game::Moves> ret;
			return ret;
		};
		std::vector<::game::moves::Capture> NoMoves::getCaptures(::game::Board board, ::game::pieces::Abstract& ActivePiece) {
			std::vector<::game::moves::Capture> ret;
			return ret;
		};
	}
}