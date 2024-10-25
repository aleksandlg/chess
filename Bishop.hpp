#pragma once
#include "Figure.hpp"

class Bishop :public Figure {
private:

public:
	Bishop(const Position& = DEF_POSITION);
	Figure* clone() { return new Bishop(*this); };
};
Bishop::Bishop(const Position& _start) :Figure('b', _start, 28) {
	for (int i = 0; i < 7; i++) {
		//upper right diagonal
		possible[i] = Position(current.getRow() + (i + 1), current.getColumn() + (i + 1));
		//upper left diagonal
		possible[i + 7] = Position(current.getRow() + (i + 1), current.getColumn() - (i + 1));
		//lower right diagonal
		possible[i + 14] = Position(current.getRow() - (i + 1), current.getColumn() + (i + 1));
		//lower left diagonal
		possible[i + 21] = Position(current.getRow() - (i + 1), current.getColumn() - (i + 1));
	}
}