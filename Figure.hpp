#pragma once
#include "Position.hpp"

class Figure {
protected:
	char name;
	Position start;
	Position current;
	int numPossible;
	Position* possible;
	void copyFigure(const char, const Position&, int);
public:
	virtual Figure* clone() = 0;

	void setCurrPosition(const Position& newPosition) { this->current = newPosition; };

	const int getNumPossible()const { return numPossible; };
	const Position* getPossible()const { return possible; };
	char getName()const { return name; };
	const Position getCurrPosition()const { return current; };
	const Position getStartPosition()const { return start; };

	Figure();
	Figure(const char, const Position&, int);
	Figure(const Figure&);
	virtual ~Figure();
	Figure& operator=(const Figure&);

	bool operator==(const Figure&)const;
};
void Figure::copyFigure(const char _name, const Position& _start, int _numPossible) {
	name = _name;
	start = _start;
	current = _start;
	numPossible = _numPossible;
	possible = new Position[numPossible];
}
Figure::Figure() {
	name = ' ';
	start = DEF_POSITION;
	current = DEF_POSITION;
	numPossible = 0;
	possible = new Position[numPossible];
}
Figure::Figure(const char _name, const Position& _start, int _numPossible):Figure() {
	copyFigure(_name, _start, _numPossible);
}
Figure::Figure(const Figure& other):Figure() {
	copyFigure(other.name, other.start, other.numPossible);
}
Figure::~Figure() {
	delete[]possible;
}
Figure& Figure::operator=(const Figure& other) {
	if (this != &other) {
		delete[]this->possible;
		copyFigure(other.name, other.start, other.numPossible);
		current = other.current;
		if (numPossible > 0)
			for (int i = 0; i < numPossible; i++)
				possible[i] = other.possible[i];
	}
	return *this;
}
bool Figure::operator==(const Figure& other)const {
	return other.getName() == this->getName() && other.numPossible == this->numPossible &&
		other.getStartPosition() == this->getStartPosition();
}