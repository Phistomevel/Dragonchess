#include "position.h"
namespace game {
	namespace board {
			Position::Position(int x, int y, int z){
				this->x = x;
				this->y = y;
				this->z = z;
			}
			Position::~Position(){}
			int x, y, z;
	}
}
