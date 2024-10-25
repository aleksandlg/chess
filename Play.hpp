#pragma once
#include "headers.h"
#include "Board.hpp"
#include "Player.hpp"

class Play {
private:
	Board boarrd;
	Player whitePlayer;
	Player blackPlayer;
	Figure& getFigureFrom(const Position&);
	bool isPositionFree(const Position&)const;
	bool isFigureWhite(const Figure&)const;
	bool isOwn(const Figure&, const Figure&)const;
public:
	const Board getBoarrd()const { return boarrd; };

	Play(const Player&, const Player&);

	void conquer(const Position&, const Position&);
	bool moveFigure(const Position&, const Position&);

	bool isWhiteKingInCheck()const;
	bool isBlackKingInCheck()const;
	bool Mate(const King&)const;
	bool Castling()const;
	bool EnPassant()const;
};
Play::Play(const Player& _whiteP, const Player& _blackP) {
	boarrd = Board();
	whitePlayer = Player(_whiteP);
	whitePlayer.setFigures(boarrd.getWhite());
	blackPlayer = Player(_blackP);
	blackPlayer.setFigures(boarrd.getBlack());
}
Figure& Play::getFigureFrom(const Position& pos) {
	for (int i = 0; i < 16; i++) {
		if (boarrd.getWhite()[i]->getCurrPosition() == pos)
			return *(boarrd.getWhite()[i]);
		if ((boarrd.getBlack()[i]->getCurrPosition() == pos))
			return *(boarrd.getBlack()[i]);
	}
}
void Play::conquer(const Position& conqueror, const Position& conquered) {
	int row = getFigureFrom(conquered).getCurrPosition().getRow();
	int column = getFigureFrom(conquered).getCurrPosition().getColumn();
	delete boarrd.getBoard()[row][column];
	getFigureFrom(conqueror).setCurrPosition(conquered);
}
bool Play::isPositionFree(const Position& position)const {
	return (boarrd.getBoard()[position.getRow()][position.getColumn()] == nullptr);
}
bool Play::isFigureWhite(const Figure& figure)const {
	if (figure.getStartPosition().getRow() == 6 || figure.getStartPosition().getRow() == 7)
		return true;
	else return false;
}
bool Play::isOwn(const Figure& mine, const Figure& other)const {
	if (!(mine == other))
		if (isFigureWhite(mine) && isFigureWhite(other) || !(isFigureWhite(mine) && isFigureWhite(other)))
			return true;
		else return false;
	else return true;
}
bool Play::isBlackKingInCheck()const {
	for (int i = 0; i < 16 && i != 12; i++) {	//for each figure in the opposing set
		const Position* enemyPossitions = boarrd.getWhite()[i]->getPossible();	//get it's possible positions
		const int enemyLimit = boarrd.getWhite()[i]->getNumPossible();	//get their number
		for (int j = 0; j < enemyLimit; j++) //and for every possition 
			if (enemyPossitions[j] == boarrd.getBlack()[12]->getCurrPosition()) {//check if the king is on one of them
				int rowOfEnemy = enemyPossitions[j].getRow();	//if so get the enemy's row and column
				int columnOfEnemy = enemyPossitions[j].getColumn();
				int rowOfKing = boarrd.getBlack()[12]->getCurrPosition().getRow();	//and the king's row and column
				int columnOfKing = boarrd.getBlack()
[12]->getCurrPosition().getColumn();
				if (rowOfEnemy >= rowOfKing && columnOfEnemy >= columnOfKing) {	//and for every possition in the rectangle circuled by them
					for (int k = rowOfKing; k < rowOfEnemy; k++) {
						for (int l = columnOfKing; l < columnOfEnemy; l++)
							if (!isPositionFree(Position(k, l)))	//check if that possition is vacant
								for (int p = 0; p < enemyLimit; p++)
									if (enemyPossitions[p] == Position(k, l))
										return true;
					}
					if (rowOfEnemy < rowOfKing && columnOfEnemy < columnOfKing) {
						for (int k = rowOfEnemy; k < rowOfKing; k++)
							for (int l = columnOfEnemy; l < columnOfKing; l++)
								if (!isPositionFree(Position(k, l)))
									for (int p = 0; p < enemyLimit; p++)
										if (enemyPossitions[p] == Position(k, l))
											return true;
					}
					if (rowOfEnemy < rowOfKing && columnOfEnemy >= columnOfKing) {
						for (int k = rowOfEnemy; k < rowOfKing; k++)
							for (int l = columnOfKing; l < columnOfEnemy; l++)
								if (!isPositionFree(Position(k, l)))
									for (int p = 0; p < enemyLimit; p++)
										if (enemyPossitions[p] == Position(k, l))
											return true;
					}
					if (rowOfEnemy >= rowOfKing && columnOfEnemy < columnOfKing) {
						for (int k = rowOfKing; k < rowOfEnemy; k++)
							for (int l = columnOfEnemy; l < columnOfKing; l++)
								if (!isPositionFree(Position(k, l)))
									for (int p = 0; p < enemyLimit; p++)
										if (enemyPossitions[p] == Position(k, l))
											return true;
					}
				}
			}

	}
	return false;
}
bool Play::moveFigure(const Position& from, const Position& to) {
	if (!isPositionFree(from) && from.isValid() && to.isValid()) {	//if 'from' position is valid and isn't empty
		if (isPositionFree(to)) {		//check if the other position is ocupied
			getFigureFrom(from).setCurrPosition(to);	//if not just 
			return true;
		}
		else {
			if (isOwn(getFigureFrom(from), getFigureFrom(to))) return false;
			else {
				conquer(from, to);
				return true;
			}
		}
	}
	return false;	//if 'from' position is empty tf you expect from me
}
