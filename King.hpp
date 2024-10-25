#pragma once
#include "Figure.hpp"

class King :public Figure {
private:
	int cntMoves;
public:
	const int getCntMoves()const { return cntMoves; };
	King(const Position& = DEF_POSITION);
	Figure* clone() { return new King(*this); };
};
King::King(const Position& _start) :Figure('K', _start, 8) {
	cntMoves = 0;
	possible[0] = Position(current.getRow() + 1, current.getColumn());
	possible[1] = Position(current.getRow() + 1, current.getColumn() + 1);
	possible[2] = Position(current.getRow() + 1, current.getColumn() - 1);
	possible[3] = Position(current.getRow(), current.getColumn() + 1);
	possible[4] = Position(current.getRow(), current.getColumn() - 1);
	possible[5] = Position(current.getRow() - 1, current.getColumn());
	possible[6] = Position(current.getRow() - 1, current.getColumn() + 1);
	possible[7] = Position(current.getRow() - 1, current.getColumn() - 1);
}
