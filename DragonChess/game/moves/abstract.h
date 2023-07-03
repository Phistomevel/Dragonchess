#pragma once
#include <vector>
#include "../board/position.h"
#include "../moves.h";
#include "capture.h"

#include "../pieces/abstract.h"

namespace game {
	class Board;
}

namespace game {
	namespace moves {
		class Abstract
		{
		public:
			Abstract();
			virtual ~Abstract();
			virtual std::vector<::game::Moves> getMovesRaw(::game::Board &board, ::game::pieces::Abstract& ActivePiece) = 0;
			virtual std::vector<::game::moves::Capture> getCapturesRaw(::game::Board &board, ::game::pieces::Abstract& ActivePiece)=0;
			virtual std::vector<::game::moves::Capture> getThreatsInverted(::game::Board &board, ::game::pieces::Abstract& ActivePiece)=0;
			std::vector<::game::Moves> getMoves(::game::Board &board, ::game::pieces::Abstract& ActivePiece);
			std::vector<::game::moves::Capture> getCaptures(::game::Board &board, ::game::pieces::Abstract& ActivePiece);
		};
	}
}