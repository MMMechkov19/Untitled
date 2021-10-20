#include <iostream>
#include <conio.h>
using namespace std;

const int declareMazeExample()
{
	const int** mazeReference = new const int* [10];

	for (int i = 0; i < 10; i++)
	{
		mazeReference[i] = new const int[10];
	}

	mazeReference[0][0] = 2;
	mazeReference[0][1] = 1;
	mazeReference[0][2] = 0;
	mazeReference[0][3] = 0;
	mazeReference[0][4] = 0;
	mazeReference[0][5] = 0;
	mazeReference[0][6] = 0;
	mazeReference[0][7] = 0;
	mazeReference[0][8] = 0;
	mazeReference[0][9] = 0;
	mazeReference[1][0] = 1;
	mazeReference[1][1] = 1;
	mazeReference[1][2] = 0;
	mazeReference[1][3] = 0;
	mazeReference[1][4] = 0;
	mazeReference[1][5] = 0;
	mazeReference[1][6] = 0;
	mazeReference[1][7] = 0;
	mazeReference[1][8] = 0;
	mazeReference[1][9] = 0;
	mazeReference[2][0] = 0;
	mazeReference[2][1] = 1;
	mazeReference[2][2] = 0;
	mazeReference[2][3] = 0;
	mazeReference[2][4] = 1;
	mazeReference[2][5] = 1;
	mazeReference[2][6] = 1;
	mazeReference[2][7] = 0;
	mazeReference[2][8] = 0;
	mazeReference[2][9] = 0;
	mazeReference[3][0] = 0;
	mazeReference[3][1] = 1;
	mazeReference[3][2] = 1;
	mazeReference[3][3] = 0;
	mazeReference[3][4] = 1;
	mazeReference[3][5] = 0;
	mazeReference[3][6] = 1;
	mazeReference[3][7] = 1;
	mazeReference[3][8] = 1;
	mazeReference[3][9] = 0;
	mazeReference[4][0] = 0;
	mazeReference[4][1] = 0;
	mazeReference[4][2] = 1;
	mazeReference[4][3] = 0;
	mazeReference[4][4] = 1;
	mazeReference[4][5] = 0;
	mazeReference[4][6] = 1;
	mazeReference[4][7] = 0;
	mazeReference[4][8] = 1;
	mazeReference[4][9] = 0;
	mazeReference[5][0] = 0;
	mazeReference[5][1] = 0;
	mazeReference[5][2] = 1;
	mazeReference[5][3] = 1;
	mazeReference[5][4] = 1;
	mazeReference[5][5] = 0;
	mazeReference[5][6] = 1;
	mazeReference[5][7] = 0;
	mazeReference[5][8] = 1;
	mazeReference[5][9] = 0;
	mazeReference[6][0] = 0;
	mazeReference[6][1] = 0;
	mazeReference[6][2] = 0;
	mazeReference[6][3] = 0;
	mazeReference[6][4] = 0;
	mazeReference[6][5] = 0;
	mazeReference[6][6] = 1;
	mazeReference[6][7] = 0;
	mazeReference[6][8] = 0;
	mazeReference[6][9] = 0;
	mazeReference[7][0] = 0;
	mazeReference[7][1] = 1;
	mazeReference[7][2] = 1;
	mazeReference[7][3] = 1;
	mazeReference[7][4] = 1;
	mazeReference[7][5] = 1;
	mazeReference[7][6] = 1;
	mazeReference[7][7] = 0;
	mazeReference[7][8] = 1;
	mazeReference[7][9] = 0;
	mazeReference[8][0] = 0;
	mazeReference[8][1] = 0;
	mazeReference[8][2] = 4;
	mazeReference[8][3] = 0;
	mazeReference[8][4] = 0;
	mazeReference[8][5] = 0;
	mazeReference[8][6] = 1;
	mazeReference[8][7] = 1;
	mazeReference[8][8] = 1;
	mazeReference[8][9] = 0;
	mazeReference[9][0] = 0;
	mazeReference[9][1] = 0;
	mazeReference[9][2] = 0;
	mazeReference[9][3] = 0;
	mazeReference[9][4] = 0;
	mazeReference[9][5] = 0;
	mazeReference[9][6] = 0;
	mazeReference[9][7] = 0;
	mazeReference[9][8] = 1;
	mazeReference[9][9] = 3;
}
void declareMazeReference()
{
	

	char pressedKey;
	for (int i = 0; i < 10; i++) 
	{
		for (int j = 0; j < 10; j++) 
		{
			do
			{
				pressedKey = _getch();

				switch (pressedKey)
				{
				case 'W':
				case 'w':
					if (mazeReference[i - 1][j] != 0) 
					{
						mazeReference[i - 1][j] = 5;
						mazeReference[i][j] = 1;
						break;
					}
					else
					{
						cout << "There is a wall you can not walk through!";
					}
				case 'A':
				case 'a':
					if (mazeReference[i][j - 1] != 0)
					{
						mazeReference[i][j - 1] = 5;
						mazeReference[i][j] = 1;
						break;
					}
					else
					{
						cout << "There is a wall you can not walk through!";
					}
					
				case 's':
				case 'S':
					if (mazeReference[i + 1][j] != 0)
					{
						mazeReference[i + 1][j] = 5;
						mazeReference[i][j] = 1;
						break;
					}
					else
					{
						cout << "There is a wall you can not walk through!";
					}

				case 'D':
				case 'd':
					if (mazeReference[i][j + 1] != 0)
					{
						mazeReference[i][j + 1] = 5;
						mazeReference[i][j] = 1;
						break;
					}
					else
					{
						cout << "There is a wall you can not walk through!";
					}
				}

			} while (pressedKey != 'Q' && pressedKey != 'q');
		}
	}
	

	for (int i = 0; i < 10; i++)
	{
		delete[] mazeReference[i];
	}
}

void printMaze()
{
	char** mazeBoard = new char* [10];

	for (int i = 0; i < 10; i++)
	{
		mazeBoard[i] = new char[10];
	}

	mazeBoard[0][0] = 'S';
	mazeBoard[0][1] = ' ';
	mazeBoard[0][2] = '#';
	mazeBoard[0][3] = '#';
	mazeBoard[0][4] = '#';
	mazeBoard[0][5] = '#';
	mazeBoard[0][6] = '#';
	mazeBoard[0][7] = '#';
	mazeBoard[0][8] = '#';
	mazeBoard[0][9] = '#';
	mazeBoard[1][0] = '#';
	mazeBoard[1][1] = ' ';
	mazeBoard[1][2] = '#';
	mazeBoard[1][3] = '#';
	mazeBoard[1][4] = '#';
	mazeBoard[1][5] = '#';
	mazeBoard[1][6] = '#';
	mazeBoard[1][7] = '#';
	mazeBoard[1][8] = '#';
	mazeBoard[1][9] = '#';
	mazeBoard[2][0] = '#';
	mazeBoard[2][1] = ' ';
	mazeBoard[2][2] = '#';
	mazeBoard[2][3] = '#';
	mazeBoard[2][4] = ' ';
	mazeBoard[2][5] = ' ';
	mazeBoard[2][6] = ' ';
	mazeBoard[2][7] = '#';
	mazeBoard[2][8] = '#';
	mazeBoard[2][9] = '#';
	mazeBoard[3][0] = '#';
	mazeBoard[3][1] = ' ';
	mazeBoard[3][2] = ' ';
	mazeBoard[3][3] = '#';
	mazeBoard[3][4] = ' ';
	mazeBoard[3][5] = '#';
	mazeBoard[3][6] = ' ';
	mazeBoard[3][7] = ' ';
	mazeBoard[3][8] = ' ';
	mazeBoard[3][9] = '#';
	mazeBoard[4][0] = '#';
	mazeBoard[4][1] = '#';
	mazeBoard[4][2] = ' ';
	mazeBoard[4][3] = '#';
	mazeBoard[4][4] = ' ';
	mazeBoard[4][5] = '#';
	mazeBoard[4][6] = ' ';
	mazeBoard[4][7] = '#';
	mazeBoard[4][8] = ' ';
	mazeBoard[4][9] = '#';
	mazeBoard[5][0] = '#';
	mazeBoard[5][1] = '#';
	mazeBoard[5][2] = ' ';
	mazeBoard[5][3] = ' ';
	mazeBoard[5][4] = ' ';
	mazeBoard[5][5] = '#';
	mazeBoard[5][6] = ' ';
	mazeBoard[5][7] = '#';
	mazeBoard[5][8] = ' ';
	mazeBoard[5][9] = '#';
	mazeBoard[6][0] = '#';
	mazeBoard[6][1] = '#';
	mazeBoard[6][2] = '#';
	mazeBoard[6][3] = '#';
	mazeBoard[6][4] = '#';
	mazeBoard[6][5] = '#';
	mazeBoard[6][6] = ' ';
	mazeBoard[6][7] = '#';
	mazeBoard[6][8] = '#';
	mazeBoard[6][9] = '#';
	mazeBoard[7][0] = '#';
	mazeBoard[7][1] = ' ';
	mazeBoard[7][2] = ' ';
	mazeBoard[7][3] = ' ';
	mazeBoard[7][4] = ' ';
	mazeBoard[7][5] = ' ';
	mazeBoard[7][6] = ' ';
	mazeBoard[7][7] = ' ';
	mazeBoard[7][8] = ' ';
	mazeBoard[7][9] = '#';
	mazeBoard[8][0] = '#';
	mazeBoard[8][1] = '#';
	mazeBoard[8][2] = 'o';
	mazeBoard[8][3] = '#';
	mazeBoard[8][4] = '#';
	mazeBoard[8][5] = '#';
	mazeBoard[8][6] = ' ';
	mazeBoard[8][7] = '#';
	mazeBoard[8][8] = ' ';
	mazeBoard[8][9] = '#';
	mazeBoard[9][0] = '#';
	mazeBoard[9][1] = '#';
	mazeBoard[9][2] = '#';
	mazeBoard[9][3] = '#';
	mazeBoard[9][4] = '#';
	mazeBoard[9][5] = '#';
	mazeBoard[9][6] = '#';
	mazeBoard[9][7] = '#';
	mazeBoard[9][8] = ' ';
	mazeBoard[9][9] = 'F';

	cout << "Easy mode - 10 x 10" << endl;
	cout << "Your current possition is ";

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			if (mazeBoard[i][j] == 'S')
			{
				cout << "[" << i << "][" << j << "]" << endl;
			}
		}
	}

	cout << "The final is located on position [9][9]" << endl << endl << "     ";

	for (int i = 0; i < 10; i++)
	{
		cout << i << " ";
	}

	cout << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) 
		{
			if (mazeReference[i][j] == 0) 
			{
				mazeBoard[i][j] = '#';
			}
			else if (mazeReference[i][j] == 1) 
			{
				mazeBoard[i][j] = ' ';
			}
			else if (mazeReference[i][j] == 2) 
			{
				mazeBoard[i][j] == 'S';
			}
			else if (mazeReference[i][j] == 3) 
			{
				mazeBoard[i][j] == 'F';
			}
			else if (mazeReference[i][j] == 4) 
			{
				mazeBoard[i][j] == 'o';
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		cout << " " << i << "   ";
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
	declareMazeReference();
}

