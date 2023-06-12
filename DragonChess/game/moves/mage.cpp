#include "Mage.h"
#include <map>
#include <algorithm>
#include "../moves.h"
namespace game {
	namespace moves {

		Mage::Mage() {}
		Mage::~Mage() {}
		std::vector<::game::Moves> Mage::getMoves(::game::Board board, ::game::pieces::Abstract& ActivePiece) {
			std::vector<::game::Moves> ret;
			switch (ActivePiece.getPosition().z)
			{
			case 1: {
				int i = 1;
				while (i + ActivePiece.getPosition().x < 12 && -i + ActivePiece.getPosition().y >= 0) {
					if (board.getPieceByField(i + ActivePiece.getPosition().x, -i + ActivePiece.getPosition().y, 1).getType() == ::game::pieces::Abstract::UNDEFINED) {
						ret.push_back(::game::Moves(1 * i, -1 * i, 0, "relative"));
					}
					else {
						break;
					}
					i++;
				}
				i = 1;
				while (i + ActivePiece.getPosition().x < 12 && i + ActivePiece.getPosition().y < 8) {
					if (board.getPieceByField(i + ActivePiece.getPosition().x, i + ActivePiece.getPosition().y, 1).getType() == ::game::pieces::Abstract::UNDEFINED) {
						ret.push_back(::game::Moves(1 * i, 1 * i, 0, "relative"));
					}
					else {
						break;
					}
					i++;
				}
				i = 1;
				while (-i + ActivePiece.getPosition().x >= 0 && -i + ActivePiece.getPosition().y >= 0) {
					if (board.getPieceByField(-i + ActivePiece.getPosition().x, -i + ActivePiece.getPosition().y, 1).getType() == ::game::pieces::Abstract::UNDEFINED) {
						ret.push_back(::game::Moves(-1 * i, -1 * i, 0, "relative"));
					}
					else {
						break;
					}
					i++;
				}
				i = 1;
				while (-i + ActivePiece.getPosition().x >= 0 && i + ActivePiece.getPosition().y < 8) {
					if (board.getPieceByField(-i + ActivePiece.getPosition().x, i + ActivePiece.getPosition().y, 1).getType() == ::game::pieces::Abstract::UNDEFINED) {
						ret.push_back(::game::Moves(-1 * i, 1 * i, 0, "relative"));
					}
					else {
						break;
					}
					i++;
				}
				i = 1;
				while (i + ActivePiece.getPosition().x < 12 && ActivePiece.getPosition().y >= 0) {
					if (board.getPieceByField(i + ActivePiece.getPosition().x, ActivePiece.getPosition().y, 1).getType() == ::game::pieces::Abstract::UNDEFINED) {
						ret.push_back(::game::Moves(1 * i, 0, 0, "relative"));
					}
					else {
						break;
					}
					i++;
				}
				i = 1;
				while (-i + ActivePiece.getPosition().x >= 0 && ActivePiece.getPosition().y < 8) {
					if (board.getPieceByField(-i + ActivePiece.getPosition().x, ActivePiece.getPosition().y, 1).getType() == ::game::pieces::Abstract::UNDEFINED) {
						ret.push_back(::game::Moves(-1 * i, 0, 0, "relative"));
					}
					else {
						break;
					}
					i++;
				}
				i = 1;
				while (ActivePiece.getPosition().x >= 0 && i + ActivePiece.getPosition().y < 8) {
					if (board.getPieceByField(ActivePiece.getPosition().x, i + ActivePiece.getPosition().y, 1).getType() == ::game::pieces::Abstract::UNDEFINED) {
						ret.push_back(::game::Moves(0, 1 * i, 0, "relative"));
					}
					else {
						break;
					}
					i++;
				}
				i = 1;
				while (ActivePiece.getPosition().x >= 0 && -i + ActivePiece.getPosition().y >= 0) {
					if (board.getPieceByField(ActivePiece.getPosition().x, -i + ActivePiece.getPosition().y, 1).getType() == ::game::pieces::Abstract::UNDEFINED) {
						ret.push_back(::game::Moves(0, -1 * i, 0, "relative"));
					}
					else {
						break;
					}
					i++;
				}
			}
				  break;
			default: {
				ret.push_back(::game::Moves(0, 1, 0, "relative"));
				ret.push_back(::game::Moves(0, -1, 0, "relative"));
				ret.push_back(::game::Moves(1, 0, 0, "relative"));
				ret.push_back(::game::Moves(-1, 0, 0, "relative"));
			}
				   break;
			}


			int i = 1;
			while (i + ActivePiece.getPosition().z < 3) {
				if (board.getPieceByField(ActivePiece.getPosition().x, ActivePiece.getPosition().y, i + ActivePiece.getPosition().z).getType() == ::game::pieces::Abstract::UNDEFINED) {
					ret.push_back(::game::Moves(0, 0, i, "relative"));
				}
				else {
					break;
				}
				i++;
			}
			i = 1;
			while (-i + ActivePiece.getPosition().z >= 0) {
				if (board.getPieceByField(ActivePiece.getPosition().x, ActivePiece.getPosition().y, -i + ActivePiece.getPosition().z).getType() == ::game::pieces::Abstract::UNDEFINED) {
					ret.push_back(::game::Moves(0, 0, -i, "relative"));
				}
				else {
					break;
				}
				i++;
			}
			for (int i = 0; i < ret.size(); i++) {//auto currMove : ret
				if (ret[i].moveType == ::game::Moves::MOVE_RELATIVE) {
					ret[i].x += ActivePiece.getPosition().x;
					ret[i].y += ActivePiece.getPosition().y;
					ret[i].z += ActivePiece.getPosition().z;
					ret[i].moveType = ::game::Moves::MOVE_ABSOLUTE;
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
		std::vector<::game::moves::Capture> Mage::getCaptures(::game::Board board, ::game::pieces::Abstract& ActivePiece) {
			std::vector<::game::moves::Capture> ret;
			switch (ActivePiece.getPosition().z)
			{
			case 1: {
				int i = 1;
				while (i + ActivePiece.getPosition().x < 12 && -i + ActivePiece.getPosition().y >= 0) {
					if (board.getPieceByField(i + ActivePiece.getPosition().x, -i + ActivePiece.getPosition().y, 1).getType() != ::game::pieces::Abstract::UNDEFINED) {
						ret.push_back(::game::moves::Capture(::game::Moves(1 * i, -1 * i, 0, "relative")));
						break;
					}
					i++;
				}
				i = 1;
				while (-i + ActivePiece.getPosition().x >= 0 && -i + ActivePiece.getPosition().y >= 0) {
					if (board.getPieceByField(-i + ActivePiece.getPosition().x, -i + ActivePiece.getPosition().y, 1).getType() != ::game::pieces::Abstract::UNDEFINED) {
						ret.push_back(::game::moves::Capture(::game::Moves(-1 * i, -1 * i, 0, "relative")));
						break;
					}
					i++;
				}
				i = 1;
				while (i + ActivePiece.getPosition().x < 12 && i + ActivePiece.getPosition().y < 8) {
					if (board.getPieceByField(i + ActivePiece.getPosition().x, i + ActivePiece.getPosition().y, 1).getType() != ::game::pieces::Abstract::UNDEFINED) {
						ret.push_back(::game::moves::Capture(::game::Moves(1 * i, 1 * i, 0, "relative")));
						break;
					}
					i++;
				}
				i = 1;
				while (-i + ActivePiece.getPosition().x >= 0 && i + ActivePiece.getPosition().y < 8) {
					if (board.getPieceByField(-i + ActivePiece.getPosition().x, i + ActivePiece.getPosition().y, 1).getType() != ::game::pieces::Abstract::UNDEFINED) {
						ret.push_back(::game::moves::Capture(::game::Moves(-1 * i, 1 * i, 0, "relative")));
						break;
					}
					i++;
				}
				i = 1;
				while (i + ActivePiece.getPosition().x < 12 && ActivePiece.getPosition().y >= 0) {
					if (board.getPieceByField(i + ActivePiece.getPosition().x, ActivePiece.getPosition().y, 1).getType() != ::game::pieces::Abstract::UNDEFINED) {
						ret.push_back(::game::moves::Capture(::game::Moves(1 * i, 0, 0, "relative")));
						break;
					}
					i++;
				}
				i = 1;
				while (-i + ActivePiece.getPosition().x >= 0 && ActivePiece.getPosition().y >= 0) {
					if (board.getPieceByField(-i + ActivePiece.getPosition().x, ActivePiece.getPosition().y, 1).getType() != ::game::pieces::Abstract::UNDEFINED) {
						ret.push_back(::game::moves::Capture(::game::Moves(-1 * i, 0, 0, "relative")));
						break;
					}
					i++;
				}
				i = 1;
				while (ActivePiece.getPosition().x < 12 && i + ActivePiece.getPosition().y < 8) {
					if (board.getPieceByField(ActivePiece.getPosition().x, i + ActivePiece.getPosition().y, 1).getType() != ::game::pieces::Abstract::UNDEFINED) {
						ret.push_back(::game::moves::Capture(::game::Moves(0, 1 * i, 0, "relative")));
						break;
					}
					i++;
				}
				i = 1;
				while (ActivePiece.getPosition().x >= 0 && -i + ActivePiece.getPosition().y >= 0) {
					if (board.getPieceByField(ActivePiece.getPosition().x, -i + ActivePiece.getPosition().y, 1).getType() != ::game::pieces::Abstract::UNDEFINED) {
						ret.push_back(::game::moves::Capture(::game::Moves(0, -1 * i, 0, "relative")));
						break;
					}
					i++;
				}
				break;
			}
			default:
				break;
			}
			
			int i = 1;
			while (i + ActivePiece.getPosition().z < 3) {
				if (board.getPieceByField(ActivePiece.getPosition().x, ActivePiece.getPosition().y, i + ActivePiece.getPosition().z).getType() != ::game::pieces::Abstract::UNDEFINED) {
					ret.push_back(::game::Moves(0, 0, i, "relative"));
					break;
				}
				i++;
			}
			i = 1;
			while (-i + ActivePiece.getPosition().z >= 0) {
				if (board.getPieceByField(ActivePiece.getPosition().x, ActivePiece.getPosition().y, -i + ActivePiece.getPosition().z).getType() != ::game::pieces::Abstract::UNDEFINED) {
					ret.push_back(::game::Moves(0, 0, -i, "relative"));
					break;
				}
				i++;
			}

			for (int i = 0; i < ret.size(); i++) {//auto currMove : ret
				if (ret[i].move.moveType == ::game::Moves::MOVE_RELATIVE) {
					ret[i].move.x += ActivePiece.getPosition().x;
					ret[i].move.y += ActivePiece.getPosition().y;
					ret[i].move.z += ActivePiece.getPosition().z;
					ret[i].move.moveType = ::game::Moves::MOVE_ABSOLUTE;
					ret[i].capture.x += ActivePiece.getPosition().x;
					ret[i].capture.y += ActivePiece.getPosition().y;
					ret[i].capture.z += ActivePiece.getPosition().z;
					ret[i].capture.moveType = ::game::Moves::MOVE_ABSOLUTE;
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