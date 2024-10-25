#pragma once
#include "Figure.hpp"

class Pawn :public Figure {
private:

public:
	Pawn(const Position& = DEF_POSITION);
	Figure* clone() { return new Pawn(*this); };
	bool atTheOtherEndOfBoard()const;
};
Pawn::Pawn(const Position& _start) :Figure('p', _start, 4) {
	//when makin the first move pawns can move two squares front
	possible[0] = Position(current.getRow() + 2, current.getColumn());
	//the usual move - one square to the front
	possible[1] = Position(current.getRow() + 1, current.getColumn());
	//if conquering to the right
	possible[2] = Position(current.getRow() + 1, current.getColumn() + 1);
	//if conquering ti the left
	possible[3] = Position(current.getRow() + 1, current.getColumn() - 1);
}
