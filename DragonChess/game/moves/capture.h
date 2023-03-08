#pragma once
#include "../board/position.h"
#include "../moves.h"
namespace game {
	namespace moves {
		class Capture
		{
		public:
			Capture(::game::Moves move = { 0,0,0, ::game::Moves::MOVE_UNDEFINED }, ::game::Moves capture = { 0,0,0, ::game::Moves::MOVE_UNDEFINED });
			virtual	~Capture();
			::game::Moves move;
			::game::Moves capture;
		};
	}
}

