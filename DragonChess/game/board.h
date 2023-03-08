#pragma once
#include <vector>
#include "pieces/abstract.h"
#include "board/position.h"
#include "moves.h"
//include <Windows.h>
#include "../renderer/plain/Render.h"
#include "pieces/abstract.h"
namespace renderer {
	namespace plain {
		class Render;
	}
}

namespace game {


	class Board
	{
	public:
		Board();
		~Board();
		virtual ::game::pieces::Abstract getPieceByField(int x, int y, int z);
		virtual void movePiece(::game::pieces::Abstract piece, int x, int y, int z);
		virtual std::vector<::game::Moves> getValidMoves(std::vector<::game::Moves>& moves, ::game::pieces::Abstract piece);
		virtual std::vector<::game::Moves> getValidCaptures(std::vector<::game::Moves>& moves, ::game::pieces::Abstract piece);
		virtual void render(
			HDC hdc,
			::renderer::plain::Render &renderer
		);
	
	protected:
		static const int MAX_X = 12;
		static const int MAX_Y = 8;
		static const int MAX_Z = 3;
		::game::pieces::Abstract field[MAX_X][MAX_Y][MAX_Z];
		const std::vector<game::Moves>& getValid(std::vector<game::Moves>& moves, game::pieces::Abstract& piece, bool isCapture);

	};
}

