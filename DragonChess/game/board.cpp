#include "board.h"
#include <iostream>
#include <fstream>
namespace game {
		Board::Board() {

		}
		Board::~Board() {
			/*for (auto layer : this->field) {
				for (auto column : layer) {
					for (auto &field : column) {
						if (field) {
							field->DestroyWindow();
							delete field;
							field = NULL;
						}
					}
					column.clear();
				}
				layer.clear();
			}
			this->field.clear();
			*/
		}
		void game::Board::onresize(RECT newsize)
		{
			for (int i = 0; i < this->MAX_X; i++) {
				for (int j = 0; j < this->MAX_Y; j++) {
					for (int k = 0; k < this->MAX_Z; k++) {
						RECT fieldRect;
						this->field[i][j][k]->GetClientRect(&fieldRect);
						this->field[i][j][k]->MoveWindow(fieldRect.left,fieldRect.top,fieldRect.right,fieldRect.bottom);
					}
				}
			}
		}

		void Board::init() {
			::renderer::plain::RessourceManager* RM = (*RM).instance();
			CWnd* win = CWnd::FromHandle(RM->getHWND());
			if (this->isInitialized) {
				return;
			}
			if (win==NULL) {
				return;
			}
			if (afxCurrentInstanceHandle == NULL) {
				return;
			}
			
			
			
			for (int i = 0; i < this->MAX_X; i++) {
				std::vector<std::vector<::game::pieces::Abstract*>> column;
				for (int j = 0; j < this->MAX_Y; j++) {
					std::vector<::game::pieces::Abstract*> layer;
					for (int k = 0; k < this->MAX_Z; k++) {
						
						layer.push_back(new ::game::pieces::Abstract(::game::pieces::Abstract::UNDEFINED,::game::pieces::Abstract::COLOR_BLACK,i,j,k));
						//WCHAR szWindowClass = RM->getRC();
							WCHAR szTitle[MAX_LOADSTRING];
							RECT cviewDim;
							HWND hWnd = RM->getHWND();
							GetWindowRect(RM->getHWND(), &cviewDim);
							RECT standardViewDim = RECT{ 0, 0, 42, 42 };
							standardViewDim.right += i * 42 + k%2 * 512 + k/2*256+ 4;
							standardViewDim.left += i * 42 + k%2 * 512 + k/2 * 256 + 4;
							standardViewDim.top += j * 42+k/2*-344 + 348;
							standardViewDim.bottom += j * 42+k / 2 * -344 + 348;

							/*cviewDim.right -= (cviewDim.left + 50);
							cviewDim.bottom -= (cviewDim.top + 50);
							cviewDim.top = 0;
							cviewDim.left = 0;*/
							UINT id = k+10*j+100*i;
							RM->getRC();
							layer.at(k)->Create(RM->getRC(), NULL, WS_VISIBLE || WS_CHILD || WS_CLIPSIBLINGS, standardViewDim, win, id);
							/*layer.at(id)->Detach();
							layer.at(id)->Attach(win->GetSafeHwnd());*/
							layer.at(k)->SetParent(win);
							layer.at(k)->ShowWindow(1);
							layer.at(k)->EnableWindow();
							std::string windowname;
							windowname += "ID:"+ std::to_string(id);
							layer.at(k)->SetWindowTextW(CA2CT(windowname.c_str()));
							layer.at(k)->BringWindowToTop();
							RECT parentWin;
							RECT childWin;
							layer.at(k)->GetWindowRect(&childWin);
							win->GetWindowRect(&parentWin);
							layer.at(k)->Invalidate();
					}
					column.push_back(layer);
				}
				this->field.push_back(column);
			}
			(this->field.at(5).at(6).at(2))->setType(pieces::Abstract::DRAGON);
			(this->field.at(5).at(6).at(1))->setType(pieces::Abstract::OLIPHANT);
			(this->field.at(4).at(6).at(1))->setType(pieces::Abstract::UNICORN);
			(this->field.at(3).at(6).at(1))->setType(pieces::Abstract::MAGE);
			(this->field.at(9).at(6).at(1))->setType(pieces::Abstract::THIEF);
			//(this->field.at(5).at(6).at(1))->setColor(pieces::Abstract::COLOR_WHITE);
			(this->field.at(5).at(6).at(2))->setColor(pieces::Abstract::COLOR_WHITE);
			(this->field.at(0).at(0).at(2))->setType(pieces::Abstract::GRIFFON);
			(this->field.at(1).at(1).at(2))->setType(pieces::Abstract::SYLPH);
			(this->field.at(2).at(2).at(2))->setType(pieces::Abstract::GRIFFON);
			(this->field.at(4).at(3).at(0))->setType(pieces::Abstract::BASILISK);
			(this->field.at(5).at(5).at(2))->setType(pieces::Abstract::SYLPH);
			(this->field.at(5).at(5).at(1))->setType(pieces::Abstract::WARRIOR);
			(this->field.at(5).at(5).at(2))->setColor(pieces::Abstract::COLOR_WHITE);
			(this->field.at(4).at(3).at(0))->setColor(pieces::Abstract::COLOR_WHITE);

			this->isInitialized = true;
		}

		::game::pieces::Abstract& Board::getPieceByField(int x, int y, int z) {
			return *(this->field.at(x).at(y).at(z));
		}
		void Board::movePiece(::game::pieces::Abstract* piece, int x, int y, int z) {
			game::board::Position currpos = piece->getPosition();
			this->field.at(x).at(y).at(z)->setType(piece->getType());
			(this->field.at(currpos.x).at(currpos.y).at(currpos.z))->setType(game::pieces::Abstract::UNDEFINED);
		}
		std::vector<::game::Moves> Board::getValidMoves(::game::pieces::Abstract& piece) {
				//TODO:: factory etablieren, da string in object umwandeln, dann object.getmoves(board*) aufrufen.
			std::vector<::game::Moves> ret;
			return ret;
		}
		std::vector<::game::moves::Capture> Board::getValidCaptures(::game::pieces::Abstract piece) {
			std::vector<::game::moves::Capture> ret;
			return ret;
		}

		const std::vector<game::Moves>& Board::getValid(std::vector<game::Moves>& moves, game::pieces::Abstract& piece, bool isCapture)
		{
			std::vector<game::Moves> ret;
			for(auto currentMove : moves) {
				::game::Moves move = currentMove;
				//@todo append to ret instead of modifying moves 
				if (move.moveType == "relative") {
					move.x = piece.getPosition().x + move.x;
					move.y = piece.getPosition().y + move.y;
					move.z = piece.getPosition().z + move.z;
					move.moveType = ::game::Moves::MOVE_ABSOLUTE;
				}

				//check if move leads offboard
				if (move.x>=0 && move.x < MAX_X && move.y >= 0 && move.y < MAX_Y && move.z >= 0 && move.z < MAX_Z)
				{
					std::string piece = (this->field.at(move.x).at(move.y).at(move.z))->getType();
					if (isCapture) {
						//check if target field is not occupied 
						if (piece != (::game::pieces::Abstract::UNDEFINED))
						{
							ret.push_back(move);
						}
					}
					else {
						//check if target field is occupied 
						if (piece == (::game::pieces::Abstract::UNDEFINED))
						{
							ret.push_back(move);
						}
					}
				}
				
			}
			return moves;
		}
		void Board::render() {
			if (!this->isInitialized) {
				return;
			}
			::renderer::plain::RessourceManager *RM = (*RM).instance();
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint((*RM).getHWND(), &ps);
			(*RM).renderSprite(hdc, 256, 0, "Skyboard");
			(*RM).renderSprite(hdc, 0, 344, "Earthboard");
			(*RM).renderSprite(hdc, 512, 344, "Subboard");
			(this->field.at(5).at(6).at(2))->setType(pieces::Abstract::DRAGON);
			(this->field.at(0).at(0).at(2))->setType(pieces::Abstract::GRIFFON);
			(this->field.at(1).at(1).at(2))->setType(pieces::Abstract::SYLPH);
			(this->field.at(2).at(2).at(2))->setType(pieces::Abstract::GRIFFON);
			(this->field.at(4).at(3).at(2))->setType(pieces::Abstract::BASILISK);
			(this->field.at(5).at(5).at(2))->setType(pieces::Abstract::SYLPH);
			(this->field.at(3).at(3).at(2))->setColor(pieces::Abstract::COLOR_WHITE);
			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 8; j++) {
					//for (int k = 0; k < 3; k++) {
					std::string color = (this->field.at(i).at(j).at(2))->getColor();
					if (color==game::pieces::Abstract::COLOR_WHITE) {
						color = "red";
					}
					else {
						color = "blue";
					}
					//(*RM).renderSprite(hdc,i*42+5,j*42+5,(this->field.at(i).at(j).at(2))->getType()+color);
					//TODO: make it use the same Renderer?
					//}
				}
			}
			EndPaint((*RM).getHWND(), &ps);
		};
}