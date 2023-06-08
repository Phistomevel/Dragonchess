#include "Unicorn.h"
#include <map>
#include <algorithm>
#include "../moves.h"
namespace game {
    namespace moves {

        Unicorn::Unicorn() {}
        Unicorn::~Unicorn() {}
        std::vector<::game::Moves> Unicorn::getMoves(::game::Board board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::Moves> ret;
            ret.push_back(::game::Moves(-2, 1,0,"relative"));
            ret.push_back(::game::Moves( 2, 1,0,"relative"));
            ret.push_back(::game::Moves(-2,-1,0,"relative"));
            ret.push_back(::game::Moves( 2,-1,0,"relative"));
            ret.push_back(::game::Moves(-1, 2, 0, "relative"));
            ret.push_back(::game::Moves( 1, 2, 0, "relative"));
            ret.push_back(::game::Moves(-1,-2, 0, "relative"));
            ret.push_back(::game::Moves( 1,-2, 0, "relative"));
            for (int i = 0; i < ret.size(); i++) {//auto currMove : ret
                if (ret[i].moveType == ::game::Moves::MOVE_RELATIVE) {
                    ret[i].x += ActivePiece.getPosition().x;
                    ret[i].y += ActivePiece.getPosition().y;
                    ret[i].z += ActivePiece.getPosition().z;
                }
                if (!((ret[i].x >= 0 && ret[i].x < 12)
                    && (ret[i].y >= 0 && ret[i].y < 8)
                    && (ret[i].z >= 0 && ret[i].z < 3))) {
                    ret.erase(ret.begin() + i);
                    i--;
                }
                else {
                    if (board.getPieceByField(ret[i].x, ret[i].y, ret[i].z).getType() != ::game::pieces::Abstract::UNDEFINED) {
                        ret.erase(ret.begin() + i);
                        i--;
                    }
                }
            }
            return ret;
        }
        std::vector<::game::moves::Capture> Unicorn::getCaptures(::game::Board board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::moves::Capture> ret;
            ret.push_back(::game::moves::Capture(::game::Moves(-2, 1, 0, "relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(2, 1, 0, "relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(-2, -1, 0, "relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(2, -1, 0, "relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(-1, 2, 0, "relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(1, 2, 0, "relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(-1, -2, 0, "relative")));
            ret.push_back(::game::moves::Capture(::game::Moves(1, -2, 0, "relative")));
            for (int i = 0; i < ret.size(); i++) {//auto currMove : ret
                if (ret[i].move.moveType == ::game::Moves::MOVE_RELATIVE) {
                    ret[i].move.x += ActivePiece.getPosition().x;
                    ret[i].move.y += ActivePiece.getPosition().y;
                    ret[i].move.z += ActivePiece.getPosition().z;
                    ret[i].capture.x += ActivePiece.getPosition().x;
                    ret[i].capture.y += ActivePiece.getPosition().y;
                    ret[i].capture.z += ActivePiece.getPosition().z;
                }
                if (!(
                    ret[i].move.x >= 0 && ret[i].move.x < 12
                    && ret[i].move.y >= 0 && ret[i].move.y < 8
                    && ret[i].move.z >= 0 && ret[i].move.z < 3)
                    ) {
                    ret.erase(ret.begin() + i);
                    i--;
                }
                else {
                    if (board.getPieceByField(ret[i].capture.x, ret[i].capture.y, ret[i].capture.z).getColor() == ActivePiece.getColor() || board.getPieceByField(ret[i].capture.x, ret[i].capture.y, ret[i].capture.z).getType() == game::pieces::Abstract::UNDEFINED) {
                        ret.erase(ret.begin() + i);
                        i--;
                    }
                }
            }
            return ret;
        }

    }
}