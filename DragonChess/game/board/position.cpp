#include "position.h"
namespace game {
	namespace board {
		bool operator<(const ::game::board::Position& a, const ::game::board::Position& b) {
			return (a.x * 2 + a.y * 3 + a.z * 5 < b.x * 2 + b.y * 3 + b.z * 5);
		}
			Position::Position(int x, int y, int z){
				this->x = x;
				this->y = y;
				this->z = z;
			}
			Position::~Position(){}
//			bool Position::operator<(::game::board::Position& other) {
//				return (this->x*2+this->y*3+this->z*5<other.x*2+other.y*3+other.z*5);
//			}
			int x, y, z;
	}
}
