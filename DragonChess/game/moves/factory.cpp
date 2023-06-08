#include "factory.h"
namespace game {
	namespace moves {
		Factory::Factory(){
		
		}
		Factory::~Factory(){}
		game::moves::Abstract* Factory::getMyMoves(std::string typeName){
			if (typeName == game::pieces::Abstract::GRIFFON) {
				//return &game::moves::Factory::myGriffon;
				return new game::moves::Griffon();
			}
			if (typeName == game::pieces::Abstract::SYLPH) {
				//return &game::moves::Factory::mySylph;
				return new game::moves::Sylph;
			}
			if (typeName == game::pieces::Abstract::DRAGON) {
				//return &game::moves::Factory::myDragon;
				return new game::moves::Dragon;
			}
			if (typeName == game::pieces::Abstract::WARRIOR) {
				//return &game::moves::Factory::myDragon;
				return new game::moves::Warrior;
			}
			if (typeName == game::pieces::Abstract::OLIPHANT) {
				//return &game::moves::Factory::myDragon;
				return new game::moves::Oliphant;
			}
			if (typeName == game::pieces::Abstract::UNICORN) {
				//return &game::moves::Factory::myDragon;
				return new game::moves::Unicorn;
			}
			if (typeName == game::pieces::Abstract::MAGE) {
				//return &game::moves::Factory::myDragon;
				return new game::moves::Mage;
			}
			if (typeName == game::pieces::Abstract::THIEF) {
				//return &game::moves::Factory::myDragon;
				return new game::moves::Thief;
			}
			if (typeName == game::pieces::Abstract::BASILISK) {
				//return &game::moves::Factory::myDragon;
				return new game::moves::Basilisk;
			}
			return new game::moves::NoMoves;
		}
	}
}