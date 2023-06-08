#pragma once
#include "abstract.h"
namespace game {
    namespace moves {
        class NoMoves :public  game::moves::Abstract
        {
            public:
                virtual ~NoMoves();
                std::vector<::game::Moves> getMoves(::game::Board board, ::game::pieces::Abstract & ActivePiece) override;
                std::vector<::game::moves::Capture> getCaptures(::game::Board board, ::game::pieces::Abstract & ActivePiece) override;
        };
    }
}


