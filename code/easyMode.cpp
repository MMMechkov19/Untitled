#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

// easy mode first board example
void printMaze()
{
	// decllare 2D array dynamically
	char** mazeBoard = new char* [10];

	for (int i = 0; i < 10; i++)
	{
		mazeBoard[i] = new char[10];
	}

	// initialise array's values
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

	// print game mode and current position
	cout << "Easy mode - 10 x 10" << endl;
	cout << "Your current position is ";

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			if (mazeBoard[i][j] == 'S')
			{
				cout << "[" << i << "][" << j << "]" << endl;
			}
		}
	}

	// print final position
	cout << "The final is located on position [9][9]" << endl << endl << "     ";

	// print y coordinates
	for (int i = 0; i < 10; i++)
	{
		cout << i << " ";
	}

	cout << endl << endl;

	// print maze board
	for (int i = 0; i < 10; i++)
	{
		// print x coordinates
		cout << " " << i << "   ";

		for (int j = 0; j < 10; j++)
		{
			cout << mazeBoard[i][j] << " ";
		}
		cout << endl;
	}

	// declare variable for the pressed key
	char pressedKey;

	// print maze board with changed values
	do {

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				do
				{
					pressedKey = _getch();

					switch (pressedKey)
					{

						// moves character with one position up
					case 'W':
					case 'w':

						// checks wheter there is a wall or an empty space
						if (mazeBoard[i - 1][j] != '#')
						{
							// changes character's position
							mazeBoard[i - 1][j] = 'S';
							mazeBoard[i][j] = ' ';
						}
						else
						{
							cout << "There is a wall you can not walk through!";
						}
						break;

						// moves character with one position left
					case 'A':
					case 'a':

						// checks wheter there is a wall or an empty space
						if (mazeBoard[i][j - 1] != '#')
						{
							// changes character's position
							mazeBoard[i][j - 1] = 'S';
							mazeBoard[i][j] = ' ';
						}
						else
						{
							cout << "There is a wall you can not walk through!";
						}
						break;

						// moves character with one position down
					case 's':
					case 'S':

						// checks wheter there is a wall or an empty space
						if (mazeBoard[i + 1][j] != '#')
						{
							// changes character's position
							mazeBoard[i + 1][j] = 'S';
							mazeBoard[i][j] = ' ';
						}
						else
						{
							cout << "There is a wall you can not walk through!";
						}
						break;

						// moves character with one position right
					case 'D':
					case 'd':

						// checks wheter there is a wall or an empty space
						if (mazeBoard[i][j + 1] != '#')
						{
							// changes character's position
							mazeBoard[i][j + 1] = 'S';
							mazeBoard[i][j] = ' ';
						}
						else
						{
							cout << "There is a wall you can not walk through!";
						}
						break;
					}

					// clear screen
					system("CLS");

					cout << "     ";

					// print y coordinates
					for (int s = 0; s < 10; s++)
					{
						cout << s << " ";
					}

					cout << endl << endl;

					// print maze board with changed positions
					for (int row = 0; row < 10; row++)
					{
						// print x coordinates
						cout << " " << row << "   ";

						for (int col = 0; col < 10; col++)
						{
							cout << mazeBoard[row][col] << " ";
						}
						cout << endl;
					}
				} while (pressedKey == 'w' || pressedKey == 'W' || pressedKey == 's' || pressedKey == 'S' || pressedKey == 'a' || pressedKey == 'A' || pressedKey == 'd' || pressedKey == 'D');
			}
		}
	} while (mazeBoard[9][9] != 'S');

	for (int i = 0; i < 10; i++)
	{
		delete[] mazeBoard[i];
	}
}


int main()
{
	printMaze();
}


