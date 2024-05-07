#include "abstract.h"
namespace player {
		Abstract::Abstract(){}
		const std::string Abstract::TYPE_HUMAN_LOCAL = "humanLocal";
		const std::string Abstract::TYPE_HUMAN_REMOTE = "humanRemote";
		const std::string Abstract::TYPE_AIPLAYER = "AIplayer";
		Abstract::Abstract(std::string color){
			this->color = color;
		}
		Abstract::~Abstract() {}
		void Abstract::onEvent() {

		}
		void Abstract::setActive(bool newState, ::game::Board& board) {

		}
		std::string Abstract::getType() {
			return this->type;
		}


}