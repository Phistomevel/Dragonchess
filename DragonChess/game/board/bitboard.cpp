#include "bitboard.h"
namespace game {
	namespace board {
		const unsigned int Bitboard::singleBit = 0x00000001;
		Bitboard::Bitboard(){
			for (int i = 0; i < 12;i++) {
				for (int j = 0; j < 3;j++) {
					this->rows[i][j]=0;
				}
			}
		}
		Bitboard::~Bitboard(){}
		bool Bitboard::getAt(int x, int y, int z) {
			return this->getBit(this->rows[y][z], x);
		}
		void Bitboard::setAt(int x, int y, int z, bool newstate) {
			this->setBit(this->rows[y][z], x, newstate);
		}
		void Bitboard::setBit(unsigned int &bitArray, int x, bool newState) {
			if (this->getBit(bitArray, x)!=newState) {
				bitArray = bitArray ^ (Bitboard::singleBit << x);
			}
		}
		bool Bitboard::getBit(unsigned int &bitArray, int x) {
			return (bitArray&(Bitboard::singleBit<<x));
		}
	}
}