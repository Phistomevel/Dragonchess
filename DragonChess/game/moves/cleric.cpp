#include "cleric.h"
#include <map>
#include "../board.h"
#include <algorithm>
#include "../moves.h"
namespace game {
    namespace moves {

        Cleric::Cleric() {}
        Cleric::~Cleric() {}
        std::vector<::game::Moves> Cleric::getMovesRaw(::game::Board &board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::Moves> ret;
            ret.push_back(::game::Moves(1,0,0,::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(-1,0,0,::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(0,1,0,::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(0,-1,0,::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(1,1,0,::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(1,-1,0,::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(-1,1,0,::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(-1,-1,0,::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(0,0,-1,::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(0,0,1,::game::Moves::MOVE_RELATIVE));
            for (int i = 0; i < ret.size(); i++) {
                if (ret[i].moveType == ::game::Moves::MOVE_RELATIVE) {
                    ret[i].x += ActivePiece.getPosition().x;
                    ret[i].y += ActivePiece.getPosition().y;
                    ret[i].z += ActivePiece.getPosition().z;
                }
            }
            return ret;
        }
        std::vector<::game::moves::Capture> Cleric::getCapturesRaw(::game::Board &board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::moves::Capture> ret;
            ret.push_back(::game::Moves(1, 0, 0, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(-1, 0, 0, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(0, 1, 0, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(0, -1, 0, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(1, 1, 0, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(1, -1, 0, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(-1, 1, 0, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(-1, -1, 0, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(0, 0, -1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(0, 0, 1, ::game::Moves::MOVE_RELATIVE));
            return ret;
        }
        std::vector<::game::moves::Capture> Cleric::getThreatsInverted(::game::Board& board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::moves::Capture> ret;
            ret.push_back(::game::Moves(1, 0, 0, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(-1, 0, 0, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(0, 1, 0, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(0, -1, 0, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(1, 1, 0, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(1, -1, 0, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(-1, 1, 0, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(-1, -1, 0, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(0, 0, -1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(0, 0, 1, ::game::Moves::MOVE_RELATIVE));
            return ret;
        }

    }
}