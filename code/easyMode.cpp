#include <iostream>
using namespace std;

void printMaze()
{
	char** mazeBoard = new char* [10];

	for (int i = 0; i < 10; i++)
	{
		mazeBoard[i] = new char[10];
	}

	mazeBoard[0][0] = 'S';
	mazeBoard[0][1] = '1';
	mazeBoard[0][2] = '0';
	mazeBoard[0][3] = '0';
	mazeBoard[0][4] = '0';
	mazeBoard[0][5] = '0';
	mazeBoard[0][6] = '0';
	mazeBoard[0][7] = '0';
	mazeBoard[0][8] = '0';
	mazeBoard[0][9] = '0';
	mazeBoard[1][0] = '1';
	mazeBoard[1][1] = '1';
	mazeBoard[1][2] = '0';
	mazeBoard[1][3] = '0';
	mazeBoard[1][4] = '0';
	mazeBoard[1][5] = '0';
	mazeBoard[1][6] = '0';
	mazeBoard[1][7] = '0';
	mazeBoard[1][8] = '0';
	mazeBoard[1][9] = '0';
	mazeBoard[2][0] = '0';
	mazeBoard[2][1] = '1';
	mazeBoard[2][2] = '0';
	mazeBoard[2][3] = '0';
	mazeBoard[2][4] = '1';
	mazeBoard[2][5] = '1';
	mazeBoard[2][6] = '1';
	mazeBoard[2][7] = '0';
	mazeBoard[2][8] = '0';
	mazeBoard[2][9] = '0';
	mazeBoard[3][0] = '0';
	mazeBoard[3][1] = '1';
	mazeBoard[3][2] = '1';
	mazeBoard[3][3] = '0';
	mazeBoard[3][4] = '1';
	mazeBoard[3][5] = '0';
	mazeBoard[3][6] = '1';
	mazeBoard[3][7] = '1';
	mazeBoard[3][8] = '1';
	mazeBoard[3][9] = '0';
	mazeBoard[4][0] = '0';
	mazeBoard[4][1] = '0';
	mazeBoard[4][2] = '1';
	mazeBoard[4][3] = '0';
	mazeBoard[4][4] = '1';
	mazeBoard[4][5] = '0';
	mazeBoard[4][6] = '1';
	mazeBoard[4][7] = '0';
	mazeBoard[4][8] = '1';
	mazeBoard[4][9] = '0';
	mazeBoard[5][0] = '0';
	mazeBoard[5][1] = '0';
	mazeBoard[5][2] = '1';
	mazeBoard[5][3] = '1';
	mazeBoard[5][4] = '1';
	mazeBoard[5][5] = '0';
	mazeBoard[5][6] = '1';
	mazeBoard[5][7] = '0';
	mazeBoard[5][8] = '1';
	mazeBoard[5][9] = '0';
	mazeBoard[6][0] = '0';
	mazeBoard[6][1] = '0';
	mazeBoard[6][2] = '0';
	mazeBoard[6][3] = '0';
	mazeBoard[6][4] = '0';
	mazeBoard[6][5] = '0';
	mazeBoard[6][6] = '1';
	mazeBoard[6][7] = '1';
	mazeBoard[6][8] = '0';
	mazeBoard[6][9] = '0';
	mazeBoard[7][0] = '0';
	mazeBoard[7][1] = '1';
	mazeBoard[7][2] = '1';
	mazeBoard[7][3] = '1';
	mazeBoard[7][4] = '1';
	mazeBoard[7][5] = '1';
	mazeBoard[7][6] = '1';
	mazeBoard[7][7] = '0';
	mazeBoard[7][8] = '1';
	mazeBoard[7][9] = '0';
	mazeBoard[8][0] = '0';
	mazeBoard[8][1] = '0';
	mazeBoard[8][2] = '1';
	mazeBoard[8][3] = '0';
	mazeBoard[8][4] = '0';
	mazeBoard[8][5] = '0';
	mazeBoard[8][6] = '1';
	mazeBoard[8][7] = '1';
	mazeBoard[8][8] = '1';
	mazeBoard[8][9] = '1';
	mazeBoard[9][0] = '0';
	mazeBoard[9][1] = '0';
	mazeBoard[9][2] = '0';
	mazeBoard[9][3] = '0';
	mazeBoard[9][4] = '0';
	mazeBoard[9][5] = '0';
	mazeBoard[9][6] = '0';
	mazeBoard[9][7] = '0';
	mazeBoard[9][8] = '1';
	mazeBoard[9][9] = 'F';

	cout << "Easy mode - 10 x 10" << endl;
	cout << "Your current possition is [0][0]" << endl;
	cout << "The final is located on position [9][9]" << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "  ";
		for (int j = 0; j < 10; j++)
		{
			cout << mazeBoard[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < 10; i++)
	{
		delete[] mazeBoard[i];
	}
}

int main()
{
	printMaze();
}

