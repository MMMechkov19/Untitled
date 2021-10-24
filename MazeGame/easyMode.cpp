#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "easyMode.h"
#include "mainMenu.h"

using namespace std;

const int KEY_LEFT = 'a', KEY_RIGHT = 'd', KEY_UP = 'w', KEY_DOWN = 's';

// Player's coordinates and symbol
struct Player
{
	char symbol;
	int x;
	int y;
};

// Moves' counter
int keysPressedCounter = 0;

void printMaze(char** arr, int keysPressedCounter)
{
	// Print game mode and current position
	cout << "Easy mode - 10 x 10" << endl;
	cout << "Your current position is ";

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == 'S')
			{
				cout << "[" << i << "][" << j << "]" << endl;
			}
		}
	}

	// Print final position
	int finalCounter = 0;
	cout << "The final is located on position ";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == 'F')
			{
				finalCounter++;

				if (finalCounter == 2)
				{
					cout << " / [" << i << "][" << j << "]";
				}
				else
				{
					cout << "[" << i << "][" << j << "]";
				}
			}
		}
	}

	// Print used moves
	cout << endl << "You've moved " << keysPressedCounter << " time/s" << endl << endl << "     ";

	// Print y coordinates
	for (int i = 0; i < 10; i++)
	{
		cout << i << " ";
	}

	cout << endl << endl;

	// Print maze board
	for (int i = 0; i < 10; i++)
	{
		// Print x coordinates
		cout << " " << i << "   ";

		for (int j = 0; j < 10; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
// Find if the character's position is on the key and if so unlock the secret door
void secretKey(int a, int b, char** arr)
{
	if (a == 5 && b == 8 && arr[a][b] == 'o')
	{
		arr[5][9] = 'F';
	}
	else if (a == 4 && b == 8 && arr[a][b] == 'o')
	{
		arr[4][9] = 'F';
	}
	else if (a == 4 && b == 1 && arr[a][b] == 'o')
	{
		arr[4][0] = 'F';
	}

}

// System for moving player's character
void movementSystem(bool doesNotWin, char** arr)
{
	// Declare variable for the pressed key
	char pressedKey;
	Player player;
	player.symbol = 'S';
	doesNotWin = true;

	bool isFound = false;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j] == 'S')
			{
				player.x = j;
				player.y = i;
				isFound = true;
				break;
			}
		}
		if (isFound) {
			break;
		}
	}

	while (doesNotWin)
	{
		if (arr[player.y][player.x] == ' ' || arr[player.y][player.x] == 'o')
		{
			arr[player.y][player.x] = player.symbol;
		}

		printMaze(arr, keysPressedCounter);

		pressedKey = _getch();

		switch (pressedKey)
		{
		case KEY_LEFT:
			if (arr[player.y][player.x - 1] != '#')
			{
				arr[player.y][player.x] = ' ';
				player.x--;
				keysPressedCounter++;
			}
			break;
		case KEY_UP:
			if (arr[player.y - 1][player.x] != '#')
			{
				arr[player.y][player.x] = ' ';
				player.y--;
				keysPressedCounter++;
			}
			break;
		case KEY_DOWN:
			if (arr[player.y + 1][player.x] != '#')
			{
				arr[player.y][player.x] = ' ';
				player.y++;
				keysPressedCounter++;
			}
			break;
		case KEY_RIGHT:
			if (arr[player.y][player.x + 1] != '#')
			{
				arr[player.y][player.x] = ' ';
				player.x++;
				keysPressedCounter++;
			}
			break;
		}
		secretKey(player.y, player.x, arr);

		// Checks character's position to end the program
		if (player.y == 9 && player.x == 9 || player.y == 5 && player.x == 9)
		{
			doesNotWin = false;
		}
		else if (player.y == 0 && player.x == 8 || player.y == 4 && player.x == 9)
		{
			doesNotWin = false;
		}
		else if (player.y == 2 && player.x == 0 || player.y == 4 && player.x == 0)
		{
			doesNotWin = false;
		}
		else if (player.y == 9 && player.x == 5 || player.y == 5 && player.x == 9)
		{
			doesNotWin = false;
		}

		system("CLS");
	}
}

// Display win message
void winMessage()
{
	cout << "WIN!" << endl;
	cout << "You've moved " << keysPressedCounter << " time/s" << endl;
	keysPressedCounter = 0;
	system("CLS");

}

// Declare maze board
void mazeDeclaration()
{

	bool doesNotWin = true;

	srand(time(0));
	int randomMaze = rand() % 4, guess = 0;

	if (randomMaze == 0)
	{
		// Declare 2D array
		char** mazeBoard = new char* [10];

		for (int i = 0; i <= 10; i++)
		{
			mazeBoard[i] = new char[10];
		}

		// Initialize array's values
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
		mazeBoard[5][8] = 'o';
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
		mazeBoard[8][2] = ' ';
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

		movementSystem(doesNotWin, mazeBoard);
		winMessage();

		for (int i = 0; i < 10; i++)
		{
			delete[] mazeBoard[i];
		}
	}
	else if (randomMaze == 1)
	{

		// Declare 2D array
		char** mazeBoard1 = new char* [10];

		for (int i = 0; i <= 10; i++)
		{
			mazeBoard1[i] = new char[10];
		}

		// Initialize array's values
		mazeBoard1[0][0] = '#';
		mazeBoard1[0][1] = '#';
		mazeBoard1[0][2] = '#';
		mazeBoard1[0][3] = 'S';
		mazeBoard1[0][4] = '#';
		mazeBoard1[0][5] = '#';
		mazeBoard1[0][6] = '#';
		mazeBoard1[0][7] = '#';
		mazeBoard1[0][8] = '#';
		mazeBoard1[0][9] = '#';
		mazeBoard1[1][0] = '#';
		mazeBoard1[1][1] = '#';
		mazeBoard1[1][2] = '#';
		mazeBoard1[1][3] = ' ';
		mazeBoard1[1][4] = '#';
		mazeBoard1[1][5] = '#';
		mazeBoard1[1][6] = '#';
		mazeBoard1[1][7] = '#';
		mazeBoard1[1][8] = '#';
		mazeBoard1[1][9] = '#';
		mazeBoard1[2][0] = '#';
		mazeBoard1[2][1] = ' ';
		mazeBoard1[2][2] = ' ';
		mazeBoard1[2][3] = ' ';
		mazeBoard1[2][4] = ' ';
		mazeBoard1[2][5] = ' ';
		mazeBoard1[2][6] = ' ';
		mazeBoard1[2][7] = ' ';
		mazeBoard1[2][8] = '#';
		mazeBoard1[2][9] = '#';
		mazeBoard1[3][0] = '#';
		mazeBoard1[3][1] = '#';
		mazeBoard1[3][2] = '#';
		mazeBoard1[3][3] = '#';
		mazeBoard1[3][4] = '#';
		mazeBoard1[3][5] = '#';
		mazeBoard1[3][6] = '#';
		mazeBoard1[3][7] = ' ';
		mazeBoard1[3][8] = '#';
		mazeBoard1[3][9] = '#';
		mazeBoard1[4][0] = '#';
		mazeBoard1[4][1] = ' ';
		mazeBoard1[4][2] = ' ';
		mazeBoard1[4][3] = ' ';
		mazeBoard1[4][4] = ' ';
		mazeBoard1[4][5] = ' ';
		mazeBoard1[4][6] = ' ';
		mazeBoard1[4][7] = ' ';
		mazeBoard1[4][8] = '#';
		mazeBoard1[4][9] = '#';
		mazeBoard1[5][0] = '#';
		mazeBoard1[5][1] = ' ';
		mazeBoard1[5][2] = '#';
		mazeBoard1[5][3] = '#';
		mazeBoard1[5][4] = '#';
		mazeBoard1[5][5] = '#';
		mazeBoard1[5][6] = '#';
		mazeBoard1[5][7] = ' ';
		mazeBoard1[5][8] = 'o';
		mazeBoard1[5][9] = '#';
		mazeBoard1[6][0] = '#';
		mazeBoard1[6][1] = ' ';
		mazeBoard1[6][2] = ' ';
		mazeBoard1[6][3] = ' ';
		mazeBoard1[6][4] = ' ';
		mazeBoard1[6][5] = ' ';
		mazeBoard1[6][6] = '#';
		mazeBoard1[6][7] = '#';
		mazeBoard1[6][8] = '#';
		mazeBoard1[6][9] = '#';
		mazeBoard1[7][0] = '#';
		mazeBoard1[7][1] = '#';
		mazeBoard1[7][2] = ' ';
		mazeBoard1[7][3] = '#';
		mazeBoard1[7][4] = '#';
		mazeBoard1[7][5] = ' ';
		mazeBoard1[7][6] = ' ';
		mazeBoard1[7][7] = ' ';
		mazeBoard1[7][8] = ' ';
		mazeBoard1[7][9] = '#';
		mazeBoard1[8][0] = '#';
		mazeBoard1[8][1] = '#';
		mazeBoard1[8][2] = ' ';
		mazeBoard1[8][3] = '#';
		mazeBoard1[8][4] = '#';
		mazeBoard1[8][5] = ' ';
		mazeBoard1[8][6] = '#';
		mazeBoard1[8][7] = '#';
		mazeBoard1[8][8] = '#';
		mazeBoard1[8][9] = '#';
		mazeBoard1[9][0] = '#';
		mazeBoard1[9][1] = '#';
		mazeBoard1[9][2] = '#';
		mazeBoard1[9][3] = '#';
		mazeBoard1[9][4] = '#';
		mazeBoard1[9][5] = 'F';
		mazeBoard1[9][6] = '#';
		mazeBoard1[9][7] = '#';
		mazeBoard1[9][8] = '#';
		mazeBoard1[9][9] = '#';

		movementSystem(doesNotWin, mazeBoard1);
		winMessage();

		for (int i = 0; i < 10; i++)
		{
			delete[] mazeBoard1[i];
		}
	}
	// Declare 2D array
	else if (randomMaze == 2)
	{
		char** mazeBoard2 = new char* [10];

		for (int i = 0; i <= 10; i++)
		{
			mazeBoard2[i] = new char[10];
		}

		// Initialize array's values
		mazeBoard2[0][0] = '#';
		mazeBoard2[0][1] = '#';
		mazeBoard2[0][2] = '#';
		mazeBoard2[0][3] = '#';
		mazeBoard2[0][4] = '#';
		mazeBoard2[0][5] = '#';
		mazeBoard2[0][6] = '#';
		mazeBoard2[0][7] = '#';
		mazeBoard2[0][8] = '#';
		mazeBoard2[0][9] = '#';
		mazeBoard2[1][0] = '#';
		mazeBoard2[1][1] = '#';
		mazeBoard2[1][2] = ' ';
		mazeBoard2[1][3] = ' ';
		mazeBoard2[1][4] = '#';
		mazeBoard2[1][5] = ' ';
		mazeBoard2[1][6] = ' ';
		mazeBoard2[1][7] = ' ';
		mazeBoard2[1][8] = ' ';
		mazeBoard2[1][9] = '#';
		mazeBoard2[2][0] = 'F';
		mazeBoard2[2][1] = ' ';
		mazeBoard2[2][2] = ' ';
		mazeBoard2[2][3] = ' ';
		mazeBoard2[2][4] = ' ';
		mazeBoard2[2][5] = ' ';
		mazeBoard2[2][6] = '#';
		mazeBoard2[2][7] = '#';
		mazeBoard2[2][8] = ' ';
		mazeBoard2[2][9] = '#';
		mazeBoard2[3][0] = '#';
		mazeBoard2[3][1] = '#';
		mazeBoard2[3][2] = '#';
		mazeBoard2[3][3] = '#';
		mazeBoard2[3][4] = '#';
		mazeBoard2[3][5] = '#';
		mazeBoard2[3][6] = ' ';
		mazeBoard2[3][7] = ' ';
		mazeBoard2[3][8] = ' ';
		mazeBoard2[3][9] = '#';
		mazeBoard2[4][0] = '#';
		mazeBoard2[4][1] = 'o';
		mazeBoard2[4][2] = ' ';
		mazeBoard2[4][3] = ' ';
		mazeBoard2[4][4] = '#';
		mazeBoard2[4][5] = '#';
		mazeBoard2[4][6] = ' ';
		mazeBoard2[4][7] = '#';
		mazeBoard2[4][8] = '#';
		mazeBoard2[4][9] = '#';
		mazeBoard2[5][0] = '#';
		mazeBoard2[5][1] = '#';
		mazeBoard2[5][2] = '#';
		mazeBoard2[5][3] = ' ';
		mazeBoard2[5][4] = '#';
		mazeBoard2[5][5] = ' ';
		mazeBoard2[5][6] = ' ';
		mazeBoard2[5][7] = ' ';
		mazeBoard2[5][8] = '#';
		mazeBoard2[5][9] = '#';
		mazeBoard2[6][0] = '#';
		mazeBoard2[6][1] = '#';
		mazeBoard2[6][2] = '#';
		mazeBoard2[6][3] = ' ';
		mazeBoard2[6][4] = ' ';
		mazeBoard2[6][5] = ' ';
		mazeBoard2[6][6] = '#';
		mazeBoard2[6][7] = '#';
		mazeBoard2[6][8] = ' ';
		mazeBoard2[6][9] = '#';
		mazeBoard2[7][0] = '#';
		mazeBoard2[7][1] = ' ';
		mazeBoard2[7][2] = ' ';
		mazeBoard2[7][3] = ' ';
		mazeBoard2[7][4] = '#';
		mazeBoard2[7][5] = '#';
		mazeBoard2[7][6] = '#';
		mazeBoard2[7][7] = '#';
		mazeBoard2[7][8] = ' ';
		mazeBoard2[7][9] = '#';
		mazeBoard2[8][0] = '#';
		mazeBoard2[8][1] = '#';
		mazeBoard2[8][2] = '#';
		mazeBoard2[8][3] = ' ';
		mazeBoard2[8][4] = ' ';
		mazeBoard2[8][5] = ' ';
		mazeBoard2[8][6] = ' ';
		mazeBoard2[8][7] = ' ';
		mazeBoard2[8][8] = ' ';
		mazeBoard2[8][9] = 'S';
		mazeBoard2[9][0] = '#';
		mazeBoard2[9][1] = '#';
		mazeBoard2[9][2] = '#';
		mazeBoard2[9][3] = '#';
		mazeBoard2[9][4] = '#';
		mazeBoard2[9][5] = '#';
		mazeBoard2[9][6] = '#';
		mazeBoard2[9][7] = '#';
		mazeBoard2[9][8] = '#';
		mazeBoard2[9][9] = '#';

		movementSystem(doesNotWin, mazeBoard2);
		winMessage();

		for (int i = 0; i < 10; i++)
		{
			delete[] mazeBoard2[i];
		}
	}

	else if (randomMaze == 3)
	{
		// Declare 2D array dynamically 
		char** mazeBoard3 = new char* [10];

		for (int i = 0; i <= 10; i++)
		{
			mazeBoard3[i] = new char[10];
		}

		// Initialize array's values
		mazeBoard3[0][0] = '#';
		mazeBoard3[0][1] = '#';
		mazeBoard3[0][2] = '#';
		mazeBoard3[0][3] = '#';
		mazeBoard3[0][4] = '#';
		mazeBoard3[0][5] = '#';
		mazeBoard3[0][6] = '#';
		mazeBoard3[0][7] = '#';
		mazeBoard3[0][8] = 'F';
		mazeBoard3[0][9] = '#';
		mazeBoard3[1][0] = '#';
		mazeBoard3[1][1] = ' ';
		mazeBoard3[1][2] = ' ';
		mazeBoard3[1][3] = ' ';
		mazeBoard3[1][4] = '#';
		mazeBoard3[1][5] = '#';
		mazeBoard3[1][6] = ' ';
		mazeBoard3[1][7] = ' ';
		mazeBoard3[1][8] = ' ';
		mazeBoard3[1][9] = '#';
		mazeBoard3[2][0] = '#';
		mazeBoard3[2][1] = ' ';
		mazeBoard3[2][2] = '#';
		mazeBoard3[2][3] = ' ';
		mazeBoard3[2][4] = '#';
		mazeBoard3[2][5] = ' ';
		mazeBoard3[2][6] = ' ';
		mazeBoard3[2][7] = '#';
		mazeBoard3[2][8] = '#';
		mazeBoard3[2][9] = '#';
		mazeBoard3[3][0] = '#';
		mazeBoard3[3][1] = ' ';
		mazeBoard3[3][2] = '#';
		mazeBoard3[3][3] = ' ';
		mazeBoard3[3][4] = '#';
		mazeBoard3[3][5] = ' ';
		mazeBoard3[3][6] = '#';
		mazeBoard3[3][7] = '#';
		mazeBoard3[3][8] = '#';
		mazeBoard3[3][9] = '#';
		mazeBoard3[4][0] = '#';
		mazeBoard3[4][1] = ' ';
		mazeBoard3[4][2] = '#';
		mazeBoard3[4][3] = ' ';
		mazeBoard3[4][4] = '#';
		mazeBoard3[4][5] = ' ';
		mazeBoard3[4][6] = ' ';
		mazeBoard3[4][7] = ' ';
		mazeBoard3[4][8] = 'o';
		mazeBoard3[4][9] = '#';
		mazeBoard3[5][0] = '#';
		mazeBoard3[5][1] = ' ';
		mazeBoard3[5][2] = '#';
		mazeBoard3[5][3] = ' ';
		mazeBoard3[5][4] = '#';
		mazeBoard3[5][5] = ' ';
		mazeBoard3[5][6] = '#';
		mazeBoard3[5][7] = '#';
		mazeBoard3[5][8] = '#';
		mazeBoard3[5][9] = '#';
		mazeBoard3[6][0] = '#';
		mazeBoard3[6][1] = ' ';
		mazeBoard3[6][2] = '#';
		mazeBoard3[6][3] = ' ';
		mazeBoard3[6][4] = '#';
		mazeBoard3[6][5] = ' ';
		mazeBoard3[6][6] = ' ';
		mazeBoard3[6][7] = ' ';
		mazeBoard3[6][8] = ' ';
		mazeBoard3[6][9] = '#';
		mazeBoard3[7][0] = '#';
		mazeBoard3[7][1] = ' ';
		mazeBoard3[7][2] = '#';
		mazeBoard3[7][3] = ' ';
		mazeBoard3[7][4] = '#';
		mazeBoard3[7][5] = '#';
		mazeBoard3[7][6] = '#';
		mazeBoard3[7][7] = '#';
		mazeBoard3[7][8] = ' ';
		mazeBoard3[7][9] = '#';
		mazeBoard3[8][0] = '#';
		mazeBoard3[8][1] = ' ';
		mazeBoard3[8][2] = '#';
		mazeBoard3[8][3] = ' ';
		mazeBoard3[8][4] = ' ';
		mazeBoard3[8][5] = ' ';
		mazeBoard3[8][6] = ' ';
		mazeBoard3[8][7] = ' ';
		mazeBoard3[8][8] = ' ';
		mazeBoard3[8][9] = '#';
		mazeBoard3[9][0] = '#';
		mazeBoard3[9][1] = 'S';
		mazeBoard3[9][2] = '#';
		mazeBoard3[9][3] = '#';
		mazeBoard3[9][4] = '#';
		mazeBoard3[9][5] = '#';
		mazeBoard3[9][6] = '#';
		mazeBoard3[9][7] = '#';
		mazeBoard3[9][8] = '#';
		mazeBoard3[9][9] = '#';


		movementSystem(doesNotWin, mazeBoard3);
		winMessage();

		for (int i = 0; i < 10; i++)
		{
			delete[] mazeBoard3[i];
		}
	}
}