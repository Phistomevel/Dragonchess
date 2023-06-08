#pragma once
#include "abstract.h"
namespace game {
    namespace moves {
        class Griffon :
            public ::game::moves::Abstract
        {
        public:
            virtual ~Griffon();
            std::vector<::game::Moves> getMoves(::game::Board board, ::game::pieces::Abstract& ActivePiece) override;
            std::vector<::game::moves::Capture> getCaptures(::game::Board board, ::game::pieces::Abstract& ActivePiece) override;
        };
    }
}