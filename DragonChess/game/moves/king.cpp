#include "king.h"
#include <map>
#include <algorithm>
#include "../moves.h"
#include "../board.h"
namespace game {
    namespace moves {

        King::King() {}
        King::~King() {}
        std::vector<::game::Moves> King::getMovesRaw(::game::Board &board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::Moves> ret;
            if (ActivePiece.getPosition().z==1)
            {
                ret.push_back(::game::Moves( 1, 0,0,::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-1, 0,0,::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves( 0, 1,0,::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves( 0,-1,0,::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves( 1,-1,0,::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-1,-1,0,::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves( 1, 1,0,::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-1, 1,0,::game::Moves::MOVE_RELATIVE));
            }
            ret.push_back(::game::Moves(0, 0, 1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(0, 0, -1, ::game::Moves::MOVE_RELATIVE));
            for (int i = 0; i < ret.size(); i++) {
                if (ret[i].moveType == ::game::Moves::MOVE_RELATIVE) {
                    ret[i].x += ActivePiece.getPosition().x;
                    ret[i].y += ActivePiece.getPosition().y;
                    ret[i].z += ActivePiece.getPosition().z;
                }
            }
            return ret;
        }
        std::vector<::game::moves::Capture> King::getCapturesRaw(::game::Board& board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::moves::Capture> ret;
            

            if (ActivePiece.getPosition().z == 1)
            {
                ret.push_back(::game::Moves(1, 0, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-1, 0, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(0, 1, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(0, -1, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(1, -1, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-1, -1, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(1, 1, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-1, 1, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(0, 0, 1, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(0, 0, -1, ::game::Moves::MOVE_RELATIVE));
            }
            return ret;
        }
        std::vector<::game::moves::Capture> King::getThreatsInverted(::game::Board& board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::moves::Capture> ret;
            if (ActivePiece.getPosition().z == 1)
            {
                ret.push_back(::game::Moves(1, 0, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-1, 0, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(0, 1, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(0, -1, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(1, -1, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-1, -1, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(1, 1, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-1, 1, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(0, 0, 1, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(0, 0, -1, ::game::Moves::MOVE_RELATIVE));
            }
            return ret;
        }

    }
}