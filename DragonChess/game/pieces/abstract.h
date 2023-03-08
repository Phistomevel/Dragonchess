#pragma once
#include <string>
#include "../board/position.h"
#include "../../resource.h"
namespace game {
	namespace pieces {
		class Abstract 
		{
		public:
			static const std::string UNDEFINED;
			static const std::string SYLPH;
			static const std::string GRIFFON;
			static const std::string DRAGON;
			static const std::string WARRIOR;
			static const std::string OLIPHANT;
			static const std::string UNICORN;
			static const std::string HERO;
			static const std::string THIEF;
			static const std::string CLERIC;
			static const std::string MAGE;
			static const std::string KING;
			static const std::string PALADIN;
			static const std::string DWARF;
			static const std::string BASILISK;
			static const std::string ELEMENTAL;


			static const std::string COLOR_WHITE;
			static const std::string COLOR_BLACK;
			Abstract();
			Abstract(std::string type, std::string color, int x, int y, int z);
			virtual ~Abstract();

			void setColor(std::string color);
			std::string getColor();
			
			void setType(std::string name);
			/*
			* @return its type
			*/
			std::string getType();
			/**
			 * @return current position
			 */
			::game::board::Position getPosition();
			/*
			*  @param position sets new position
			*/
			void setPosition(::game::board::Position position);
			//void render();


		protected:
			::game::board::Position position;
			std::string type;
			std::string color;
			CView* cView;
		};
	}
}

