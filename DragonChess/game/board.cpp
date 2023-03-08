#include "board.h"
namespace game {
		Board::Board() {}
		Board::~Board() {}
		::game::pieces::Abstract Board::getPieceByField(int x, int y, int z) {
			return (this->field[x][y][z]);
		}
		void Board::movePiece(::game::pieces::Abstract piece, int x, int y, int z) {
			game::board::Position currpos = piece.getPosition();
			this->field[x][y][z] = piece;
			(this->field[currpos.x][currpos.y][currpos.z]).setType(game::pieces::Abstract::UNDEFINED);
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
					std::string piece = (this->field[move.x][move.y][move.z]).getType();
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
		void Board::render(HDC hdc, ::renderer::plain::Render &renderer) {
			(this->field[5][6][2]).setType(pieces::Abstract::DRAGON);
			(this->field[0][0][2]).setType(pieces::Abstract::GRIFFON);
			(this->field[1][1][2]).setType(pieces::Abstract::SYLPH);
			(this->field[2][3][2]).setType(pieces::Abstract::GRIFFON);
			(this->field[3][4][2]).setType(pieces::Abstract::BASILISK);
			(this->field[3][4][2]).setColor(pieces::Abstract::COLOR_WHITE);
			(this->field[5][5][2]).setType(pieces::Abstract::SYLPH);
			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 8; j++) {
					//for (int k = 0; k < 3; k++) {
					//TODO:Make universal, for all possible field sizes
					std::string color = (this->field[i][j][2]).getColor();
					if (color==game::pieces::Abstract::COLOR_WHITE) {
						color = "red";
					}
					else {
						color = "blue";
					}
					renderer.renderSprite(hdc,i*42+5,j*42+5,(this->field[i][j][2]).getType()+color);
					//TODO: make it use the same Renderer?
					//}
				}
			}
		};
}