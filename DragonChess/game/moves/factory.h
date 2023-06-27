#pragma once
#include "../../resource.h"
#include "../pieces/abstract.h"
#include "abstract.h"
#include "dragon.h"
#include "griffon.h"
#include "sylph.h"
#include "nomoves.h"
#include "warrior.h"
#include "oliphant.h"
#include "unicorn.h"
#include "mage.h"
#include "thief.h"
#include "basilisk.h"
#include "dwarf.h"
#include "cleric.h"
#include "paladin.h"
#include "elemental.h"
#include "hero.h"
#include "king.h"
namespace game {
	namespace moves {
		class Factory
		{
		public:
			Factory();
			~Factory();
			static ::game::moves::Abstract& getMyMoves(std::string typeName);
		protected:
			static ::game::moves::Dragon myDragon;
			static ::game::moves::Griffon myGriffon;
			static ::game::moves::Sylph mySylph;
			static ::game::moves::Warrior myWarrior;
			static ::game::moves::Oliphant myOliphant;
			static ::game::moves::Mage myMage;
			static ::game::moves::Unicorn myUnicorn;
			static ::game::moves::Thief myThief;
			static ::game::moves::Basilisk myBasilisk;
			static ::game::moves::Dwarf myDwarf;
			static ::game::moves::Cleric myCleric;
			static ::game::moves::Paladin myPaladin;
			static ::game::moves::Elemental myElemental;
			static ::game::moves::Hero myHero;
			static ::game::moves::King myKing;
			static ::game::moves::NoMoves myNoMoves;

		};
	}
}
