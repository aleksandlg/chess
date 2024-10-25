#pragma once
#include <cstring>
#include "Figure.hpp"

class Player {
private:
	char* name;
	int result;
	Figure** figures;
	void copyPlayer(const Player&);
	void deletePlayer();
public:
	void setFigures(Figure**);
	Player(const char* = " ");
	Player(const Player&);
	~Player();
	Player& operator=(const Player&);
	bool writeInFile();
};
void Player::setFigures(Figure** newFigures) {
	for (int i = 0; i < 16; i++)
		figures[i] = newFigures[i];
}
Player::Player(const char* _name) {
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	result = -1;
	figures = new Figure*[16];
	for (int i = 0; i < 16; i++)
		figures[i] = nullptr;
}
void Player::copyPlayer(const Player& other) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	result = other.result;
	figures = new Figure*[16];
	for (int i = 0; i < 16; i++)
		figures[i] = other.figures[i];
}
void Player::deletePlayer() {
	for (int i = 0; i < 16; i++)
		delete figures[i];
	delete[]figures;
}
Player::Player(const Player& other) {
	copyPlayer(other);
}
Player::~Player() {
	deletePlayer();
}
Player& Player::operator=(const Player& other) {
	if (this != &other) {
		deletePlayer();
		copyPlayer(other);
	}
	return *this;
}