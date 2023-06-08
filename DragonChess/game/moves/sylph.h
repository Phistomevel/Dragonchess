#pragma once
#include "abstract.h"
namespace game {
    namespace moves {
        class Sylph : public ::game::moves::Abstract
        {
        public:
            Sylph();
            virtual ~Sylph();
            std::vector<::game::Moves> getMoves(::game::Board board, ::game::pieces::Abstract& ActivePiece) override;
            std::vector<::game::moves::Capture> getCaptures(::game::Board board, ::game::pieces::Abstract& ActivePiece) override;
        };
    }
}
