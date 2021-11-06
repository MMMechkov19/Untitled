#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "mainMenu.h"
#include "enums.h"
#include "structs.h"

using namespace std;

void currentPosition(char** arr, int width, int height)
{
	outputPosition(10, 3);
	cout << "CURRENT POSITION ";
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++) {
			if (arr[i][j] == 'o')
			{
				cout << "[" << i + 1 << "][" << j + 1 << "]";
			}
		}
	}

}

void checkInitialMove(PLAYER& player)
{
	if (player.x < 0)
	{
		system("cls");
		player.x = 0;
		keysPressedCounter = 0;
	}
}

void finalPosition(char** arr, int width, int height)
{
	/*int finalCounter = 0;*/
	outputPosition(10, 4);
	cout << "FINAL'S POSITION ";
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++) {
			if (arr[i][j] == 'F')
			{
				cout << "[" << i + 1 << "][" << j + 1 << "]";
			}
		}
	}
}

void printMaze(char** arr, int width, int height)
{
	printGameMachine();
	if (height == 11)
	{
		printGround();
	}

	// Print game mode
	outputPosition(42, 4);
	color(11);
	cout << width << " x " << height << endl;

	if (keysPressedCounter == 0)
	{
		arr[1][0] = 'o';
	}
	if (height == 11 || height == 21)
	{
		arr[width - 2][width - 1] = 'F';
	}
	else
	{
		arr[width - 2][30] = 'F';
	}
	
	// Print current possition
	currentPosition(arr, width, height);

	// Print final position
	finalPosition(arr, width, height);

	// Print used moves
	outputPosition(61, 4);
	cout << "YOU'VE MOVED " << keysPressedCounter << " TIME/S";

	outputPosition(8, 5);
	cout << "____________________________________________________________________________";

	// Print maze
	if (width == 11 && height == 11)
	{
		for (int i = 0; i < width; i++)
		{
			outputPosition(34, 11 + i);
			cout << " ";

			for (int j = 0; j < height; j++)
			{
				if (arr[i][j] == 'o')
				{
					color(15);
					cout << arr[i][j] << " ";
				}
				else if (arr[i][j] == 'F')
				{
					color(9);
					cout << arr[i][j] << " ";
				}
				else
				{
					color(14);
					cout << arr[i][j] << " ";
				}
			}
		}
	}
	else if (width == 21 && height == 21)
	{
		for (int i = 0; i < width; i++)
		{
			outputPosition(24, i + 8);
			cout << "  ";
			for (int j = 0; j < height; j++)
			{
				if (arr[i][j] == 'o')
				{
					color(15);
					cout << arr[i][j] << " ";
				}
				else if (arr[i][j] == 'F')
				{
					color(9);
					cout << arr[i][j] << " ";
				}
				else
				{
					color(14);
					cout << arr[i][j] << " ";
				}
			}
			cout << endl;
		}
	}
	else if (height == 31)
	{
		for (int i = 0; i < width; i++)
		{
			outputPosition(14, i + 8);
			cout << "  ";
			for (int j = 0; j < height; j++)
			{
				if (arr[i][j] == 'o')
				{
					color(15);
					cout << arr[i][j] << " ";
				}
				else if (arr[i][j] == 'F')
				{
					color(9);
					cout << arr[i][j] << " ";
				}
				else
				{
					color(14);
					cout << arr[i][j] << " ";
				}
			}
			cout << endl;
		}
	}
}

// System for moving player's character
void movementSystem(bool doesNotWin, char** arr, int width, int height)
{
	char pressedKey;
	PLAYER player;
	player.symbol = 'o';
	doesNotWin = true;

	bool isFound = false;

	player.x = 0;
	player.y = 1;

	while (doesNotWin)
	{
		checkInitialMove(player);

		if (arr[player.y][player.x] == ' ')
		{
			arr[player.y][player.x] = player.symbol;
		}

		printMaze(arr, width, height);

		pressedKey = _getch();

		switch ((KEY)pressedKey)
		{
		case KEY::LEFT:
			if (arr[player.y][player.x - 1] != char(254))
			{
				arr[player.y][player.x] = ' ';
				player.x--;
				keysPressedCounter++;
			}
			break;
		case KEY::UP:
			if (arr[player.y - 1][player.x] != char(254))
			{
				arr[player.y][player.x] = ' ';
				player.y--;
				keysPressedCounter++;
			}
			break;
		case KEY::DOWN:
			if (arr[player.y + 1][player.x] != char(254))
			{
				arr[player.y][player.x] = ' ';
				player.y++;
				keysPressedCounter++;
			}
			break;
		case KEY::RIGHT:
			if (arr[player.y][player.x + 1] != char(254))
			{
				arr[player.y][player.x] = ' ';
				player.x++;
				keysPressedCounter++;
			}
			break;
		}

		// Checks character's position to end the program
		if (arr[player.y][player.x] == 'F')
		{
			doesNotWin = false;
		}
		system("CLS");
	}
}

void resetArray(char** arr, int width, int height)
{
	// Fill the 2D array with walls
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++) {
			arr[i][j] = char(254);
		}
	}
}

int isInBounds(int x, int y, int width, int height)
{
	// Return "true" if x and y are both in-bounds
	if (x < 0 || x >= width)
	{
		return false;
	}
	if (y < 0 || y >= height)
	{
		return false;
	}
	return true;
}

void cleanTunnels(int x, int y, char** arr, int width, int height)
{
	arr[x][y] = ' ';

	int DIRECTIONS[4];
	DIRECTIONS[0] = NORTH;
	DIRECTIONS[1] = EAST;
	DIRECTIONS[2] = SOUTH;
	DIRECTIONS[3] = WEST;
	// Set random direction to try to clean space
	for (int i = 0; i < 4; ++i)
	{
		int randomDirection = rand() & 3;
		int temp = DIRECTIONS[randomDirection];
		DIRECTIONS[randomDirection] = DIRECTIONS[i];
		DIRECTIONS[i] = temp;
	}
	// Loop through every direction and attempt to clean space in that direction
	for (int i = 0; i < 4; ++i)
	{
		int rows = 0, columns = 0;
		switch (DIRECTIONS[i])
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
		if (isInBounds(x2, y2, width, height))
		{
			if (arr[x2][y2] == char(254))
			{
				// Clean space
				arr[x2 - rows][y2 - columns] = ' ';
				cleanTunnels(x2, y2, arr, width, height);
			}
		}
	}
}

void gameMode(SIZES size)
{
	bool doesNotWin = true;
	char** arr = new char* [size.HEIGHT];

	for (int i = 0; i < size.WIDTH; i++)
	{
		arr[i] = new char[size.WIDTH];
	}

	srand(time(0));

	resetArray(arr, size.WIDTH, size.HEIGHT);
	cleanTunnels(1, 1, arr, size.WIDTH, size.HEIGHT);
	printMaze(arr, size.WIDTH, size.HEIGHT);

	system("CLS");

	movementSystem(doesNotWin, arr, size.WIDTH, size.HEIGHT);
	system("CLS");

	for (int i = 0; i < size.WIDTH; i++)
	{
		delete[] arr[i];
	}
}