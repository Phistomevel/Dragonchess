#include "warrior.h"
#include <map>
#include <algorithm>
#include "../moves.h"
#include "../board.h"
namespace game {
    namespace moves {

        Warrior::Warrior() {}
        Warrior::~Warrior() {}
        std::vector<::game::Moves> Warrior::getMovesRaw(::game::Board& board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::Moves> ret;
            if (ActivePiece.getColor()==::game::pieces::Abstract::COLOR_BLACK)
            {
                ret.push_back(::game::Moves( 0,-1,0, "relative"));
            }
            else {
                ret.push_back(::game::Moves( 0, 1, 0, "relative"));
            }
            for (int i = 0; i < ret.size(); i++) {
                if (ret[i].moveType == ::game::Moves::MOVE_RELATIVE) {
                    ret[i].x += ActivePiece.getPosition().x;
                    ret[i].y += ActivePiece.getPosition().y;
                    ret[i].z += ActivePiece.getPosition().z;
                }
            }
            return ret;
        }
        std::vector<::game::moves::Capture> Warrior::getCapturesRaw(::game::Board& board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::moves::Capture> ret;
            if (ActivePiece.getColor() == ::game::pieces::Abstract::COLOR_BLACK)
            {
                ret.push_back(::game::moves::Capture( ::game::Moves( 1,-1, 0, "relative")));
                ret.push_back(::game::moves::Capture( ::game::Moves(-1,-1, 0, "relative")));
            }
            else {
                ret.push_back(::game::moves::Capture( ::game::Moves( 1, 1, 0, "relative")));
                ret.push_back(::game::moves::Capture( ::game::Moves(-1, 1, 0, "relative")));
            }
            return ret;
        }
        std::vector<::game::moves::Capture> Warrior::getThreatsInverted(::game::Board &board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::moves::Capture> ret;
            if (ActivePiece.getColor() != ::game::pieces::Abstract::COLOR_BLACK)
            {
                ret.push_back(::game::moves::Capture(::game::Moves(1, 1, 0, "relative")));
                ret.push_back(::game::moves::Capture(::game::Moves(-1, 1, 0, "relative")));
            }
            else {
                ret.push_back(::game::moves::Capture(::game::Moves(1, -1, 0, "relative")));
                ret.push_back(::game::moves::Capture(::game::Moves(-1, -1, 0, "relative")));
            }
            return ret;
        }
    }
}