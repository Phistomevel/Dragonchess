#pragma once
#pragma message("including ::renderer::plain_::Renderer")
//#include <windows.h>
#include "../../game/board.h"


#include <CommCtrl.h>
#pragma comment (lib, "comctl32")
#include <vector>
#include <string>
#include <map>
namespace renderer {
	namespace plain {
		class Render
		{
		public:
			Render();
			~Render();
			virtual void render(HWND hWnd);
			virtual void renderSprite(HDC hdc, int x, int y, std::string spriteName);
			HIMAGELIST getSprite(std::string spriteName);
			virtual void loadImages();
		protected:
			std::map<std::string, HIMAGELIST> ImageKey = {};
		};
	}
}

