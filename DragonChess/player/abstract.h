#pragma once
#include <string>
#include "../game/board.h"
namespace player {
	class Abstract
	{
	public:
		const static std::string TYPE_HUMAN_LOCAL;
		const static std::string TYPE_HUMAN_REMOTE;
		const static std::string TYPE_AIPLAYER;

		Abstract();
		Abstract(std::string color);
		~Abstract();
		void onEvent();
		void setActive(bool newState, ::game::Board &board);
		std::string getColor();
		virtual std::string getType();
	private:
		bool isActive;
		std::string color;
		std::string type;

	};
}


