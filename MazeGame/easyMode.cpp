#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "globalVariables.h"
#include "easyMode.h"
#include "mainMenu.h"
#include "mazeFunctions.h"

using namespace std;

void printMaze(char** arr)
{
	// Print game mode
	cout << "Easy mode - 11 x 11" << endl;
	
	// Print current possition
	currentPossition(arr);

	// Print final position
	finalPossition(arr);

	// Print used moves
	cout << endl << "You've moved " << keysPressedCounter << " time/s" << endl << endl << "     ";

	// Print y coordinates
	for (int i = 0; i < 11; i++)
	{
		cout << i << " ";
	}

	cout << endl << endl;

	// Print maze
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

		// Display the maze to the screen
		for (int j = 0; j < 11; j++)
		{
			if (i == 1 && j == 0)
			{
				if (keysPressedCounter == 0)
				{
					arr[i][j] = 'o';
				}
			}
			if (i == 9 && j == 10)
			{
				arr[i][j] = 'F';
			}
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

//// Find if the character's position is on the key and if so unlock the secret door
//void secretKey(int a, int b, char** arr)
//{
//	if (a == 5 && b == 8 && arr[a][b] == 'o')
//	{
//		arr[5][9] = 'F';
//	}
//	else if (a == 4 && b == 8 && arr[a][b] == 'o')
//	{
//		arr[4][9] = 'F';
//	}
//	else if (a == 4 && b == 1 && arr[a][b] == 'o')
//	{
//		arr[4][0] = 'F';
//	}
//
//}

//void printMaze(char** arr)
//{
//	// Display the maze to the screen
//	for (int y = 0; y < HEIGHT; y++)
//	{
//		for (int x = 0; x < WIDTH; x++)
//		{
//			if (x == 1 && y == 0)
//			{
//				arr[x][y] = 'o';
//			}
//			if (x == 9 && y == 10)
//			{
//				arr[x][y] = 'F';
//			}
//			cout << arr[x][y] << " ";
//		}
//		cout << endl;
//	}
//}

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

	for (int i = 0; i < 11; i++)
	{
		delete[] arr[i];
	}
	printMaze(arr);
	winMessage();
}
