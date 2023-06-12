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
namespace game {
	namespace moves {
		class Factory
		{
		public:
			Factory();
			~Factory();
			static ::game::moves::Abstract* getMyMoves(std::string typeName);
		protected:
			//static const ::game::moves::Dragon myDragon;
			//static const ::game::moves::Griffon myGriffon;
			//static const ::game::moves::Sylph mySylph;

		};
	}
}
