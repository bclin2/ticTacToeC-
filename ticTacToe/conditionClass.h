#define ROW_LENGTH 3
#define COLUMN_LENGTH 3

class Condition {
public: 
	char pattern[ROW_LENGTH][COLUMN_LENGTH];
	int nextX;
	int nextY;
	Condition(int arg00, int arg01, int arg02, int arg10, int arg11, int arg12, int arg20, int arg21, int arg22, int argNextX, int argNextY)
	{
		pattern[0][0] = arg00;
		pattern[0][1] = arg01;
		pattern[0][2] = arg02;
		pattern[1][0] = arg10;
		pattern[1][1] = arg11;
		pattern[1][2] = arg12;
		pattern[2][0] = arg20;
		pattern[2][1] = arg21;
		pattern[2][2] = arg22;
		nextX = argNextX;
		nextY = argNextY;
	}

	bool compare(char input[ROW_LENGTH][COLUMN_LENGTH]);
private:
	void rotateBoard90(char rotateArray[ROW_LENGTH][COLUMN_LENGTH], char pattern[ROW_LENGTH][COLUMN_LENGTH]);
	bool confirmBoardRotation(char board1[ROW_LENGTH][COLUMN_LENGTH], char board2[ROW_LENGTH][COLUMN_LENGTH]);
	void copyBoard(char destinationBoard[ROW_LENGTH][COLUMN_LENGTH], char sourceBoard[ROW_LENGTH][COLUMN_LENGTH]);
};