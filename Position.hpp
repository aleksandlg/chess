#pragma once

class Position {
private:
	int row;
	int column;
public:
	const int getRow()const { return row; };
	const int getColumn()const { return column; };
	//void setRow(int newRow) { row = newRow; };
	//void setColumn(int newColumn) { column = newColumn; };

	Position(const int = -1, const int = -1);
	bool isValid()const;
	bool operator==(const Position&)const;
};
Position::Position(const int _row, const int _column) {
	row = _row;
	column = _column;
}
bool Position::isValid()const {
	return (row >= 1 && row <= 8 && column >= 1 && column <= 8);
}
bool Position::operator==(const Position& other)const {
	return ((row == other.row) && (column == other.column));
}

const Position DEF_POSITION;