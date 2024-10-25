#pragma once
#include "Figure.hpp"

class Knight :public Figure {
private:

public:
	Knight(const Position& = DEF_POSITION);
	Figure* clone() { return new Knight(*this); };
};
Knight::Knight(const Position& _start) :Figure('k', _start, 8) {
	//up and right/left
	possible[0] = Position(current.getRow() + 2, current.getColumn() + 1);
	possible[1] = Position(current.getRow() + 2, current.getColumn() - 1);
	//down and right/left
	possible[2] = Position(current.getRow() - 2, current.getColumn() + 1);
	possible[3] = Position(current.getRow() - 2, current.getColumn() - 1);
	//right and top/bottom
	possible[4] = Position(current.getRow() + 1, current.getColumn() + 2);
	possible[5] = Position(current.getRow() - 1, current.getColumn() + 2);
	//left and top/bottom
	possible[6] = Position(current.getRow() + 1, current.getColumn() - 2);
	possible[7] = Position(current.getRow() - 1, current.getColumn() - 2);
}
