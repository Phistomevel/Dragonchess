#pragma once
namespace game {
	namespace board {
		class Position
		{
		public:
			Position(int x = 0, int y = 0, int z = 0);
			virtual ~Position();
			int x, y, z;

		};
	}
}

