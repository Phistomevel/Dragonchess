#pragma once
#include <vector>
#include "../board/position.h"
#include "../moves.h";
#include "capture.h"
namespace game {
	namespace moves {
		class Abstract
		{
		public:
			Abstract();
			virtual ~Abstract();
			virtual std::vector<::game::Moves> getMoves(int layer)=0;
			virtual std::vector<::game::moves::Capture> getCaptures(int layer)=0;

		};
	}
}

