#include "moves.h"
namespace game {
		Moves::Moves(int x , int y , int z , std::string moveType) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->moveType = moveType;
		}
		bool Moves::operator==(const Moves& other) const {
			if (this->x != other.x) {
				return false;
			}
			if (this->y != other.y) {
				return false;
			}
			if (this->z != other.z) {
				return false;
			}
			return true;
		}
		bool Moves::operator>(const Moves& other) const {
			if (this->x>other.x|| this->y > other.y|| this->z > other.z) {
				return true;
			}
			return false;
		}
		bool Moves::operator<(const Moves& other) const {
			if (this->x < other.x || this->y < other.y || this->z < other.z) {
				return true;
			}
			return false;
		}
		Moves::~Moves(){}
		const std::string Moves::MOVE_RELATIVE="relative";
		const std::string Moves::MOVE_ABSOLUTE="absolute";
		const std::string Moves::MOVE_UNDEFINED="UNDEFINED";

	
}
