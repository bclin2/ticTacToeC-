#include "stdafx.h"
#include "conditionClass.h"

extern char playerX;
void printBoard(char board[ROW_LENGTH][COLUMN_LENGTH]);
bool Condition::compare(char input[ROW_LENGTH][COLUMN_LENGTH]) {
	int rowIndex;
	int columnIndex;
	int rotateRowIndex;
	int rotateColumnIndex;

	for (rowIndex = 0; rowIndex < ROW_LENGTH; rowIndex++) {
		for (columnIndex = 0; columnIndex < COLUMN_LENGTH; columnIndex++) {
			if (input[rowIndex][columnIndex] != board[rowIndex][columnIndex]) {
				goto rotateAll;
				// need to break out of the loops instead of returning
			}
		}
	}

	input[nextX][nextY] = playerX;
	return true;
	// rotate and copy
	rotateAll:
	char rotateArray[ROW_LENGTH][COLUMN_LENGTH];

	for (rotateRowIndex = 0; rotateRowIndex < ROW_LENGTH; rotateRowIndex++)
	{
		for (rotateColumnIndex = 0; rotateColumnIndex < COLUMN_LENGTH; rotateColumnIndex++)
		{
			rotateArray[rotateRowIndex][rotateColumnIndex] = input[rotateRowIndex][2 - rotateColumnIndex];
		}
	}

	for (rowIndex = 0; rowIndex < ROW_LENGTH; rowIndex++) {
		for (columnIndex = 0; columnIndex < COLUMN_LENGTH; columnIndex++) {
			if (board[rowIndex][columnIndex] != rotateArray[rowIndex][columnIndex]) {
				return false;
			}
		}
	}

	printBoard(rotateArray);
	//compare rotated condition board

	input[nextX][nextY] = playerX;
	return true;
}