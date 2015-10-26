#define ROW_LENGTH 3
#define COLUMN_LENGTH 3

class Condition {
public: 
	char board[ROW_LENGTH][COLUMN_LENGTH];
	int nextX;
	int nextY;
	Condition(int arg00, int arg01, int arg02, int arg10, int arg11, int arg12, int arg20, int arg21, int arg22, int argNextX, int argNextY)
	{
		board[0][0] = arg00;
		board[0][1] = arg01;
		board[0][2] = arg02;
		board[1][0] = arg10;
		board[1][1] = arg11;
		board[1][2] = arg12;
		board[2][0] = arg20;
		board[2][1] = arg21;
		board[2][2] = arg22;
		nextX = argNextX;
		nextY = argNextY;
	}

	bool compare(char board[ROW_LENGTH][COLUMN_LENGTH]);
};