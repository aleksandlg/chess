#pragma once
#include "Figure.hpp"

class Rook :public Figure {
private:
	int cntMoves;
public:
	const int getCntMoves()const { return cntMoves; };
	Rook(const Position& = DEF_POSITION);
	Figure* clone() { return new Rook(*this); };
};
Rook::Rook(const Position& _start) :Figure('r', _start, 28) {
	cntMoves = 0;
	for (int i = 0; i < 7; i++)	//moving to the top
		possible[i] = Position(current.getRow() + (i + 1), current.getColumn());
	for (int i = 7; i < 14; i++)	//moving to the bottom
		possible[i] = Position(current.getRow() - (i + 1), current.getColumn());
	for (int i = 14; i < 21; i++)	//moving to the right
		possible[i] = Position(current.getRow(), current.getColumn() + (14 - i));
	for (int i = 21; i < 28; i++)	//moving ti the left
		possible[i] = Position(current.getRow(), current.getColumn() - (14 - i));
}