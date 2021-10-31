#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "easyMode.h"
#include "mainMenu.h"
#include "globalVariables.h"

using namespace std;

void currentPossition(char** arr)
{
	cout << "Your current position is ";
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 1; j < HEIGHT; j++) {
			if (arr[i][j] == 'o')
			{
				if (keysPressedCounter == 0)
				{
					cout << "[1][0]";
				}
				else
				{
					cout << "[" << i << "][" << j << "]" << endl;
				}
			}
		}
	}

}

void finalPossition(char** arr)
{
	/*int finalCounter = 0;*/
	cout << "The final is located on position ";
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++) {
			if (arr[i][j] == 'F')
			{
				/*finalcounter++;

				if (finalcounter == 2)
				{
					cout << " / [" << i << "][" << j << "]";
				}
				else
				{*/
				cout << "[" << i << "][" << j << "]";
				/*}*/
			}
		}
	}
}

// System for moving player's character
void movementSystem(bool doesNotWin, char** arr)
{
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

		printMaze(arr);

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
		/*secretKey(player.y, player.x, arr);*/
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