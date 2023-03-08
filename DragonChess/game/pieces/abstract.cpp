#include "abstract.h"


namespace game {

	namespace pieces {

		const std::string Abstract::UNDEFINED = "Undefined";
		const std::string Abstract::SYLPH     = "Sylph";
		const std::string Abstract::GRIFFON   = "Griffon";
		const std::string Abstract::DRAGON    = "Dragon";
		const std::string Abstract::WARRIOR   = "Warrior";
		const std::string Abstract::OLIPHANT  = "Oliphant";
		const std::string Abstract::UNICORN   = "Unicorn";
		const std::string Abstract::HERO      = "Hero";
		const std::string Abstract::THIEF     = "Thief";
		const std::string Abstract::CLERIC    = "Cleric";
		const std::string Abstract::MAGE      = "Mage";
		const std::string Abstract::KING      = "King";
		const std::string Abstract::PALADIN   = "Paladin";
		const std::string Abstract::DWARF     = "Dwarf";
		const std::string Abstract::BASILISK  = "Basilisk";
		const std::string Abstract::ELEMENTAL = "Elemental";

		const std::string Abstract::COLOR_WHITE = "White";
		const std::string Abstract::COLOR_BLACK = "Black";

		Abstract::Abstract() {
			this->type = Abstract::UNDEFINED;
			this->color = Abstract::COLOR_BLACK;
			this->position = game::board::Position(0,0,0);
		}

		Abstract::Abstract(std::string type , std::string color, int x, int y, int z) {
			this->type = type;
			this->color=color;
			this->position = game::board::Position(x,y,z);
		}
		Abstract::~Abstract() {}

		void Abstract::setColor(std::string color) {
			this->color = color;
		}

		std::string Abstract::getColor() {
			return this->color;
		}

		void Abstract::setType(std::string name) {
			this->type=name;
		}

		std::string Abstract::getType() {
			return this->type;
		}

		/**
		 * @return current position
		 */
		::game::board::Position Abstract::getPosition() {
			return this->position;
		}
		/*
		*  @param position sets new position
		*/
		void Abstract::setPosition(::game::board::Position position) {
			this->position = position;
		}
	}
}

