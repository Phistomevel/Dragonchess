#pragma once
#include "abstract.h"
namespace game {
	namespace moves {
		class Unicorn : public ::game::moves::Abstract
		{
		public:
			Unicorn();
			virtual ~Unicorn();
			std::vector<::game::Moves> getMoves(::game::Board board, ::game::pieces::Abstract& ActivePiece) override;
			std::vector<::game::moves::Capture> getCaptures(::game::Board board, ::game::pieces::Abstract& ActivePiece) override;
		};
	}
}


