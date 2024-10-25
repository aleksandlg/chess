#pragma once
#include <iostream>
#include "headers.h"

class Board {
private:
	Figure*** board;
	int cntWhite;
	Figure** white;
	int cntBlack;
	Figure** black;
	void setWhite();
	void setBlack();
	void copyBoard(const Board& other);
	void deleteBoard();
public:
	Figure** getWhite()const { return white; };
	Figure** getBlack()const { return black; };
	Figure*** getBoard()const { return board; };

	Board();
	Board(const Board&);
	~Board();
	Board& operator=(const Board&);

	friend std::ostream& operator<<(std::ostream&, const Board&);
};
void Board::setWhite() {
	cntWhite = 16;
	white = new Figure*[cntWhite];
	for (int i = 0; i < 8; i++) {
		Pawn pn(Position(6, i));
		white[i] = pn.clone();
	}
	Rook rk1(Position(7, 0));
	white[8] = rk1.clone();
	Rook rk2(Position(7, 7));
	white[15] = rk2.clone();
	Knight kn1(Position(7, 1));
	white[9] = kn1.clone();
	Knight kn2(Position(7, 6));
	white[14] = kn2.clone();
	Bishop bs1(Position(7, 2));
	white[10] = bs1.clone();
	Bishop bs2(Position(7, 5));
	white[13] = bs2.clone();
	Queen q(Position(7, 3));
	white[11] = q.clone();
	King k(Position(7, 4));
	white[12] = k.clone();
}
void Board::setBlack() {
	cntBlack = 16;
	black = new Figure*[cntBlack];
	for (int i = 0; i < 8; i++) {
		Pawn p(Position(1, i));
		black[i] = p.clone();
	}
	Rook r1(Position(0, 0));
	black[8] = r1.clone();
	Rook r2(Position(0, 7));
	black[15] = r2.clone();
	Knight k1(Position(0, 1));
	black[9] = k1.clone();
	Knight k2(Position(0, 6));
	black[14] =k2.clone();
	Bishop b1(Position(0, 2));
	black[10] = b1.clone();
	Bishop b2(Position(0, 5));
	black[13] = b2.clone();
	Queen q(Position(0, 3));
	black[11] = q.clone();
	King k(Position(0, 4));
	black[12] = k.clone();
}

Board::Board() {
	board = new Figure**[8];
	for (int i = 0; i < 8; i++)
		board[i] = new Figure*[8];
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = nullptr;
	setWhite();
	setBlack();
	for (int i = 0; i < 8; i++) {
		board[6][i] = white[i];
		board[7][i] = white[8 + i];
		board[1][i] = black[i];
		board[0][i] = black[8 + i];
	 }
}
void Board::copyBoard(const Board& other) {
	board = new Figure**[8];
	for (int i = 0; i < 8; i++)
		board[i] = new Figure*[8];
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = other.board[i][j]->clone();
	setWhite();
	setBlack();
}
Board::Board(const Board& other) {
	copyBoard(other);
}
void Board::deleteBoard() {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			delete board[i][j];
	for (int i = 0; i < 8; i++)
		delete[] board[i];
	delete[]board;
}
Board::~Board() {
	deleteBoard();
}
Board& Board::operator=(const Board& other) {
	if (this != &other) {
		deleteBoard();
		copyBoard(other);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Board& other) {
	for (int i = 0; i < 8; i++) {
		os << "   + = + = + = + = + = + = + = + = +" << std::endl;
		os << ' ' << 8 - i << ' ';
		for (int j = 0; j < 8; j++)
			if(other.board[i][j])
			os << "| " << other.board[i][j]->getName() << " ";
			else os << "| " << ' ' << " ";
		os << "|" << std::endl;
	}
	os << "   + = + = + = + = + = + = + = + = +" << std::endl;
	os << "     A   B   C   D   E   F   G   H";
	return os;
}

//const Board DEF_BOARD;