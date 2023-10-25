#include <map>
#include "dragon.h"
#include "../moves.h"
#include "abstract.h"
#include "../board.h"
namespace game {
    namespace moves {
        
        Dragon::~Dragon() {}
        std::vector<::game::Moves> Dragon::getMovesRaw(::game::Board &board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::Moves> ret;
            ret.push_back(::game::Moves( 1, 0,0,"relative"));
            ret.push_back(::game::Moves(-1, 0,0,"relative"));
            ret.push_back(::game::Moves( 0, 1,0,"relative"));
            ret.push_back(::game::Moves( 0,-1,0,"relative"));
            int i = 1;
            while (i+ActivePiece.getPosition().x<12&&-i+ActivePiece.getPosition().y>=0) {
                if (board.getPieceByField(i + ActivePiece.getPosition().x,-i + ActivePiece.getPosition().y,2).getType()==::game::pieces::Abstract::UNDEFINED) {
                    ret.push_back(::game::Moves(1 * i, -1 * i, 0, "relative"));
                }
                else {
                    break;
                }
                i++;
            }
            i = 1;
            while (i + ActivePiece.getPosition().x < 12 && i + ActivePiece.getPosition().y <8) {
                if (board.getPieceByField(i + ActivePiece.getPosition().x, i + ActivePiece.getPosition().y, 2).getType() == ::game::pieces::Abstract::UNDEFINED) {
                    ret.push_back(::game::Moves(1 * i, 1 * i, 0, "relative"));
                }
                else {
                    break;
                }
                i++;
            }
            i = 1;
            while (-i + ActivePiece.getPosition().x >=0 && -i + ActivePiece.getPosition().y >= 0) {
                if (board.getPieceByField(-i + ActivePiece.getPosition().x, -i + ActivePiece.getPosition().y, 2).getType() == ::game::pieces::Abstract::UNDEFINED) {
                    ret.push_back(::game::Moves(-1 * i, -1 * i, 0, "relative"));
                }
                else {
                    break;
                }
                i++;
            }
            i = 1;
            while (-i + ActivePiece.getPosition().x >=0 && i + ActivePiece.getPosition().y <8) {
                if (board.getPieceByField(-i + ActivePiece.getPosition().x, i + ActivePiece.getPosition().y, 2).getType() == ::game::pieces::Abstract::UNDEFINED) {
                    ret.push_back(::game::Moves(-1 * i, 1 * i, 0, "relative"));
                }
                else {
                    break;
                }
                i++;
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
        std::vector<::game::moves::Capture> Dragon::getCapturesRaw(::game::Board &board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::moves::Capture> ret; 
            ret.push_back(::game::moves::Capture(::game::Moves(1, 0, 0, "relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(-1, 0, 0, "relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(0, 1, 0, "relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(0, -1, 0, "relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(0, 0, 0, "relative"),game::Moves(0,0,-1,"relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(0, 0, 0, "relative"),game::Moves(1,0,-1,"relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(0, 0, 0, "relative"),game::Moves(-1,0,-1,"relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(0, 0, 0, "relative"),game::Moves(0,1,-1,"relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(0, 0, 0, "relative"),game::Moves(0,-1,-1,"relative")));
            int i = 1;
            while (i + ActivePiece.getPosition().x < 12 && -i + ActivePiece.getPosition().y >= 0) {
                ret.push_back(::game::moves::Capture(::game::Moves(1 * i, -1 * i, 0, "relative")));
                if (board.getPieceByField(i + ActivePiece.getPosition().x, -i + ActivePiece.getPosition().y, 2).getType() != ::game::pieces::Abstract::UNDEFINED) {
                    break;
                }
                i++;
            }
            i = 1;
            while (-i + ActivePiece.getPosition().x >=0 && -i + ActivePiece.getPosition().y >= 0) {
                ret.push_back(::game::moves::Capture(::game::Moves(-1 * i, -1 * i, 0, "relative")));
                if (board.getPieceByField(-i + ActivePiece.getPosition().x, -i + ActivePiece.getPosition().y, 2).getType() != ::game::pieces::Abstract::UNDEFINED) {
                    break;
                }
                i++;
            }
            i = 1;
            while (i + ActivePiece.getPosition().x < 12 && i + ActivePiece.getPosition().y <8) {
                ret.push_back(::game::moves::Capture(::game::Moves(1 * i, 1 * i, 0, "relative")));
                if (board.getPieceByField(i + ActivePiece.getPosition().x, i + ActivePiece.getPosition().y, 2).getType() != ::game::pieces::Abstract::UNDEFINED) {
                    break;
                }
                i++;
            }
            i = 1;
            while (-i + ActivePiece.getPosition().x >=0 && i + ActivePiece.getPosition().y <8) {
                ret.push_back(::game::moves::Capture(::game::Moves(-1 * i, 1 * i, 0, "relative")));
                if (board.getPieceByField(-i + ActivePiece.getPosition().x, i + ActivePiece.getPosition().y, 2).getType() != ::game::pieces::Abstract::UNDEFINED) {
                    break;
                }
                i++;
            }
            return ret;
        }
        std::vector<::game::moves::Capture> Dragon::getThreatsInverted(::game::Board& board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::moves::Capture> ret;
            if (ActivePiece.getPosition().z==1)
            {
                ret.push_back(::game::moves::Capture(::game::Moves(0, 0, 0, "relative"), game::Moves(0, 0, 1, "relative")));
                ret.push_back(::game::moves::Capture(::game::Moves(0, 0, 0, "relative"), game::Moves(1, 0, 1, "relative")));
                ret.push_back(::game::moves::Capture(::game::Moves(0, 0, 0, "relative"), game::Moves(-1, 0, 1, "relative")));
                ret.push_back(::game::moves::Capture(::game::Moves(0, 0, 0, "relative"), game::Moves(0, 1, 1, "relative")));
                ret.push_back(::game::moves::Capture(::game::Moves(0, 0, 0, "relative"), game::Moves(0, -1, 1, "relative")));
            }
            if (ActivePiece.getPosition().z == 2) {
                ret.push_back(::game::moves::Capture(::game::Moves(1, 0, 0, "relative")));
                ret.push_back(::game::moves::Capture(::game::Moves(-1, 0, 0, "relative")));
                ret.push_back(::game::moves::Capture(::game::Moves(0, 1, 0, "relative")));
                ret.push_back(::game::moves::Capture(::game::Moves(0, -1, 0, "relative")));
                int i = 1;
                while (i + ActivePiece.getPosition().x < 12 && -i + ActivePiece.getPosition().y >= 0) {
                    ret.push_back(::game::moves::Capture(::game::Moves(1 * i, -1 * i, 0, "relative")));
                    if (board.getPieceByField(i + ActivePiece.getPosition().x, -i + ActivePiece.getPosition().y, 2).getType() != ::game::pieces::Abstract::UNDEFINED) {
                        break;
                    }
                    i++;
                }
                i = 1;
                while (-i + ActivePiece.getPosition().x >= 0 && -i + ActivePiece.getPosition().y >= 0) {
                    ret.push_back(::game::moves::Capture(::game::Moves(-1 * i, -1 * i, 0, "relative")));
                    if (board.getPieceByField(-i + ActivePiece.getPosition().x, -i + ActivePiece.getPosition().y, 2).getType() != ::game::pieces::Abstract::UNDEFINED) {
                        break;
                    }
                    i++;
                }
                i = 1;
                while (i + ActivePiece.getPosition().x < 12 && i + ActivePiece.getPosition().y < 8) {
                    ret.push_back(::game::moves::Capture(::game::Moves(1 * i, 1 * i, 0, "relative")));
                    if (board.getPieceByField(i + ActivePiece.getPosition().x, i + ActivePiece.getPosition().y, 2).getType() != ::game::pieces::Abstract::UNDEFINED) {
                        break;
                    }
                    i++;
                }
                i = 1;
                while (-i + ActivePiece.getPosition().x >= 0 && i + ActivePiece.getPosition().y < 8) {
                    ret.push_back(::game::moves::Capture(::game::Moves(-1 * i, 1 * i, 0, "relative")));
                    if (board.getPieceByField(-i + ActivePiece.getPosition().x, i + ActivePiece.getPosition().y, 2).getType() != ::game::pieces::Abstract::UNDEFINED) {
                        break;
                    }
                    i++;
                }
            }
            return ret;
        }
    }
}