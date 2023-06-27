#include "hero.h"
#include <map>
#include <algorithm>
#include "../moves.h"
#include "../board.h"
namespace game {
    namespace moves {

        Hero::Hero() {}
        Hero::~Hero() {}
        std::vector<::game::Moves> Hero::getMovesRaw(::game::Board board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::Moves> ret;
            if (ActivePiece.getPosition().z==1)
            {
                ret.push_back(::game::Moves(1,1,0,::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-1,1,0,::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(1,-1,0,::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-1,-1,0,::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(2,2,0,::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-2,2,0,::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(2,-2,0,::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-2,-2,0,::game::Moves::MOVE_RELATIVE));
            }
            ret.push_back(::game::Moves(1, 1, 1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(1, 1, -1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(1, -1, 1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(1, -1, -1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(-1, 1, 1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(-1, 1, -1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(-1, -1, 1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(-1, -1, -1, ::game::Moves::MOVE_RELATIVE));
            for (int i = 0; i < ret.size(); i++) {
                if (ret[i].moveType == ::game::Moves::MOVE_RELATIVE) {
                    ret[i].x += ActivePiece.getPosition().x;
                    ret[i].y += ActivePiece.getPosition().y;
                    ret[i].z += ActivePiece.getPosition().z;
                }
            }
            return ret;
        }
        std::vector<::game::moves::Capture> Hero::getCapturesRaw(::game::Board board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::moves::Capture> ret;
            if (ActivePiece.getPosition().z == 1)
            {
                ret.push_back(::game::Moves(1, 1, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-1, 1, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(1, -1, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-1, -1, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(2, 2, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-2, 2, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(2, -2, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-2, -2, 0, ::game::Moves::MOVE_RELATIVE));
            }
            ret.push_back(::game::Moves(1, 1, 1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(1, 1, -1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(1, -1, 1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(1, -1, -1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(-1, 1, 1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(-1, 1, -1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(-1, -1, 1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(-1, -1, -1, ::game::Moves::MOVE_RELATIVE));
            return ret;
        }
        std::vector<::game::moves::Capture> Hero::getThreatsInverted(::game::Board board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::moves::Capture> ret;
            if (ActivePiece.getPosition().z == 1)
            {
                ret.push_back(::game::Moves(1, 1, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-1, 1, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(1, -1, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-1, -1, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(2, 2, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-2, 2, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(2, -2, 0, ::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-2, -2, 0, ::game::Moves::MOVE_RELATIVE));
            }
            ret.push_back(::game::Moves(1, 1, 1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(1, 1, -1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(1, -1, 1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(1, -1, -1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(-1, 1, 1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(-1, 1, -1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(-1, -1, 1, ::game::Moves::MOVE_RELATIVE));
            ret.push_back(::game::Moves(-1, -1, -1, ::game::Moves::MOVE_RELATIVE));
            return ret;
        }
    }
}