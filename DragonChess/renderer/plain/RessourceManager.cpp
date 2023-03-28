#include "RessourceManager.h"
#include <string>
#include <iostream>




namespace renderer {
	namespace plain {
		RessourceManager::RessourceManager() {}
		RessourceManager::~RessourceManager() {}
        RessourceManager *RessourceManager::instance()
        {
            static RessourceManager INSTANCE;
            static RessourceManager *ref = &INSTANCE;
            return ref;
        }


        void RessourceManager::loadImages() {
            std::string mainAddress= "C:\\Users\\Nils\\source\\repos\\Dragonchess\\Dragonchess\\source\\";
            std::string name[12] = {"Basilisk","Dragon","Griffon","Mage","Oliphant","Sylph","Unicorn","Warrior","Subboard","Skyboard","Earthboard","TEST"};
            std::string color[2] = { "red","blue" };
            for (int i = 0; i < 8;i++) {
                for (int j = 0; j < 2; j++) {
                    HBITMAP bitimage = (HBITMAP)LoadImageA(NULL, (mainAddress + name[i] +"_"+ color[j]+".bmp").c_str(), 0, 40, 40, LR_LOADFROMFILE);
                    HBITMAP bitmask = (HBITMAP)LoadImageA(NULL, (mainAddress + name[i] +"_mask.bmp").c_str(), 0, 40, 40, LR_LOADFROMFILE | LR_MONOCHROME);
                    this->ImageKey[name[i] + color[j]] = ImageList_Create(40, 40, ILC_MASK | ILC_COLOR24, 1, 0);
                    int index = ImageList_Add(this->ImageKey[name[i] + color[j]], bitimage, bitmask);;
                }
            }
            for (int i = 8; i < 11; i++) {
                //std::string address = (mainAddress + name[i] + ".bmp").c_str();
                HANDLE bitimage = LoadImageA(NULL, (mainAddress + name[i] + ".bmp").c_str(), 0, 0, 0,  LR_LOADFROMFILE | LR_VGACOLOR);
                HANDLE bitmask = LoadImageA(NULL, (mainAddress + "Boardmask.bmp").c_str(), 0, 0, 0, LR_LOADFROMFILE | LR_MONOCHROME);
                this->ImageKey[name[i]]=(ImageList_Create(512, 344, ILC_COLOR24, 1, 0));
                int index = ImageList_Add(this->ImageKey[name[i]], (HBITMAP)bitimage, (HBITMAP)bitmask);
            }
        }

        void RessourceManager::renderSprite(HDC hdc, int x, int y, std::string spriteName) {//ASK:mainImageList abschaffen, stattdessen nur this->MainImageList?

            if (this->ImageKey.size() == 0) {
                RessourceManager::loadImages();
            }
            if (spriteName.find("Undefined")) {//TODO:use abstract::UNDEFINED instead
                if (ImageList_Draw(this->ImageKey[spriteName], 0, hdc, x, y, ILD_TRANSPARENT)) {
                    
                }
            }
        }

        HIMAGELIST RessourceManager::getSprite(std::string spriteName) {
            if (this->ImageKey.size() == 0) {
                RessourceManager::loadImages();
            }
            return this->ImageKey[spriteName];
        }
        void RessourceManager::setHWND(HWND hWNd) {
            this->hWnd = hWNd;
        }
        HWND RessourceManager::getHWND() {
            return this->hWnd;
        }

	}
}