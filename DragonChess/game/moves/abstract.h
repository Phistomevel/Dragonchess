#pragma once
#include <vector>
#include "../board/position.h"
#include "../moves.h";
#include "capture.h"
#include "../board.h"
#include "../pieces/abstract.h"
namespace game {
	namespace moves {
		class Abstract
		{
		public:
			Abstract();
			virtual ~Abstract();
			virtual std::vector<::game::Moves> getMoves(::game::Board board, ::game::pieces::Abstract& ActivePiece) = 0;
			virtual std::vector<::game::moves::Capture> getCaptures(::game::Board board, ::game::pieces::Abstract& ActivePiece)=0;

		};
	}
}

