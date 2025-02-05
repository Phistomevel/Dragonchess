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
            WCHAR path[MAX_PATH];
            GetModuleFileNameW(NULL, path, MAX_PATH);
            std::wstring stringPath(path);
            stringPath = stringPath.substr(0, stringPath.length() - 25);
            stringPath.append(L"DragonChess\\source\\");
            std::string mainAddress(stringPath.begin(),stringPath.end());
            std::string name[19] = {"King","Hero","Cleric","Basilisk","Paladin","Dwarf","Elemental","Dragon","Griffon","Mage","Oliphant","Sylph","Unicorn","Warrior","Thief","Subboard","Skyboard","Earthboard","TEST"};
            std::string color[2] = { "red","blue" };
            for (int i = 0; i < 16;i++) {
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
        HBRUSH RessourceManager::getBrush(int r, int g, int b) {
            int hashIndex = r*65536+g*256+b;
            if (this->ColorKey.count(hashIndex)==0) {
                COLORREF color = RGB(r, g, b);
                HBRUSH newBrush = CreateSolidBrush(color);
                this->ColorKey.emplace(std::make_pair(hashIndex, newBrush));
            }
            return this->ColorKey[hashIndex];
        }

        void RessourceManager::setHWND(HWND hWNd) {
            this->hWnd = hWNd;
        }
        HWND RessourceManager::getHWND() {
            return this->hWnd;
        }
        void RessourceManager::setRC(LPCWSTR hinstance) {
            this->hinstance = hinstance;
        }
        LPCWSTR RessourceManager::getRC() {
            return this->hinstance;
        }

	}
}