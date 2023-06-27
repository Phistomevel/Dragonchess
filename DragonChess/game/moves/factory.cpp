#include "factory.h"
namespace game {
	namespace moves {

		::game::moves::Dragon	Factory::myDragon;
		::game::moves::Griffon	Factory::myGriffon;
		::game::moves::Sylph		Factory::mySylph;
		::game::moves::Warrior	Factory::myWarrior;
		::game::moves::Oliphant	Factory::myOliphant;
		::game::moves::Mage		Factory::myMage;
		::game::moves::Unicorn	Factory::myUnicorn;
		::game::moves::Thief		Factory::myThief;
		::game::moves::Basilisk	Factory::myBasilisk;
		::game::moves::Dwarf		Factory::myDwarf;
		::game::moves::Cleric	Factory::myCleric;
		::game::moves::Paladin	Factory::myPaladin;
		::game::moves::Elemental Factory::myElemental;
		::game::moves::Hero		Factory::myHero;
		::game::moves::King		Factory::myKing;
		::game::moves::NoMoves	Factory::myNoMoves;
		Factory::Factory(){
		
		}
		Factory::~Factory(){}
		game::moves::Abstract& Factory::getMyMoves(std::string typeName){
			if (typeName == game::pieces::Abstract::GRIFFON) {
				return game::moves::Factory::myGriffon;
			}
			if (typeName == game::pieces::Abstract::SYLPH) {
				return game::moves::Factory::mySylph;
			}
			if (typeName == game::pieces::Abstract::DRAGON) {
				return Factory::myDragon;
			}
			if (typeName == game::pieces::Abstract::WARRIOR) {
				return game::moves::Factory::myWarrior;
			}
			if (typeName == game::pieces::Abstract::OLIPHANT) {
				return game::moves::Factory::myOliphant;
			}
			if (typeName == game::pieces::Abstract::UNICORN) {
				return game::moves::Factory::myUnicorn;
			}
			if (typeName == game::pieces::Abstract::MAGE) {
				return game::moves::Factory::myMage;
			}
			if (typeName == game::pieces::Abstract::THIEF) {
				return game::moves::Factory::myThief;
			}
			if (typeName == game::pieces::Abstract::BASILISK) {
				return game::moves::Factory::myBasilisk;
			}
			if (typeName == game::pieces::Abstract::DWARF) {
				return game::moves::Factory::myDwarf;
			}
			if (typeName == game::pieces::Abstract::CLERIC) {
				return game::moves::Factory::myCleric;
			}
			if (typeName == game::pieces::Abstract::PALADIN) {
				return game::moves::Factory::myPaladin;
			}
			if (typeName == game::pieces::Abstract::ELEMENTAL) {
				return game::moves::Factory::myElemental;
			}
			if (typeName == game::pieces::Abstract::HERO) {
				return game::moves::Factory::myHero;
			}
			if (typeName == game::pieces::Abstract::KING) {
				return game::moves::Factory::myKing;
			}
			return game::moves::Factory::myNoMoves;
		}
	}
}