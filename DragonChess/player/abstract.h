#pragma once
#include <string>
namespace player {
	class Abstract
	{
	public:
		Abstract();
		Abstract(std::string color);
		~Abstract();
		void onEvent();
		void setActive(bool newState);
	private:
		bool isActive;
		std::string color;
	};
}


