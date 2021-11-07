#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "mainMenu.h"
#include "enums.h"
#include "structs.h"

using namespace std;

/// \file

/// \brief  Print player's current position
/// \param  char** arr, int width, int height
/// \return void 
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

/// \file

/// \brief  Prevent getting out of the maze
/// \param  PLAYER& player
/// \return void 
void checkInitialMove(PLAYER& player)
{
	if (player.x < 0)
	{
		system("cls");
		player.x = 0;
		keysPressedCounter = 0;
	}
}

/// \file

/// \brief  Print final's position
/// \param  char** arr, int width, int height
/// \return void 
void finalPosition(char** arr, int width, int height)
{
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

/// \file

/// \brief  This function prints the maze
/// \param  char** arr, int width, int height
/// \return void 
void printMaze(char** arr, int width, int height)
{
	// Print ground if the maze is small enough
	printGameMachine();
	if (height == 11)
	{
		printGround();
	}

	// Print game mode
	outputPosition(42, 4);
	color(11);
	cout << width << " x " << height << endl;

	// Set start's position
	if (keysPressedCounter == 0)
	{
		arr[1][0] = 'o';
	}

	// Set final's position
	if (height == 11 || height == 21)
	{
		arr[width - 2][width - 1] = 'F';
	}
	else
	{
		arr[width - 2][30] = 'F';
	}

	// Print player's current possition
	currentPosition(arr, width, height);

	// Print final's position
	finalPosition(arr, width, height);

	// Print the number of used movements
	outputPosition(61, 4);
	cout << "YOU'VE MOVED " << keysPressedCounter << " TIME/S";

	outputPosition(8, 5);
	cout << "____________________________________________________________________________";

	// Print easy mode
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

	// Print medium mode
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

	// Print hard mode
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

/// \file

/// \brief  System for moving player's character
/// \param  bool doesNotWin, char** arr, int width, int height
/// \return void  
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

		// Display player's character
		if (arr[player.y][player.x] == ' ')
		{
			arr[player.y][player.x] = player.symbol;
		}

		printMaze(arr, width, height);

		pressedKey = _getch();

		switch ((KEY)pressedKey)
		{
			// Move left through the maze
		case KEY::LEFT:
			if (arr[player.y][player.x - 1] != char(254))
			{
				arr[player.y][player.x] = ' ';
				player.x--;
				keysPressedCounter++;
			}
			break;
			// Move up through the maze
		case KEY::UP:
			if (arr[player.y - 1][player.x] != char(254))
			{
				arr[player.y][player.x] = ' ';
				player.y--;
				keysPressedCounter++;
			}
			break;
			// Move down through the maze
		case KEY::DOWN:
			if (arr[player.y + 1][player.x] != char(254))
			{
				arr[player.y][player.x] = ' ';
				player.y++;
				keysPressedCounter++;
			}
			break;
			// Move right through the maze
		case KEY::RIGHT:
			if (arr[player.y][player.x + 1] != char(254))
			{
				arr[player.y][player.x] = ' ';
				player.x++;
				keysPressedCounter++;
			}
			break;
		}

		// Checks players's position to end the program
		if (arr[player.y][player.x] == 'F')
		{
			doesNotWin = false;
		}
		system("CLS");
	}
}

/// \file

/// \brief  This function fills the array with "walls"
/// \param  char** arr, int width, int height
/// \return void  
void resetArray(char** arr, int width, int height)
{
	// Fill array with walls
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++) {
			arr[i][j] = char(254);
		}
	}
}

/// \file

/// \brief  This functions checks if the coordinates are in-bounds
/// \param  int x, int y, int width, int height
/// \return void 
int isInBounds(int x, int y, int width, int height)
{
	// Check if coordinates are in-bounds
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

/// \file

/// \brief  This functions cleans tunnels through the maze
/// \param  int x, int y, char** arr, int width, int height
/// \return void 
void cleanTunnels(int x, int y, char** arr, int width, int height)
{
	arr[x][y] = ' ';

	int DIRECTIONS[4];
	DIRECTIONS[0] = NORTH;
	DIRECTIONS[1] = EAST;
	DIRECTIONS[2] = SOUTH;
	DIRECTIONS[3] = WEST;

	// Try to clean space in random direction
	for (int i = 0; i < 4; ++i)
	{
		int randomDirection = rand() & 3;
		int temp = DIRECTIONS[randomDirection];
		DIRECTIONS[randomDirection] = DIRECTIONS[i];
		DIRECTIONS[i] = temp;
	}

	// Check every direction and attempt to clean space in that direction
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

/// \file

/// \brief  This functions switches between different modes based on given sizes
/// \param  SIZES size
/// \return void 
void gameMode(SIZES size)
{
	bool doesNotWin = true;

	// Declare maze
	char** arr = new char* [size.WIDTH];

	for (int i = 0; i < size.WIDTH; i++)
	{
		arr[i] = new char[size.HEIGHT];
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