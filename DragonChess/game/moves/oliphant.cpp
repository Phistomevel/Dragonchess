#include "Oliphant.h"
#include <map>
#include <algorithm>
#include "../moves.h"
#include "../board.h"
namespace game {
    namespace moves {

        Oliphant::Oliphant() {}
        Oliphant::~Oliphant() {}
        std::vector<::game::Moves> Oliphant::getMovesRaw(::game::Board board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::Moves> ret;
           
            int i = 1;
            while (i + ActivePiece.getPosition().x < 12 ) {
                if (board.getPieceByField(i + ActivePiece.getPosition().x, ActivePiece.getPosition().y, 1).getType() == ::game::pieces::Abstract::UNDEFINED) {
                    ret.push_back(::game::Moves(1 * i, 0, 0, "relative"));
                }
                else {
                    break;
                }
                i++;
            }
            i = 1;
            while (-i + ActivePiece.getPosition().x >=0 ) {
                if (board.getPieceByField(-i + ActivePiece.getPosition().x, ActivePiece.getPosition().y, 1).getType() == ::game::pieces::Abstract::UNDEFINED) {
                    ret.push_back(::game::Moves(-1 * i, 0, 0, "relative"));
                }
                else {
                    break;
                }
                i++;
            }
            i = 1;
            while ( i + ActivePiece.getPosition().y<8) {
                if (board.getPieceByField(ActivePiece.getPosition().x, i + ActivePiece.getPosition().y, 1).getType() == ::game::pieces::Abstract::UNDEFINED) {
                    ret.push_back(::game::Moves(0, 1 * i, 0, "relative"));
                }
                else {
                    break;
                }
                i++;
            }
            i = 1;
            while ( -i + ActivePiece.getPosition().y >=0) {
                if (board.getPieceByField(ActivePiece.getPosition().x, -i + ActivePiece.getPosition().y, 1).getType() == ::game::pieces::Abstract::UNDEFINED) {
                    ret.push_back(::game::Moves(0, -1 * i, 0, "relative"));
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
        std::vector<::game::moves::Capture> Oliphant::getCapturesRaw(::game::Board board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::moves::Capture> ret;
           
            int i = 1;
            while (i + ActivePiece.getPosition().x < 12 &&  ActivePiece.getPosition().y >= 0) {
                ret.push_back(::game::moves::Capture(::game::Moves(1 * i, 0, 0, "relative")));
                if (board.getPieceByField(i + ActivePiece.getPosition().x,  ActivePiece.getPosition().y, 1).getType() != ::game::pieces::Abstract::UNDEFINED) {
                    
                    break;
                }
                i++;
            }
            i = 1;
            while (-i + ActivePiece.getPosition().x >= 0 &&  ActivePiece.getPosition().y >= 0) {
                ret.push_back(::game::moves::Capture(::game::Moves(-1 * i, 0, 0, "relative")));
                if (board.getPieceByField(-i + ActivePiece.getPosition().x,  ActivePiece.getPosition().y, 1).getType() != ::game::pieces::Abstract::UNDEFINED) {
                    
                    break;
                }
                i++;
            }
            i = 1;
            while (ActivePiece.getPosition().x < 12 && i + ActivePiece.getPosition().y < 8) {
                ret.push_back(::game::moves::Capture(::game::Moves(0, 1 * i, 0, "relative")));
                if (board.getPieceByField(ActivePiece.getPosition().x, i + ActivePiece.getPosition().y, 1).getType() != ::game::pieces::Abstract::UNDEFINED) {
                    
                    break;
                }
                i++;
            }
            i = 1;
            while (ActivePiece.getPosition().x >= 0 && -i + ActivePiece.getPosition().y >=0) {
                ret.push_back(::game::moves::Capture(::game::Moves(0, -1 * i, 0, "relative")));
                if (board.getPieceByField(ActivePiece.getPosition().x, -i + ActivePiece.getPosition().y, 1).getType() != ::game::pieces::Abstract::UNDEFINED) {
                    
                    break;
                }
                i++;
            }


            return ret;
        }
        std::vector<::game::moves::Capture> Oliphant::getThreatsInverted(::game::Board board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::moves::Capture> ret;
            if (ActivePiece.getPosition().z==1)
            {
                int i = 1;
                while (i + ActivePiece.getPosition().x < 12 && ActivePiece.getPosition().y >= 0) {
                    ret.push_back(::game::moves::Capture(::game::Moves(1 * i, 0, 0, "relative")));
                    if (board.getPieceByField(i + ActivePiece.getPosition().x, ActivePiece.getPosition().y, 1).getType() != ::game::pieces::Abstract::UNDEFINED) {

                        break;
                    }
                    i++;
                }
                i = 1;
                while (-i + ActivePiece.getPosition().x >= 0 && ActivePiece.getPosition().y >= 0) {
                    ret.push_back(::game::moves::Capture(::game::Moves(-1 * i, 0, 0, "relative")));
                    if (board.getPieceByField(-i + ActivePiece.getPosition().x, ActivePiece.getPosition().y, 1).getType() != ::game::pieces::Abstract::UNDEFINED) {

                        break;
                    }
                    i++;
                }
                i = 1;
                while (ActivePiece.getPosition().x < 12 && i + ActivePiece.getPosition().y < 8) {
                    ret.push_back(::game::moves::Capture(::game::Moves(0, 1 * i, 0, "relative")));
                    if (board.getPieceByField(ActivePiece.getPosition().x, i + ActivePiece.getPosition().y, 1).getType() != ::game::pieces::Abstract::UNDEFINED) {

                        break;
                    }
                    i++;
                }
                i = 1;
                while (ActivePiece.getPosition().x >= 0 && -i + ActivePiece.getPosition().y >= 0) {
                    ret.push_back(::game::moves::Capture(::game::Moves(0, -1 * i, 0, "relative")));
                    if (board.getPieceByField(ActivePiece.getPosition().x, -i + ActivePiece.getPosition().y, 1).getType() != ::game::pieces::Abstract::UNDEFINED) {

                        break;
                    }
                    i++;
                }
            }
            return ret;
        }
    }
}