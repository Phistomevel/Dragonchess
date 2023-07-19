#pragma once

namespace game {
	namespace board {
		class Bitboard
		{
		public:
			Bitboard();
			~Bitboard();
			bool getAt(int x, int y, int z);
			void setAt(int x, int y, int z, bool newState);
			static const unsigned int singleBit;
		protected:
			unsigned int rows[12][3];
			void setBit(unsigned int &bitArray, int x ,bool newState);
			bool getBit(unsigned int &bitArray, int x);
		};
	}
}