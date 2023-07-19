#pragma once
namespace player {
	class Abstract
	{
	public:
		Abstract();
		~Abstract();
		void onEvent();
		void setActive(bool newState);
	private:
		bool isActive;
	};
}


