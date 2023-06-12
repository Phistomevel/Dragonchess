#pragma once
#include "abstract.h"
namespace game {
	namespace moves {
		class Paladin : public ::game::moves::Abstract
		{
		public:
			Paladin();
			virtual ~Paladin();
			std::vector<::game::Moves> getMoves(::game::Board board, ::game::pieces::Abstract& ActivePiece) override;
			std::vector<::game::moves::Capture> getCaptures(::game::Board board, ::game::pieces::Abstract& ActivePiece) override;
		};
	}
}


