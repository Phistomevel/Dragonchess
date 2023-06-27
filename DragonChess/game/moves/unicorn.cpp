#include "Unicorn.h"
#include <map>
#include <algorithm>
#include "../moves.h"
#include "../board.h"
namespace game {
    namespace moves {

        Unicorn::Unicorn() {}
        Unicorn::~Unicorn() {}
        std::vector<::game::Moves> Unicorn::getMovesRaw(::game::Board board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::Moves> ret;
            ret.push_back(::game::Moves(-2, 1,0,"relative"));
            ret.push_back(::game::Moves( 2, 1,0,"relative"));
            ret.push_back(::game::Moves(-2,-1,0,"relative"));
            ret.push_back(::game::Moves( 2,-1,0,"relative"));
            ret.push_back(::game::Moves(-1, 2, 0, "relative"));
            ret.push_back(::game::Moves( 1, 2, 0, "relative"));
            ret.push_back(::game::Moves(-1,-2, 0, "relative"));
            ret.push_back(::game::Moves( 1,-2, 0, "relative"));
            for (int i = 0; i < ret.size(); i++) {
                if (ret[i].moveType == ::game::Moves::MOVE_RELATIVE) {
                    ret[i].x += ActivePiece.getPosition().x;
                    ret[i].y += ActivePiece.getPosition().y;
                    ret[i].z += ActivePiece.getPosition().z;
                }
            }
            return ret;
        }
        std::vector<::game::moves::Capture> Unicorn::getCapturesRaw(::game::Board board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::moves::Capture> ret;
            ret.push_back(::game::moves::Capture(::game::Moves(-2, 1, 0, "relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(2, 1, 0, "relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(-2, -1, 0, "relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(2, -1, 0, "relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(-1, 2, 0, "relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(1, 2, 0, "relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(-1, -2, 0, "relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(1, -2, 0, "relative")));
            return ret;
        }
        std::vector<::game::moves::Capture> Unicorn::getThreatsInverted(::game::Board board, ::game::pieces::Abstract& ActivePiece) {
            return this->getCapturesRaw(board, ActivePiece);
        }
    }
}