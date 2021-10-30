#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "easyMode.h"
#include "mainMenu.h"

using namespace std;

const int KEY_LEFT = 'a', KEY_RIGHT = 'd', KEY_UP = 'w', KEY_DOWN = 's';

struct Player
{
	char symbol;
	int x;
	int y;
};

enum size
{
	WIDTH = 11,
	HEIGHT = 11
};

enum directions
{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3
};

// Moves' counter
int keysPressedCounter = 0;

void printMaze(char** arr, int keysPressedCounter)
{
	// Print game mode and current position
	cout << "Easy mode - 11 x 11" << endl;
	cout << "Your current position is ";

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++) {
			if (arr[i][j] == 'S')
			{
				cout << "[" << i << "][" << j << "]" << endl;
			}
		}
	}

	// Print final position
	int finalCounter = 0;
	cout << "The final is located on position ";
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++) {
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
	for (int i = 0; i < 11; i++)
	{
		cout << i << " ";
	}

	cout << endl << endl;

	// Print maze board
	for (int i = 0; i < 11; i++)
	{
		// Print x coordinates
		if (i == 10) {
			cout << " " << i << "  ";
		}
		else
		{
			cout << " " << i << "   ";
		}

		for (int j = 0; j < 11; j++)
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
	player.symbol = 'o';
	doesNotWin = true;

	bool isFound = false;

	player.x = 0;
	player.y = 1;

	while (doesNotWin)
	{
		if (arr[player.y][player.x] == ' ')
		{
			arr[player.y][player.x] = player.symbol;
		}

		printMaze(arr, keysPressedCounter);

		pressedKey = _getch();

		switch (pressedKey)
		{
		case KEY_LEFT:
			if (arr[player.y][player.x - 1] != char(254))
			{
				arr[player.y][player.x] = ' ';
				player.x--;
				keysPressedCounter++;
			}
			break;
		case KEY_UP:
			if (arr[player.y - 1][player.x] != char(254))
			{
				arr[player.y][player.x] = ' ';
				player.y--;
				keysPressedCounter++;
			}
			break;
		case KEY_DOWN:
			if (arr[player.y + 1][player.x] != char(254))
			{
				arr[player.y][player.x] = ' ';
				player.y++;
				keysPressedCounter++;
			}
			break;
		case KEY_RIGHT:
			if (arr[player.y][player.x + 1] != char(254))
			{
				arr[player.y][player.x] = ' ';
				player.x++;
				keysPressedCounter++;
			}
			break;
		}
		secretKey(player.y, player.x, arr);
		// Checks character's position to end the program
		if (arr[player.y][player.x] == 'F')
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

void resetArray(char** arr)
{
	// Fills the 2D array with walls
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++) {
			arr[i][j] = char(254);
		}
	}
}

int isInBounds(int x, int y)
{
	// Returns "true" if x and y are both in-bounds.
	if (x < 0 || x >= WIDTH)
	{
		return false;
	}
	if (y < 0 || y >= HEIGHT)
	{
		return false;
	}
	return true;
}

void cleanTunnels(int x, int y, char** arr)
{
	arr[x][y] = ' ';

	int directions[4];
	directions[0] = NORTH;
	directions[1] = EAST;
	directions[2] = SOUTH;
	directions[3] = WEST;
	// Set random direction to try to clean space
	for (int i = 0; i < 4; ++i)
	{
		int randomDirection = rand() & 3;
		int temp = directions[randomDirection];
		directions[randomDirection] = directions[i];
		directions[i] = temp;
	}
	// Loop through every direction and attempt to clean space in that direction
	for (int i = 0; i < 4; ++i)
	{
		int rows = 0, columns = 0;
		switch (directions[i])
		{
		case NORTH: columns = -1;
			break;
		case SOUTH: columns = 1;
			break;
		case EAST: rows = 1;
			break;
		case WEST: rows = -1;
			break;
		}
		// Find the coordinates of the 2D array cell 2 positions away in the given direction
		int x2 = x + (rows * 2);
		int y2 = y + (columns * 2);
		if (isInBounds(x2, y2))
		{
			if (arr[x2][y2] == char(254))
			{
				// Clean space
				arr[x2 - rows][y2 - columns] = ' ';
				cleanTunnels(x2, y2, arr);
			}
		}
	}
}
void printMaze(char** arr)
{
	// Display the maze to the screen
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (x == 1 && y == 0)
			{
				arr[x][y] = 'o';
			}
			if (x == 9 && y == 10)
			{
				arr[x][y] = 'F';
			}
			cout << arr[x][y] << " ";
		}
		cout << endl;
	}
}
void easyMode()
{
	bool doesNotWin = true;
	char** arr = new char* [HEIGHT];
	for (int i = 0; i < WIDTH; i++)
	{
		arr[i] = new char[WIDTH];
	}

	srand(time(0));
	resetArray(arr);
	cleanTunnels(1, 1, arr);
	movementSystem(doesNotWin, arr);
	winMessage();

	for (int i = 0; i < 11; i++)
	{
		delete[] arr[i];
	}
	printMaze(arr);
}
