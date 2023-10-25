#include "abstract.h"


BEGIN_MESSAGE_MAP(::game::pieces::Abstract, CView)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	//ON_MESSAGE(WM_CREATE, OnMyPaint)
	//ON_MESSAGE(WM_RBUTTONDOWN, OnMyUpdate)
	
END_MESSAGE_MAP()

namespace game {

	namespace pieces {
		IMPLEMENT_DYNCREATE(Abstract, CView)


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

		const std::string Abstract::COLOR_WHITE = "red";
		const std::string Abstract::COLOR_BLACK = "blue";

		const std::string Abstract::TYPE_DEFAULT	="default";
		const std::string Abstract::TYPE_SCELECTED	="scelected";
		const std::string Abstract::TYPE_MOVE		="move_target";
		const std::string Abstract::TYPE_CAPTURE	="capture_target";

		Abstract::Abstract() 
		{
			this->type = Abstract::UNDEFINED;
			this->color = Abstract::COLOR_BLACK;
			this->position = game::board::Position(0,0,0);
			//this->cView->Create(szTitle,szWindowClass , WS_CHILD, rect, , 1 );
		}

		Abstract::Abstract(const Abstract& other)
		{
			this->type = other.type;
			this->color = other.color;
			this->position = other.position;
			//this->cView->Create(szTitle,szWindowClass , WS_CHILD, rect, , 1 );
		}

		Abstract::Abstract(std::string type , std::string color, int x, int y, int z) {

			this->type = type;
			this->color=color;
			this->position = game::board::Position(x,y,z);
		}
		Abstract::~Abstract() {
		}
		Abstract::operator bool() {
			if (this->type==::game::pieces::Abstract::UNDEFINED) {
				return false;
			}
			return true;
		}

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

		void Abstract::render() {
			
		}

		void Abstract::OnDraw(CDC* pdc)
		{
			CWnd* pParent = GetParent();
			//return;
			if (pParent != NULL)
			{
				// Your drawing code goes here
				HDC hdc = pdc->GetSafeHdc();
				::renderer::plain::RessourceManager* RM = RM->instance();
				RECT removemeplease;
				this->GetWindowRect(&removemeplease);
				RECT fillrect = { 0,0,42,42 };
				int i, j, r, g, b;
				i = (this->position.x + this->position.y) % 2;
				j = this->position.z;
				if (this->state==Abstract::TYPE_SCELECTED) {
					r = { (i == 0 && j == 0) * 227 +
						(i == 1 && j == 0) * 255 + 
						(i == 1 && j == 1) * 188 + 
						(i == 1 && j == 2) * 255 };
					g = { (i == 0 && j == 0) * 19 + 
						  (i == 1 && j == 0) * 64 + 
						  (i == 0 && j == 1) * 124 + 
						  (i == 1 && j == 1) * 198 + 
						  (i == 0 && j == 2) * 255 + 
						  (i == 1 && j == 2) * 255 };
					b = { (i == 0 && j == 0) * 19 + 
						  (i == 1 && j == 0) * 64 +
						  //(i == 0 && j == 1) * 0 + 
						  (i == 1 && j == 1) * 98 +
						  (i == 0 && j == 2) * 235 +
						  //(i == 1 && j == 2) * 0 + 
						  (i == 1 && j == 2) * 255 };
					FillRect(hdc, &fillrect, RM->getBrush(r, g, b));
					r = { (i == 1 && j == 0) * 227 +
						(i == 0 && j == 0) * 255 +
						(i == 0 && j == 1) * 188 +
						(i == 0 && j == 2) * 255 };
					g = { (i == 1 && j == 0) * 19 +
						(i == 0 && j == 0) * 64 +
						(i == 1 && j == 1) * 124 +
						(i == 0 && j == 1) * 198 +
						(i == 1 && j == 2) * 255 +
						(i == 0 && j == 2) * 255 };
					b = { (i == 1 && j == 0) * 19 +
						(i == 0 && j == 0) * 64 +
						(i == 1 && j == 1) * 0 +
						(i == 0 && j == 1) * 98 +
						(i == 1 && j == 2) * 235 +
						(i == 0 && j == 2) * 0 +
						(i == 0 && j == 2) * 255 };
					fillrect.left+=10;
					fillrect.top+=10;
					fillrect.right-=2;
					fillrect.bottom-=2;
					FillRect(hdc, &fillrect, RM->getBrush(r, g, b));

					ImageList_Draw(RM->getSprite(this->type + this->color), 0, hdc, 1, 1, ILD_TRANSPARENT);
					return;
				}
				if(this->state==::game::pieces::Abstract::TYPE_DEFAULT) {
					r = (i == 0 && j == 0) * 227 + (i == 1 && j == 0) * 255 + (i == 1 && j == 1) * 188 + (i == 1 && j == 2) * 255;
					g = (i == 0 && j == 0) * 19 + (i == 1 && j == 0) * 64 + (i == 0 && j == 1) * 124 + (i == 1 && j == 1) * 198 + (i == 0 && j == 2) * 255 + (i == 1 && j == 2) * 255;
					b = (i == 0 && j == 0) * 19 + (i == 1 && j == 0) * 64 + (i == 0 && j == 1) * 0 + (i == 1 && j == 1) * 98 + (i == 0 && j == 2) * 235 + (i == 1 && j == 2) * 0 + (i == 1 && j == 2) * 255;
					if (FillRect(hdc, &fillrect, RM->getBrush(r, g, b))) {
						//TRACE("heyooooo\n");
					}
					if (ImageList_Draw(RM->getSprite(this->type + this->color), 0, hdc, 1, 1, ILD_TRANSPARENT)) {
						//TRACE("Drew sprite, error is elsewhere\n");
					}
					return;
				}
				if (this->state == ::game::pieces::Abstract::TYPE_MOVE) {
					r = (10);
					g = (255);
					b = (40);
					if (FillRect(hdc, &fillrect, RM->getBrush(r, g, b))) {
						//TRACE("heyooooo\n");
					}
					if (ImageList_Draw(RM->getSprite(this->type + this->color), 0, hdc, 1, 1, ILD_TRANSPARENT)) {
						//TRACE("Drew sprite, error is elsewhere\n");
					}
					return;
				}
				if (this->state == ::game::pieces::Abstract::TYPE_CAPTURE) {
					r = (255);
					g = (50);
					b = (40);
					if (FillRect(hdc, &fillrect, RM->getBrush(r, g, b))) {
						//TRACE("heyooooo\n");
					}
					if (ImageList_Draw(RM->getSprite(this->type + this->color), 0, hdc, 1, 1, ILD_TRANSPARENT)) {
						//TRACE("Drew sprite, error is elsewhere\n");
					}
					return;
				}
			}
			else
			{
				TRACE("CMyView is not attached to a parent CWnd\n");
			}
			return;
		}
		void Abstract::OnPaint() {
			//CPaintDC dc(this);
			//OnPrepareDC(&dc);
			int id = this->GetDlgCtrlID();
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(&ps)->GetSafeHdc();
			OnDraw(CDC::FromHandle(hdc));
			EndPaint(&ps);
			return;
		}
		void Abstract::OnLButtonDown(UINT uint, CPoint point) {
			::tools::MessageManager &MM = MM.getInstance();
			this->state = Abstract::TYPE_SCELECTED;
			this->Invalidate();
			Abstract& ref = *this;
			MM.sendMessage(::tools::MessageManager::ONCLICK, this, uint);
		}
		void Abstract::OnRButtonDown(UINT uint, CPoint point) {
			this->state = Abstract::TYPE_DEFAULT;
			this->Invalidate();
		}

		void Abstract::setState(std::string type) {
			this->state=type;
			this->Invalidate();
		}
		std::string Abstract::getState() {
			return this->state;
		}
		std::string Abstract::getPetrifiedBy() {
			return this->petrifiedBy;
		}
		void Abstract::setPetrified(std::string petrificatorColor) { 
			this->petrifiedBy = petrificatorColor;
		}
	}
}
