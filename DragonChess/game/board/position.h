#pragma once
namespace game {
	namespace board {
		
		class Position
		{
		public:
			Position(int x = 0, int y = 0, int z = 0);
			virtual ~Position();
			int x, y, z;
			bool operator<( const ::game::board::Position& other);
			//bool operator>(::game::board::Position& other);
		};
		bool operator<(const ::game::board::Position& a, const ::game::board::Position& b);
	}
}

