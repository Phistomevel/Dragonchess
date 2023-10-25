#pragma once
#define MAX_LOADSTRING 100
#include <string>
#include <set>
#include "../board/position.h"
#include "../../resource.h"
#include "../../tools/MessageManager.h"
//#include "../../DragonChess.h"
#include "../../renderer/plain/RessourceManager.h"
//#include "../../resource.h"


namespace game {
	namespace pieces {
		class AFX_CLASS_EXPORT Abstract : public CView
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


			static const std::string TYPE_DEFAULT;
			static const std::string TYPE_SCELECTED;
			static const std::string TYPE_MOVE;
			static const std::string TYPE_CAPTURE;
			Abstract();
			Abstract(const Abstract& other);
			Abstract(std::string type, std::string color, int x, int y, int z);
			explicit operator bool();
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

			afx_msg void OnDraw(CDC* pdc) override;
			afx_msg void OnPaint();
			afx_msg LRESULT OnMyUpdate(WPARAM wParam, LPARAM lParam) ;
			afx_msg void OnLButtonDown(UINT uint, CPoint point);
			afx_msg void OnRButtonDown(UINT uint, CPoint point);

			//BOOL PreCreateWindow(CREATESTRUCT& cs) override;
			/*
			*  @param position sets new position
			*/
			void setPosition(::game::board::Position position);
			void render();
			void setState(std::string type);
			std::string getState();
			std::string getPetrifiedBy();
			void setPetrified(std::string petrificatorColor);
		protected:
			::game::board::Position position;
			std::string type;
			std::string color;
			std::string state = "default";
			std::string petrifiedBy = "Undefined";
			DECLARE_MESSAGE_MAP()
			DECLARE_DYNCREATE(Abstract)
		};
	}
}