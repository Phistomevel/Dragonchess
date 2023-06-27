#pragma once
#include "abstract.h"
namespace game {
	namespace moves {
		class Mage : public ::game::moves::Abstract
		{
		public:
			Mage();
			virtual ~Mage();
			std::vector<::game::Moves> getMovesRaw(::game::Board board, ::game::pieces::Abstract& ActivePiece) override;
			std::vector<::game::moves::Capture> getCapturesRaw(::game::Board board, ::game::pieces::Abstract& ActivePiece) override;
			std::vector<::game::moves::Capture> getThreatsInverted(::game::Board board, ::game::pieces::Abstract& ActivePiece) override;
		};
	}
}


