#include <map>
#include <algorithm>
#include "sylph.h"
#include "../moves.h"
#include "abstract.h"
#include "../board.h"
namespace game {
    namespace moves {
        
        Sylph::Sylph() {}
        Sylph::~Sylph() {}
        std::vector<::game::Moves> Sylph::getMovesRaw(::game::Board &board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::Moves> ret;
            if (ActivePiece.getColor()==game::pieces::Abstract::COLOR_BLACK) {
                switch (ActivePiece.getPosition().z)
                {
                case 2:
                    {
                         ret.push_back(game::Moves(-1, -1, +0, "relative"));
                         ret.push_back(game::Moves(+1, -1, +0, "relative"));
                         ret.push_back(game::Moves(+0, +0, -1, "relative"));
                    }
                    break;
                case 1:
                    {
                        ret.push_back(game::Moves( 0, 0,  1, "relative"));
                        ret.push_back(game::Moves( 0, 6, 2, "absolute"));
                        ret.push_back(game::Moves( 2, 6, 2, "absolute"));
                        ret.push_back(game::Moves( 4, 6, 2, "absolute"));
                        ret.push_back(game::Moves( 6, 6, 2, "absolute"));
                        ret.push_back(game::Moves( 8, 6, 2, "absolute"));
                        ret.push_back(game::Moves(10, 6, 2, "absolute"));
                    }
                    break;
                case 0:
                    break;
                default:
                    break;
                }  
            }
            else {
                switch (ActivePiece.getPosition().z)
                {
                case 2:
                {
                    ret.push_back(game::Moves(-1, +1, +0, "relative"));
                    ret.push_back(game::Moves(+1, +1, +0, "relative"));
                    ret.push_back(game::Moves(+0, +0, -1, "relative"));
                }
                break;
                case 1:
                {
                    ret.push_back(game::Moves( 0, 0, 1, "relative"));
                    ret.push_back(game::Moves( 0, 1, 2, "absolute"));
                    ret.push_back(game::Moves( 2, 1, 2, "absolute"));
                    ret.push_back(game::Moves( 4, 1, 2, "absolute"));
                    ret.push_back(game::Moves( 6, 1, 2, "absolute"));
                    ret.push_back(game::Moves( 8, 1, 2, "absolute"));
                    ret.push_back(game::Moves(10, 1, 2, "absolute"));
                }
                break;
                case 0:
                    break;
                default:
                    break;
                }
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
        std::vector<::game::moves::Capture> Sylph::getCapturesRaw(::game::Board &board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::moves::Capture> ret;
            if (ActivePiece.getColor()==::game::pieces::Abstract::COLOR_BLACK) {
                switch (ActivePiece.getPosition().z)
                {
                case 2:
                {
                    ret.push_back(game::moves::Capture(::game::Moves(0, -1, 0, "relative")));
                    ret.push_back(game::moves::Capture(::game::Moves(0, 0, -1, "relative")));
                }
                break;
                case 1:
                    break;
                case 0:
                    break;
                default:
                    break;
                }
            }
            else {
                switch (ActivePiece.getPosition().z)
                {
                case 2:
                {
                    ret.push_back(game::moves::Capture(::game::Moves(0, 1,  0, "relative")));
                    ret.push_back(game::moves::Capture(::game::Moves(0, 0, -1, "relative")));
                }
                break;
                case 1:
                    break;
                case 0:
                    break;
                default:
                    break;
                }
            }
            return ret;
        }
        
        std::vector<::game::moves::Capture> Sylph::getThreatsInverted(::game::Board &board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::moves::Capture> ret;
            if (ActivePiece.getColor() == ::game::pieces::Abstract::COLOR_BLACK) {
                switch (ActivePiece.getPosition().z)
                {
                case 1:
                {
                    ret.push_back(game::moves::Capture(::game::Moves(0, 1, 0, "relative")));
                    ret.push_back(game::moves::Capture(::game::Moves(0, 0, 1, "relative")));
                }
                break;
                case 2:
                {
                    ret.push_back(game::moves::Capture(::game::Moves(0, -1, 0, "relative"), ::game::Moves(0, -1, 0, "relative")));
                }
                    break;
                case 0:
                    break;
                default:
                    break;
                }
            }
            else {
                switch (ActivePiece.getPosition().z)
                {
                case 1:
                {
                    
                    ret.push_back(game::moves::Capture(::game::Moves(0, -1, 0, "relative")));
                    ret.push_back(game::moves::Capture(::game::Moves(0, 0, 1, "relative")));
                }
                break;
                case 2:
                {

                    ret.push_back(game::moves::Capture(::game::Moves(0, 1, 0, "relative"), ::game::Moves(0, 1, 0, "relative")));
                }
                    break;
                case 0:
                    break;
                default:
                    break;
                }
            }
            return ret;
        }
    }
}