// ticTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "conditionClass.h"

#define ROW_LENGTH 3
#define COLUMN_LENGTH 3
void inputCoordinates(char board[ROW_LENGTH][COLUMN_LENGTH]);
void randomComputerMove(char board[ROW_LENGTH][COLUMN_LENGTH]);
void printBoard(char board[ROW_LENGTH][COLUMN_LENGTH]);
char checkWin(char board[ROW_LENGTH][COLUMN_LENGTH]);
void smarterComputerMove(char board[ROW_LENGTH][COLUMN_LENGTH]);
void calculateNextMove(char board[ROW_LENGTH][COLUMN_LENGTH]);
int findEmptySpaceRow(char board[ROW_LENGTH]);
int findEmptySpaceColumn(char board[ROW_LENGTH][COLUMN_LENGTH], int columnIndex);
char playerX = 'X';
char playerO = 'O';
char emptySpace = '.';

Condition condition1(playerO, emptySpace, emptySpace, 
					 emptySpace, playerX, emptySpace, 
					 emptySpace, emptySpace, playerO,
					 0, 1);

Condition condition2(playerO, emptySpace, emptySpace,
					 emptySpace, playerO, emptySpace,
					 emptySpace, emptySpace, playerX, 
					 0, 2);

Condition condition3(emptySpace, emptySpace, emptySpace,
					 emptySpace, playerO, emptySpace,
					 emptySpace, emptySpace, emptySpace,
					 0, 0);

int main()
{
	//char testBoard[ROW_LENGTH][COLUMN_LENGTH] = {
	//	emptySpace, emptySpace, emptySpace,
	//	emptySpace, playerO, emptySpace,
	//	emptySpace, emptySpace, emptySpace
	//};
	//printBoard(testBoard);
	//smarterComputerMove(testBoard);
	//printBoard(testBoard);
	//_getch();
	//return 0;
	char board[ROW_LENGTH][COLUMN_LENGTH];
	for (int rowIndex = 0; rowIndex < ROW_LENGTH; rowIndex++) {
		for (int columnIndex = 0; columnIndex < COLUMN_LENGTH; columnIndex++) {
			board[rowIndex][columnIndex] = '.';
		}
	}

	int seed = time(NULL);
	srand(seed);
	char winner;
	inputCoordinates(board);
	printBoard(board);
	smarterComputerMove(board);
	printBoard(board);

	inputCoordinates(board);
	printBoard(board);
	smarterComputerMove(board);
	printBoard(board);

	inputCoordinates(board);
	winner = checkWin(board);
	if (winner) { goto gameEnd; }
	printBoard(board);
	smarterComputerMove(board);
	winner = checkWin(board);
	if (winner) { goto gameEnd; }
	printBoard(board);

	inputCoordinates(board);
	winner = checkWin(board);
	if (winner) { goto gameEnd; }
	printBoard(board);
	smarterComputerMove(board);
	winner = checkWin(board);
	if (winner) { goto gameEnd; }
	printBoard(board);

	inputCoordinates(board);
	winner = checkWin(board);
	if (winner) { goto gameEnd; }
	printBoard(board);


	gameEnd:
	if (winner) {
		printf("\n%c WIN!\n", winner);
		printBoard(board);
	}
	else {
		printf("\nTIE!\n");
		printBoard(board);
	}

	_getch();
	return 0;
}

void inputCoordinates(char board[ROW_LENGTH][COLUMN_LENGTH]) {
	int rowCoordinate = 0;
	int columnCoordinate = 0;
	char playerAvatar = playerO;
	scanf_s("%d", &rowCoordinate);
	scanf_s("%d", &columnCoordinate);
	char currentChar = board[rowCoordinate][columnCoordinate];
	while (currentChar == playerX || currentChar == 'O') {
		printf("spot already taken, give new coordinates\n");
		scanf_s("%d", &rowCoordinate);
		scanf_s("%d", &columnCoordinate);
		currentChar = board[rowCoordinate][columnCoordinate];
	}
	board[rowCoordinate][columnCoordinate] = playerAvatar;
}

void smarterComputerMove(char board[ROW_LENGTH][COLUMN_LENGTH]) {
	char middleChar = board[1][1];
	//get middle
	if (middleChar != playerO && middleChar == '.') {
		board[1][1] = playerX;
		return;
	}

	calculateNextMove(board);
}

void calculateNextMove(char board[ROW_LENGTH][COLUMN_LENGTH]) {
	int rowIndex;
	int columnIndex;
	int countPlayerO;
	int countPlayerX;
	int emptySpaceColumnIndex;
	int emptySpaceRowIndex;
	bool conditionResult;

	//check condition
	conditionResult = condition1.compare(board);
	if (conditionResult) {
		printf("Condition is true\n");
		return;
	}

	conditionResult = condition2.compare(board);
	if (conditionResult) {
		printf("Condition is true\n");
		return;
	}

	conditionResult = condition3.compare(board);
	if (conditionResult) {
		printf("Condition is true\n");
		return;
	}

	//check horizontal
	printf("Horizontal\n");
	for (rowIndex = 0; rowIndex < ROW_LENGTH; rowIndex++) {
		countPlayerX = 0;
		for (columnIndex = 0; columnIndex < COLUMN_LENGTH; columnIndex++) {
			// if player counter reaches 2, find empty space in row
				//make it return the empty space's index in that row
			if (board[rowIndex][columnIndex] == playerX) {
				countPlayerX++;
			}
		}

		if (countPlayerX == ROW_LENGTH - 1) {
			emptySpaceColumnIndex = findEmptySpaceRow(board[rowIndex]);
			if (emptySpaceColumnIndex != -1){
				board[rowIndex][emptySpaceColumnIndex] = playerX;
				return;
			}
		}
	}

	for (rowIndex = 0; rowIndex < ROW_LENGTH; rowIndex++) {
		countPlayerO = 0;
		for (columnIndex = 0; columnIndex < COLUMN_LENGTH; columnIndex++) {
			// if player counter reaches 2, find empty space in row
			//make it return the empty space's index in that row
			if (board[rowIndex][columnIndex] == playerO) {
				countPlayerO++;
			}
		}

		if (countPlayerO == ROW_LENGTH - 1) {
			emptySpaceColumnIndex = findEmptySpaceRow(board[rowIndex]);
			if (emptySpaceColumnIndex != -1) {
				board[rowIndex][emptySpaceColumnIndex] = playerX;
				return;
			}
		}
	}

	printf("Vertical\n");
	//vertical
	for (columnIndex = 0; columnIndex < COLUMN_LENGTH; columnIndex++) {
		countPlayerX = 0;
		for (rowIndex = 0; rowIndex < ROW_LENGTH; rowIndex++) {
			if (board[rowIndex][columnIndex] == playerX) {
				countPlayerX++;
			}
		}
		if (countPlayerX == COLUMN_LENGTH - 1) {
			// I need to give it the board, but I should also give column index
			emptySpaceRowIndex = findEmptySpaceColumn(board, columnIndex);
			if (emptySpaceRowIndex != -1) {
				board[emptySpaceRowIndex][columnIndex] = playerX;
				return;
			}
		}
	}

	for (columnIndex = 0; columnIndex < COLUMN_LENGTH; columnIndex++) {
		countPlayerO = 0;
		for (rowIndex = 0; rowIndex < ROW_LENGTH; rowIndex++) {
			if (board[rowIndex][columnIndex] == playerO) {
				countPlayerO++;
			}
		}

		if (countPlayerO == COLUMN_LENGTH - 1) {
			emptySpaceRowIndex = findEmptySpaceColumn(board, columnIndex);
			if (emptySpaceRowIndex != -1) {
				board[emptySpaceRowIndex][columnIndex] = playerX;
				return;
			}
		}
	}

	//diagonal
	printf("Diagonal\n");

	// NW to SE
	// go for the win
	if (board[0][0] == playerX && board[2][2] == playerX) {
		if (board[1][1] == '.') {
			board[1][1] = playerX;
			return;
		}
	}

	if (board[1][1] == playerX && board[0][0] == playerX) {
		if (board[2][2] == '.') {
			board[2][2] = playerX;
			return;
		}
	}

	if (board[1][1] == playerX && board[2][2] == playerX) {
		if (board[0][0] == '.') {
			board[0][0] = playerX;
			return;
		}
	}

	//prevent playerO from winning
	if (board[0][0] == playerO && board[2][2] == playerO) {
		if (board[1][1] == '.') {
			board[1][1] = playerX;
			return;
		}
	}

	if (board[1][1] == playerO && board[0][0] == playerO) {
		if (board[2][2] == '.') {
			board[2][2] = playerX;
			return;
		}
	}

	if (board[1][1] == playerO && board[2][2] == playerO) {
		if (board[0][0] == '.') {
			board[0][0] = playerX;
			return;
		}
	}

	// SW to NE
	// Go for the win
	if (board[0][2] == playerX && board[2][0] == playerX) {
		if (board[1][1] == '.') {
			board[1][1] = playerX;
			return;
		}
	}

	if (board[0][2] == playerX && board[1][1] == playerX) {
		if (board[2][0] == '.') {
			board[2][0] = playerX;
			return;
		}
	}

	if (board[2][0] == playerX && board[1][1] == playerX) {
		if (board[0][2] == '.') {
			board[0][2] = playerX;
			return;
		}
	}

	// prevent playerO from winning
	if (board[0][2] == playerO && board[2][0] == playerO) {
		if (board[1][1] == '.') {
			board[1][1] = playerX;
			return;
		}
	}

	if (board[0][2] == playerO && board[1][1] == playerO) {
		if (board[2][0] == '.') {
			board[2][0] = playerX;
			return;
		}
	}

	if (board[2][0] == playerO && board[1][1] == playerO) {
		if (board[0][2] == '.') {
			board[0][2] = playerX;
			return;
		}
	}

	//if none of the horizontal/vertical/diagonal checks work, then choose a random diagonal spot.
	printf("Random\n");
	randomComputerMove(board);
}

int findEmptySpaceRow(char board[ROW_LENGTH]) {
	int columnIndex;

	for (columnIndex = 0; columnIndex < ROW_LENGTH; columnIndex++) {
		if (board[columnIndex] == '.') {
			return columnIndex;
		}
	}

	return -1;
}

int findEmptySpaceColumn(char board[ROW_LENGTH][COLUMN_LENGTH], int columnIndex) {
	int rowIndex;

	for (rowIndex = 0; rowIndex < ROW_LENGTH; rowIndex++) {
		if (board[rowIndex][columnIndex] == '.') {
			return rowIndex;
		}
	}

	return -1;
}

void randomComputerMove(char board[ROW_LENGTH][COLUMN_LENGTH]) {
	int rowRandom;
	int columnRandom;
	char currentChar;

	do {
		rowRandom = rand() % ROW_LENGTH;
		columnRandom = rand() % COLUMN_LENGTH;
		currentChar = board[rowRandom][columnRandom];
	} while (currentChar == playerX || currentChar == playerO);

	board[rowRandom][columnRandom] = playerX;
}

char checkWin(char board[ROW_LENGTH][COLUMN_LENGTH]) {
	int rowIndex;
	int columnIndex;
	int index;
	int countPlayerO;
	int countPlayerX;
	//check horizontal
	for (rowIndex = 0; rowIndex < ROW_LENGTH; rowIndex++) {
		countPlayerO = 0;
		countPlayerX = 0;
		for (columnIndex = 0; columnIndex < COLUMN_LENGTH; columnIndex++) 
		{
			if (board[rowIndex][columnIndex] == playerO)
			{
				countPlayerO++;
			}
			else if (board[rowIndex][columnIndex] == playerX) {
				countPlayerX++;
			}
		}
		if (countPlayerO == COLUMN_LENGTH) {
			return playerO;
		}
		else if (countPlayerX == COLUMN_LENGTH) {
			return playerX;
		}
	}
	//check vertical
	for (columnIndex = 0; columnIndex < COLUMN_LENGTH; columnIndex++) {
		countPlayerO = 0;
		countPlayerX = 0;
		for (rowIndex = 0; rowIndex < ROW_LENGTH; rowIndex++) {
			if (board[rowIndex][columnIndex] == playerO)
			{
				countPlayerO++;
			}
			else if (board[rowIndex][columnIndex] == playerX) {
				countPlayerX++;
			}
		}
		if (countPlayerO == COLUMN_LENGTH) {
			return playerO;
		}
		else if (countPlayerX == COLUMN_LENGTH) {
			return playerX;
		}
	}
	//check diagonal
	if ((board[1][1] == playerO && board[0][0] == playerO && board[2][2] == playerO) || (board[1][1] == playerO && board[0][2] == playerO && board[2][0] == playerO)) {
		return playerO;
	}

	countPlayerO = 0;
	countPlayerX = 0;
	for (index = 0; index < ROW_LENGTH; index++) {
		if (board[index][index] == playerO) {
			countPlayerO++;
		}
		else if (board[index][index] == playerX) {
			countPlayerX++;
		}
	}

	if (countPlayerO == ROW_LENGTH) {
		return playerO;
	}
	else if (countPlayerX == ROW_LENGTH) {
		return playerX;
	}

	countPlayerO = 0;
	countPlayerX = 0;
	for (index = 0; index < ROW_LENGTH; index++) {
		if (board[index][2 - index] == playerO) {
			countPlayerO++;
		}
		else if (board[index][2 - index] == playerX) {
			countPlayerX++;
		}
	}

	if (countPlayerO == ROW_LENGTH) {
		return playerO;
	}
	else if (countPlayerX == ROW_LENGTH) {
		return playerX;
	}

	return 0;
}

void printBoard(char board[ROW_LENGTH][COLUMN_LENGTH]) 
{
	int rowIndex = 0;
	int columnIndex = 0;
	for (rowIndex = 0; rowIndex < ROW_LENGTH; rowIndex++) {
		for (columnIndex = 0; columnIndex < COLUMN_LENGTH; columnIndex++) {
			printf("%c  ", board[rowIndex][columnIndex]);
		}
		printf("\n");
	}
	printf("\n");
}

