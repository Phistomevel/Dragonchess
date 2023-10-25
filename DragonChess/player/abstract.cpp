#include "abstract.h"
namespace player {
		Abstract::Abstract(){}
		Abstract::Abstract(std::string color){
			this->color = color;
		}
		Abstract::~Abstract() {}
		void onEvent() {

		}
		void setActive(bool newState) {

		}
}