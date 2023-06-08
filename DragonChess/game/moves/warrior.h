#pragma once
#include "abstract.h"
namespace game {
	namespace moves {
		class Warrior : public ::game::moves::Abstract
		{
		public:
			Warrior();
			virtual ~Warrior();
			std::vector<::game::Moves> getMoves(::game::Board board, ::game::pieces::Abstract& ActivePiece) override;
			std::vector<::game::moves::Capture> getCaptures(::game::Board board, ::game::pieces::Abstract& ActivePiece) override;
		};
	}
}


