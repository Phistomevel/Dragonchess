#include "MessageManager.h"
#include "../Game.h"
namespace tools {
		//static const int ONCLICK = 0;
		MessageManager::MessageManager(){}
		MessageManager::~MessageManager() {};
		MessageManager::MessageManager(const MessageManager&){};
		MessageManager &MessageManager::getInstance(){
			static MessageManager INSTANCE;
			return INSTANCE;
		}

		void MessageManager::sendMessage(int msgtype, game::pieces::Abstract* sender, int param) {
			for (auto element : this->observers) {
				if (element) {
					element->onEvent(sender);
				}
			}
		}
		void MessageManager::registerObserver(Game* observer) {
			this->observers.push_back(observer);
		}

}
