#include "stdafx.h"
#include "conditionClass.h"

#define TIMES_CHECKED 4
extern char playerX;
void printBoard(char board[ROW_LENGTH][COLUMN_LENGTH]);
bool Condition::compare(char input[ROW_LENGTH][COLUMN_LENGTH]) {
	int checkIndex;
	bool rotateMatch;

	printf("\n0 degrees\n");
	//printBoard(pattern);

	//loop through the function, rotate 3 times, check 4 times
	//rotateBoard needs input, rotateArray, and pattern
	// subsequent rotations need pattern = previous 
	char boardToBeRotated[ROW_LENGTH][COLUMN_LENGTH];
	char comparedPatternBoard[ROW_LENGTH][COLUMN_LENGTH];
	copyBoard(comparedPatternBoard, pattern);
	// rotateBoard90(input, rotateArray90, pattern);
	//rotateMatch = confirmBoardRotation(input, rotateArray);

	for (checkIndex = 0; checkIndex < TIMES_CHECKED; checkIndex++) {
		//need to make pattern = previousRotateArray
		rotateMatch = confirmBoardRotation(input, comparedPatternBoard);
		if (rotateMatch) {
			//nextX and nextY will have to change as the boards rotate
			input[nextX][nextY] = playerX;
			return true;
		}
		else
		{
			//nextX doesn't change, but nextY does
			nextY = 2 - nextY;
			//rotate the board
			rotateBoard90(boardToBeRotated, comparedPatternBoard);
			copyBoard(comparedPatternBoard, boardToBeRotated);
		}
	}

	return false;
}

void Condition::rotateBoard90(char rotateArray[ROW_LENGTH][COLUMN_LENGTH], char pattern[ROW_LENGTH][COLUMN_LENGTH]) {
	int rotateRowIndex;
	int rotateColumnIndex;
	bool rotateMatch;
	
	//rotate 90
	for (rotateRowIndex = 0; rotateRowIndex < ROW_LENGTH; rotateRowIndex++)
	{
		for (rotateColumnIndex = 0; rotateColumnIndex < COLUMN_LENGTH; rotateColumnIndex++)
		{
			rotateArray[rotateRowIndex][rotateColumnIndex] = pattern[rotateColumnIndex][2 - rotateRowIndex];
		}
	}
}

bool Condition::confirmBoardRotation(char board1[ROW_LENGTH][COLUMN_LENGTH], char board2[ROW_LENGTH][COLUMN_LENGTH]) {
	int rowIndex;
	int columnIndex;

	for (rowIndex = 0; rowIndex < ROW_LENGTH; rowIndex++) {
		for (columnIndex = 0; columnIndex < COLUMN_LENGTH; columnIndex++) {
			if (board1[rowIndex][columnIndex] != board2[rowIndex][columnIndex]) {
				return false;
			}
		}
	}

	return true;
}

void Condition::copyBoard(char destinationBoard[ROW_LENGTH][COLUMN_LENGTH], char sourceBoard[ROW_LENGTH][COLUMN_LENGTH]) {
	int rowIndex;
	int columnIndex;

	for (rowIndex = 0; rowIndex < ROW_LENGTH; rowIndex++)
	{
		for (columnIndex = 0; columnIndex < COLUMN_LENGTH; columnIndex++)
		{
			destinationBoard[rowIndex][columnIndex] = sourceBoard[rowIndex][columnIndex];
		}
	}
}

//for (rowIndex = 0; rowIndex < ROW_LENGTH; rowIndex++) {
//	for (columnIndex = 0; columnIndex < COLUMN_LENGTH; columnIndex++) {
//		if (input[rowIndex][columnIndex] != pattern[rowIndex][columnIndex]) {
//			goto rotate90;
//		}
//	}
//}

//input[nextX][nextY] = playerX;
//return true;
//
//rotate90:
//char rotateArray90[ROW_LENGTH][COLUMN_LENGTH];
//rotateMatch = rotateBoard90(input, rotateArray90, pattern);
//printf("\n90 degrees\n");
////printBoard(rotateArray90);
//nextX90 = nextX;
//nextY90 = 2 - nextY;
//
//if (rotateMatch) {
//	input[nextX90][nextY90] = playerX;
//	return true;
//}
//
//rotate180:
//char rotateArray180[ROW_LENGTH][COLUMN_LENGTH];
//rotateMatch = rotateBoard90(input, rotateArray180, rotateArray90);
//printf("180 degrees\n");
////printBoard(rotateArray180);
//nextX180 = nextX90;
//nextY180 = 2 - nextY90;
//
//if (rotateMatch) {
//	input[nextX180][nextY180] = playerX;
//	return true;
//}
//
//rotate270:
//char rotateArray270[ROW_LENGTH][COLUMN_LENGTH];
//rotateMatch = rotateBoard90(input, rotateArray270, rotateArray180);
//printf("270 degrees\n");
////printBoard(rotateArray270);
//nextX270 = nextX180;
//nextY270 = 2 - nextY180;
//
//if (rotateMatch) {
//	input[nextX270][nextY270] = playerX;
//	return true;
//}
//
//end: