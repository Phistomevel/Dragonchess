#pragma once
#include <string>
#include <vector>
namespace game {
	class Moves
	{
	public:
		Moves(int x=0, int y=0, int z=0, std::string moveType="UNDEFINED");
		virtual ~Moves();
		bool operator==(const Moves& other) const;
		bool operator>(const Moves& other) const;
		bool operator<(const Moves& other) const;
		const static std::string MOVE_RELATIVE;
		const static std::string MOVE_ABSOLUTE;
		const static std::string MOVE_UNDEFINED;
		std::string moveType;
		int x, y, z;
	};
}
