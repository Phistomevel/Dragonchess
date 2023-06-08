#pragma once
#include "../resource.h"
#include <vector>
#include "../game/pieces/abstract.h"
class Game;
namespace game {
	namespace pieces {
		class Abstract;
	}
}


namespace tools {
	class MessageManager
	{
	public:
		static const int ONCLICK=0;

		~MessageManager();
		static MessageManager& getInstance();
		void sendMessage(int msgtype, game::pieces::Abstract* sender, int param);
		void registerObserver(Game* observer);
	protected:
		MessageManager();
		MessageManager(const MessageManager&);
		std::vector<Game*> observers;
	};
}


