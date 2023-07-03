#include "abstract.h"
#include "../board.h"
namespace game {
	namespace moves {
#pragma message("including game::moves::Abstract")
		Abstract::Abstract() {}
		Abstract::~Abstract() {}
        std::vector<::game::Moves> Abstract::getMoves(::game::Board &board, ::game::pieces::Abstract& ActivePiece) {
			std::vector<::game::Moves> ret = this->getMovesRaw(board, ActivePiece);
            for (int i = 0; i < ret.size(); i++) {//auto currMove : ret
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
		std::vector<::game::moves::Capture> Abstract::getCaptures(::game::Board &board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::moves::Capture> ret = getCapturesRaw(board, ActivePiece);
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
                    && ret[i].move.z >= 0 && ret[i].move.z < 3)||
                    !(
                    ret[i].capture.x >= 0 && ret[i].capture.x < 12
                    && ret[i].capture.y >= 0 && ret[i].capture.y < 8
                    && ret[i].capture.z >= 0 && ret[i].capture.z < 3)
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