#include "board.h"
#include <iostream>
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
						layer.push_back(new ::game::pieces::Abstract);
						//WCHAR szWindowClass = RM->getRC();

						WCHAR szTitle[MAX_LOADSTRING];
						RECT cviewDim;
						HWND hWnd = RM->getHWND();
						GetWindowRect(RM->getHWND(), &cviewDim);
						cviewDim.right -= (cviewDim.left + 50);
						cviewDim.bottom -= (cviewDim.top + 50);
						cviewDim.top = 0;
						cviewDim.left = 0;
						UINT id = k;
						RM->getRC();
						layer.at(id)->Create(RM->getRC(),NULL , WS_CHILD || WS_CLIPSIBLINGS, CRect(0,0,1,1), win, id);
						DWORD errorCode = GetLastError();
						TRACE("Error code is:%d\n",errorCode);
					}
					column.push_back(layer);
				}
				this->field.push_back(column);
			}
			this->isInitialized = true;
		}

		::game::pieces::Abstract & Board::getPieceByField(int x, int y, int z) {
			return *(this->field.at(x).at(y).at(z));
		}
		void Board::movePiece(::game::pieces::Abstract* piece, int x, int y, int z) {
			game::board::Position currpos = piece->getPosition();
			this->field.at(x).at(y).at(z) = piece;
			(this->field.at(currpos.x).at(currpos.y).at(currpos.z))->setType(game::pieces::Abstract::UNDEFINED);
		}
		std::vector<::game::Moves> Board::getValidMoves(std::vector<::game::Moves>& moves, ::game::pieces::Abstract piece) {
			return getValid(moves, piece,false);
		}
		std::vector<::game::Moves> Board::getValidCaptures(std::vector<::game::Moves>& moves, ::game::pieces::Abstract piece) {
			return getValid(moves, piece, true);
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
			(*RM).renderSprite(hdc, 0, 0, "Skyboard");
			(this->field.at(5).at(6).at(2))->setType(pieces::Abstract::DRAGON);
			(this->field.at(0).at(0).at(2))->setType(pieces::Abstract::GRIFFON);
			(this->field.at(1).at(1).at(2))->setType(pieces::Abstract::SYLPH);
			(this->field.at(2).at(2).at(2))->setType(pieces::Abstract::GRIFFON);
			(this->field.at(3).at(3).at(2))->setType(pieces::Abstract::BASILISK);
			(this->field.at(5).at(5).at(2))->setType(pieces::Abstract::SYLPH);
			(this->field.at(3).at(3).at(2))->setColor(pieces::Abstract::COLOR_WHITE);
			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 8; j++) {
					//for (int k = 0; k < 3; k++) {
					//TODO:Make universal, for all possible field sizes
					std::string color = (this->field.at(i).at(j).at(2))->getColor();
					if (color==game::pieces::Abstract::COLOR_WHITE) {
						color = "red";
					}
					else {
						color = "blue";
					}
					(*RM).renderSprite(hdc,i*42+5,j*42+5,(this->field.at(i).at(j).at(2))->getType()+color);
					//TODO: make it use the same Renderer?
					//}
				}
			}
			EndPaint((*RM).getHWND(), &ps);
		};
}