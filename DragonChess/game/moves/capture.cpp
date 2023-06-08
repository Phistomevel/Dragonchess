#include "capture.h"
namespace game {
	namespace moves {
		Capture::Capture(::game::Moves move, ::game::Moves capture) {
			if (capture.moveType==capture.MOVE_UNDEFINED) {
				capture=move;
			}
			this->capture = capture;
			this->move = move;
		}
		Capture::~Capture() {}
		::game::Moves move;
		::game::Moves capture;
		bool Capture::operator==(const Capture& other) const {
			if (!(this->move == other.move)) {
				return false;
			};
			if (!(this->capture == other.capture)) {
				return false;
			};
			return true;
		};
	}
}