#pragma once
#include <vector>
#include "pieces/abstract.h"
#include "board/position.h"
#include "moves.h"
#include "moves/capture.h"
#include "moves/factory.h"
#include "moves/abstract.h"
//include <Windows.h>
#include "../renderer/plain/RessourceManager.h"
/*namespace renderer {
	namespace plain {
		class Render;
	}
}*/
namespace game {
	namespace pieces {
		class Abstract;
	}
}
namespace game {
	namespace moves {
		class Abstract;
	}
}
namespace game{


	class Board
	{
	public:
		Board();
		~Board();
		Board(const Board& other);
		virtual ::game::pieces::Abstract& getPieceByField(int x, int y, int z);
		void onresize(RECT newsize);
		virtual void movePiece(::game::pieces::Abstract* piece, int x, int y, int z);
		virtual std::vector<::game::Moves> getValidMoves(::game::pieces::Abstract& piece);
		virtual std::vector<::game::moves::Capture> getValidCaptures(::game::pieces::Abstract piece);
		virtual void render();
		void init();
		::game::pieces::Abstract& getKing(std::string color);
	protected:
		bool isInitialized= false;
		bool isInitializing= false;
		static const int MAX_X = 12;
		static const int MAX_Y = 8;
		static const int MAX_Z = 3;
		std::vector<std::vector<std::vector<::game::pieces::Abstract*>>> field;// = new std::vector<std::vector<std::vector<::game::pieces::Abstract*>>>;
		const std::vector<game::Moves>& getValid(std::vector<game::Moves>& moves, game::pieces::Abstract& piece, bool isCapture);

	};
}

