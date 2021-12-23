#ifndef POSITION_HPP_
#define POSITION_HPP_

#include <string>

typedef struct PositionArgs {
	int idx = 0, ln = 0, col = 0;
	std::string fileName, fileText;
} PositionArgs;

class Position {
	public:
		int idx = 0, ln = 0, col = 0;
		std::string fileName, fileText;

		Position();
		Position(PositionArgs pA);
		
		int advance(std::string currentChar);
		Position copy();
};

#endif // POSITION_HPP_
