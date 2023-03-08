#include "moves.h"
namespace game {
		Moves::Moves(int x , int y , int z , std::string moveType) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->moveType = moveType;
		}
		Moves::~Moves(){}
		const std::string Moves::MOVE_RELATIVE="relative";
		const std::string Moves::MOVE_ABSOLUTE="absolute";
		const std::string Moves::MOVE_UNDEFINED="UNDEFINED";

	
}
