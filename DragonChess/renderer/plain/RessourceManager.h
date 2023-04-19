#pragma once
//#pragma message("including ::renderer::plain_::Renderer")
//#include <windows.h>
//#include "../../game/board.h"

#include "../../resource.h"
#include <CommCtrl.h>
#pragma comment (lib, "comctl32")
#include <vector>
#include <string>
#include <map>
namespace renderer {
	namespace plain {
		class RessourceManager
		{
		public:
			static RessourceManager* instance();
			~RessourceManager();
			//virtual void render();
			virtual void loadImages();
			virtual void renderSprite(HDC hdc, int x, int y, std::string spriteName);
			HIMAGELIST getSprite(std::string spriteName);
			void setHWND(HWND hWnd);
			HWND getHWND();
			void setRC(LPCWSTR instance);
			LPCWSTR getRC();
		protected:
			std::map<std::string, HIMAGELIST> ImageKey = {};
			HWND hWnd;
			LPCWSTR hinstance;
			RessourceManager();
		};
	}
}

