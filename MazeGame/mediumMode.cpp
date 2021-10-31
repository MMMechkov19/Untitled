#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "enums.h"
#include "structs.h"
#include "mediumMode.h"
#include "mainMenu.h"
#include "mazeFunctions.h"

using namespace std;

SIZE mediumModeMazeSize = { 21, 21 };

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
	char** arr = new char* [mediumModeMazeSize.HEIGHT];
	for (int i = 0; i < mediumModeMazeSize.WIDTH; i++)
	{
		arr[i] = new char[mediumModeMazeSize.WIDTH];
	}

	srand(time(0));
	resetArray(arr, mediumModeMazeSize.WIDTH, mediumModeMazeSize.HEIGHT);
	cleanTunnels(1, 1, arr, mediumModeMazeSize.WIDTH, mediumModeMazeSize.HEIGHT);
	printMaze(arr, mediumModeMazeSize.WIDTH, mediumModeMazeSize.HEIGHT);
	system("CLS");
	movementSystem(doesNotWin, arr, mediumModeMazeSize.WIDTH, mediumModeMazeSize.HEIGHT);
	winMessage();
	system("CLS");

	for (int i = 0; i < mediumModeMazeSize.WIDTH; i++)
	{
		delete[] arr[i];
	}
}
