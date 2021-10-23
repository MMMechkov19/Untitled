#pragma once
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
void printMaze(char** mazeBoard, int keysPressedCounter)
{
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
	cout << "The final is located on position [9][9]" << endl;

	// print used moves
	cout << "You've moved " << keysPressedCounter << " time/s" << endl << endl << "     ";

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
}
