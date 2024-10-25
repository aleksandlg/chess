#pragma once
#include "Figure.hpp"

class Queen :public Figure {
private:

public:
	Queen(const Position& = DEF_POSITION);
	Figure* clone() { return new Queen(*this); };
};
Queen::Queen(const Position& _start) :Figure('q', _start, 56) {
	//the rook part
	for (int i = 0; i < 7; i++)
		possible[i] = Position(current.getRow() + (i + 1), current.getColumn());
	for (int i = 7; i < 14; i++)
		possible[i] = Position(current.getRow() - (i + 1), current.getColumn());
	for (int i = 14; i < 21; i++)
		possible[i] = Position(current.getRow(), current.getColumn() + (14 - i));
	for (int i = 21; i < 28; i++)
		possible[i] = Position(current.getRow(), current.getColumn() - (14 - i));
	//the bishop part
	for (int i = 28; i < 35; i++) {
		possible[i] = Position(current.getRow() + (i + 1), current.getColumn() + (i + 1));
		possible[i + 7] = Position(current.getRow() + (i + 1), current.getColumn() - (i + 1));
		possible[i + 14] = Position(current.getRow() - (i + 1), current.getColumn() + (i + 1));
		possible[i + 21] = Position(current.getRow() - (i + 1), current.getColumn() - (i + 1));
	}
}