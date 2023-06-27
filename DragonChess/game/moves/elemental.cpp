#include "elemental.h"
#include <map>
#include <algorithm>
#include "../moves.h"
#include "../board.h"
namespace game {
    namespace moves {

        Elemental::Elemental() {}
        Elemental::~Elemental() {}
        std::vector<::game::Moves> Elemental::getMovesRaw(::game::Board board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::Moves> ret;
            if (ActivePiece.getPosition().z == 0)
            {
                int i = 1;
                while (i + ActivePiece.getPosition().x < 12&& i<=2) {
                    if (board.getPieceByField(i + ActivePiece.getPosition().x, ActivePiece.getPosition().y, 0).getType() == ::game::pieces::Abstract::UNDEFINED) {
                        ret.push_back(::game::Moves(1 * i, 0, 0, ::game::Moves::MOVE_RELATIVE));
                    }
                    else {
                        break;
                    }
                    i++;
                }
                i = 1;
                while (-i + ActivePiece.getPosition().x >=0 && i <= 2) {
                    if (board.getPieceByField(-i + ActivePiece.getPosition().x, ActivePiece.getPosition().y, 0).getType() == ::game::pieces::Abstract::UNDEFINED) {
                        ret.push_back(::game::Moves(-1 * i, 0, 0, ::game::Moves::MOVE_RELATIVE));
                    }
                    else {
                        break;
                    }
                    i++;
                }
                i = 1;
                while (i + ActivePiece.getPosition().y < 8 && i <= 2) {
                    if (board.getPieceByField(ActivePiece.getPosition().x, i + ActivePiece.getPosition().y, 0).getType() == ::game::pieces::Abstract::UNDEFINED) {
                        ret.push_back(::game::Moves(0, 1 * i,  0, ::game::Moves::MOVE_RELATIVE));
                    }
                    else {
                        break;
                    }
                    i++;
                }
                i = 1;
                while (-i + ActivePiece.getPosition().y >=0 && i <= 2) {
                    if (board.getPieceByField(ActivePiece.getPosition().x, -i + ActivePiece.getPosition().y, 0).getType() == ::game::pieces::Abstract::UNDEFINED) {
                        ret.push_back(::game::Moves(0, -1 * i, 0, ::game::Moves::MOVE_RELATIVE));
                    }
                    else {
                        break;
                    }
                    i++;
                }
                if (ActivePiece.getPosition().x-1>=0) {
                    if (board.getPieceByField(ActivePiece.getPosition().x - 1, ActivePiece.getPosition().y, ActivePiece.getPosition().z)) {
                        ret.push_back(::game::Moves(-1,0,1,::game::Moves::MOVE_RELATIVE));
                    }
                }
                if (ActivePiece.getPosition().y- 1 >= 0) {
                    if (board.getPieceByField(ActivePiece.getPosition().x, ActivePiece.getPosition().y-1, ActivePiece.getPosition().z)) {
                        ret.push_back(::game::Moves(0, -1, 1, ::game::Moves::MOVE_RELATIVE));
                    }
                }
                if (ActivePiece.getPosition().x + 1 <12) {
                    if (board.getPieceByField(ActivePiece.getPosition().x + 1, ActivePiece.getPosition().y, ActivePiece.getPosition().z)) {
                        ret.push_back(::game::Moves(1, 0, 1, ::game::Moves::MOVE_RELATIVE));
                    }
                }
                if (ActivePiece.getPosition().y + 1 <8) {
                    if (board.getPieceByField(ActivePiece.getPosition().x, ActivePiece.getPosition().y + 1, ActivePiece.getPosition().z)) {
                        ret.push_back(::game::Moves(0, 1, 1, ::game::Moves::MOVE_RELATIVE));
                    }
                }

                ret.push_back(::game::Moves(1,1,0,::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(1,-1,0,::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-1,1,0,::game::Moves::MOVE_RELATIVE));
                ret.push_back(::game::Moves(-1,-1,0,::game::Moves::MOVE_RELATIVE));
            }
            else
            {
                if (board.getPieceByField(ActivePiece.getPosition().x, ActivePiece.getPosition().y, ActivePiece.getPosition().z-1 ).getType()==::game::pieces::Abstract::UNDEFINED) {
                    ret.push_back(::game::Moves(0, 1, -1, ::game::Moves::MOVE_RELATIVE));
                    ret.push_back(::game::Moves(0, -1, -1, ::game::Moves::MOVE_RELATIVE));
                    ret.push_back(::game::Moves(1, 0, -1, ::game::Moves::MOVE_RELATIVE));
                    ret.push_back(::game::Moves(-1, 0, -1, ::game::Moves::MOVE_RELATIVE));
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
        std::vector<::game::moves::Capture> Elemental::getCapturesRaw(::game::Board board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::moves::Capture> ret;
            if (ActivePiece.getPosition().z == 0)
            {
                int i = 1;
                while (i + ActivePiece.getPosition().x < 12 && i <= 2) {
                    if (board.getPieceByField(i + ActivePiece.getPosition().x, ActivePiece.getPosition().y, 0).getType() == ::game::pieces::Abstract::UNDEFINED) {
                        ret.push_back(::game::Moves(1 * i, 0, 0, ::game::Moves::MOVE_RELATIVE));
                    }
                    else {
                        break;
                    }
                    i++;
                }
                i = 1;
                while (-i + ActivePiece.getPosition().x >=0 && i <= 2) {
                    if (board.getPieceByField(-i + ActivePiece.getPosition().x, ActivePiece.getPosition().y, 0).getType() == ::game::pieces::Abstract::UNDEFINED) {
                        ret.push_back(::game::Moves(-1 * i, 0, 0, ::game::Moves::MOVE_RELATIVE));
                    }
                    else {
                        break;
                    }
                    i++;
                }
                i = 1;
                while (i + ActivePiece.getPosition().y < 8 && i <= 2) {
                    if (board.getPieceByField(ActivePiece.getPosition().x, i + ActivePiece.getPosition().y, 0).getType() == ::game::pieces::Abstract::UNDEFINED) {
                        ret.push_back(::game::Moves(0, 1 * i, 0, ::game::Moves::MOVE_RELATIVE));
                    }
                    else {
                        break;
                    }
                    i++;
                }
                i = 1;
                while (-i + ActivePiece.getPosition().y >=0 && i <= 2) {
                    if (board.getPieceByField(ActivePiece.getPosition().x, -i + ActivePiece.getPosition().y, 0).getType() == ::game::pieces::Abstract::UNDEFINED) {
                        ret.push_back(::game::Moves(0, -1 * i, 0, ::game::Moves::MOVE_RELATIVE));
                    }
                    else {
                        break;
                    }
                    i++;
                }
                if (ActivePiece.getPosition().x - 1 >= 0) {
                    if (board.getPieceByField(ActivePiece.getPosition().x - 1, ActivePiece.getPosition().y, ActivePiece.getPosition().z)) {
                        ret.push_back(::game::Moves(-1, 0, 1, ::game::Moves::MOVE_RELATIVE));
                    }
                }
                if (ActivePiece.getPosition().y - 1 >= 0) {
                    if (board.getPieceByField(ActivePiece.getPosition().x, ActivePiece.getPosition().y - 1, ActivePiece.getPosition().z)) {
                        ret.push_back(::game::Moves(0, -1, 1, ::game::Moves::MOVE_RELATIVE));
                    }
                }
                if (ActivePiece.getPosition().x + 1 < 12) {
                    if (board.getPieceByField(ActivePiece.getPosition().x + 1, ActivePiece.getPosition().y, ActivePiece.getPosition().z)) {
                        ret.push_back(::game::Moves(1, 0, 1, ::game::Moves::MOVE_RELATIVE));
                    }
                }
                if (ActivePiece.getPosition().y + 1 < 8) {
                    if (board.getPieceByField(ActivePiece.getPosition().x, ActivePiece.getPosition().y + 1, ActivePiece.getPosition().z)) {
                        ret.push_back(::game::Moves(0, 1, 1, ::game::Moves::MOVE_RELATIVE));
                    }
                }
            }
            else
            {
                if (board.getPieceByField(ActivePiece.getPosition().x, ActivePiece.getPosition().y, ActivePiece.getPosition().z - 1).getType() == ::game::pieces::Abstract::UNDEFINED) {
                    ret.push_back(::game::Moves(0, 1, -1, ::game::Moves::MOVE_RELATIVE));
                    ret.push_back(::game::Moves(0, -1, -1, ::game::Moves::MOVE_RELATIVE));
                    ret.push_back(::game::Moves(1, 0, -1, ::game::Moves::MOVE_RELATIVE));
                    ret.push_back(::game::Moves(-1, 0, -1, ::game::Moves::MOVE_RELATIVE));
                }
            }



            return ret;
        }
        std::vector<::game::moves::Capture> Elemental::getThreatsInverted(::game::Board board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::moves::Capture> ret;
            
            if (ActivePiece.getPosition().z==1) {
                if (ActivePiece.getPosition().x - 1 >= 0) {
                    if (board.getPieceByField(ActivePiece.getPosition().x - 1, ActivePiece.getPosition().y, ActivePiece.getPosition().z)) {
                        ret.push_back(::game::Moves(-1, 0, -1, ::game::Moves::MOVE_RELATIVE));
                    }
                }
                if (ActivePiece.getPosition().y - 1 >= 0) {
                    if (board.getPieceByField(ActivePiece.getPosition().x, ActivePiece.getPosition().y - 1, ActivePiece.getPosition().z)) {
                        ret.push_back(::game::Moves(0, -1, -1, ::game::Moves::MOVE_RELATIVE));
                    }
                }
                if (ActivePiece.getPosition().x + 1 < 12) {
                    if (board.getPieceByField(ActivePiece.getPosition().x + 1, ActivePiece.getPosition().y, ActivePiece.getPosition().z)) {
                        ret.push_back(::game::Moves(1, 0, -1, ::game::Moves::MOVE_RELATIVE));
                    }
                }
                if (ActivePiece.getPosition().y + 1 < 8) {
                    if (board.getPieceByField(ActivePiece.getPosition().x, ActivePiece.getPosition().y + 1, ActivePiece.getPosition().z)) {
                        ret.push_back(::game::Moves(0, 1, -1, ::game::Moves::MOVE_RELATIVE));
                    }
                }
            }
            if (ActivePiece.getPosition().z == 0) {
                int i = 1;
                while (i + ActivePiece.getPosition().x < 12 && i <= 2) {
                    if (board.getPieceByField(i + ActivePiece.getPosition().x, ActivePiece.getPosition().y, 0).getType() == ::game::pieces::Abstract::UNDEFINED) {
                        ret.push_back(::game::Moves(1 * i, 0, 0, ::game::Moves::MOVE_RELATIVE));
                    }
                    else {
                        break;
                    }
                    i++;
                }
                i = 1;
                while (-i + ActivePiece.getPosition().x >= 0 && i <= 2) {
                    if (board.getPieceByField(-i + ActivePiece.getPosition().x, ActivePiece.getPosition().y, 0).getType() == ::game::pieces::Abstract::UNDEFINED) {
                        ret.push_back(::game::Moves(-1 * i, 0, 0, ::game::Moves::MOVE_RELATIVE));
                    }
                    else {
                        break;
                    }
                    i++;
                }
                i = 1;
                while (i + ActivePiece.getPosition().y < 8 && i <= 2) {
                    if (board.getPieceByField(ActivePiece.getPosition().x, i + ActivePiece.getPosition().y, 0).getType() == ::game::pieces::Abstract::UNDEFINED) {
                        ret.push_back(::game::Moves(0, 1 * i, 0, ::game::Moves::MOVE_RELATIVE));
                    }
                    else {
                        break;
                    }
                    i++;
                }
                i = 1;
                while (-i + ActivePiece.getPosition().y >= 0 && i <= 2) {
                    if (board.getPieceByField(ActivePiece.getPosition().x, -i + ActivePiece.getPosition().y, 0).getType() == ::game::pieces::Abstract::UNDEFINED) {
                        ret.push_back(::game::Moves(0, -1 * i, 0, ::game::Moves::MOVE_RELATIVE));
                    }
                    else {
                        break;
                    }
                    i++;
                }
                if (ActivePiece.getPosition().x - 1 >= 0) {
                    if (board.getPieceByField(ActivePiece.getPosition().x - 1, ActivePiece.getPosition().y, ActivePiece.getPosition().z)) {
                        ret.push_back(::game::Moves(-1, 0, 1, ::game::Moves::MOVE_RELATIVE));
                    }
                }
                if (ActivePiece.getPosition().y - 1 >= 0) {
                    if (board.getPieceByField(ActivePiece.getPosition().x, ActivePiece.getPosition().y - 1, ActivePiece.getPosition().z)) {
                        ret.push_back(::game::Moves(0, -1, 1, ::game::Moves::MOVE_RELATIVE));
                    }
                }
                if (ActivePiece.getPosition().x + 1 < 12) {
                    if (board.getPieceByField(ActivePiece.getPosition().x + 1, ActivePiece.getPosition().y, ActivePiece.getPosition().z)) {
                        ret.push_back(::game::Moves(1, 0, 1, ::game::Moves::MOVE_RELATIVE));
                    }
                }
                if (ActivePiece.getPosition().y + 1 < 8) {
                    if (board.getPieceByField(ActivePiece.getPosition().x, ActivePiece.getPosition().y + 1, ActivePiece.getPosition().z)) {
                        ret.push_back(::game::Moves(0, 1, 1, ::game::Moves::MOVE_RELATIVE));
                    }
                }
            }
            return ret;
        }
    }
}