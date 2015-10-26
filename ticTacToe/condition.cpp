#include "stdafx.h"
#include "conditionClass.h"

extern char playerX;
bool Condition::compare(char input[ROW_LENGTH][COLUMN_LENGTH]) {
	int rowIndex;
	int columnIndex;

	for (rowIndex = 0; rowIndex < ROW_LENGTH; rowIndex++) {
		for (columnIndex = 0; columnIndex < COLUMN_LENGTH; columnIndex++) {
			if (input[rowIndex][columnIndex] != board[rowIndex][columnIndex]) {
				return false;
			}
		}
	}

	input[nextX][nextY] = playerX;
	return true;
}