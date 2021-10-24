#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include "easyMode.h"

using namespace std;

bool exitProgram = true;

void color(int color)
{
	if (SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color)) 
	{ 
		return; 
	}
	else {}
}

void outputPosition(int x, int y)
{
	COORD position;
	position.X = x;
	position.Y = y;
	if (SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position)) 
	{ 
		return; 
	}
	else {}
}
void easyMode()
{
	char key1;
	int counter1 = 1;
	bool exitStatement = true;
	int colorNumber1[] = { 7,7,7 };

	do {


		outputPosition(5, 10);
		color(colorNumber1[0]);
		cout << "1. Easy Mode";

		outputPosition(5, 11);
		color(colorNumber1[1]);
		cout << "2. Medium Mode";

		outputPosition(5, 12);
		color(colorNumber1[2]);
		cout << "3. Hard Mode";

		key1 = _getch();

		if (key1 == 'w' && (counter1 >= 2 && counter1 <= 5))
		{
			counter1--;
		}

		if (key1 == 's' && (counter1 >= 1 && counter1 <= 4))
		{
			counter1++;
		}
		if (key1 == '\r') {

			if (counter1 == 1)
			{
				system("CLS");
				mazeDeclaration();
			}
			if (counter1 == 2)
			{
				exitProgram = true;
			}
			if (counter1 == 3)
			{
				exitProgram = true;
			}
		}
		colorNumber1[0] = 7;
		colorNumber1[1] = 7;
		colorNumber1[2] = 7;

		if (counter1 == 1)
		{
			colorNumber1[0] = 10;
		}
		if (counter1 == 2)
		{
			colorNumber1[1] = 3;
		}
		if (counter1 == 3)
		{
			colorNumber1[2] = 12;
		}

	} while (exitStatement != false);
}
void mainMenu()
{

	int colorNumber[] = {7, 7, 7, 7};
	int counter = 1;
	char key;
	cout << endl;
	cout << endl;

	cout << "        __  __     __   __     ______   __     ______   __         ______     _____    " << endl;
	cout << "       /\\ \\/\\ \\   /\\ "" -.\\ \\  / \\__  _\\ /\\ \\   /\\__  _\\ /\\ \\       /\\  ___\\   /\\  __-.  " << endl;
	cout << "       \\ \\ \\_\\ \\  \\ \\ \\-.  \\ \\/_/\\ \\ / \\ \\ \\  \\/_/\\ \\/ \\ \\ \\____  \\ \\  __\\   \\ \\ \\/\\ \\ " << endl;
	cout << "        \\ \\_____\\  \\ \\_\\ \\""\\_\\   \\ \\_\\   \\ \\_\\    \\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\____- " << endl;
	cout << "         \\/_____/   \\/_/ \\/_/    \\/_/    \\/_/     \\/_/   \\/_____/   \\/_____/   \\/____/ " << endl;

	do
	{


		outputPosition(5, 10);
		color(colorNumber[0]);
		cout << "1. Play";

		outputPosition(5, 11);
		color(colorNumber[1]);
		cout << "2. Rules";

		outputPosition(5, 12);
		color(colorNumber[2]);
		cout << "3. Exit";



		key = _getch();

		if (key == 'w' && (counter >= 2 && counter <= 5))
		{
			counter--;
		}
		if (key == 's' && (counter >= 1 && counter <= 4))
		{
			counter++;
		}
		if (key == '\r')
		{
			if (counter == 1)
			{
				easyMode();
				
			}
			if (counter == 2)
			{
				exitProgram = true;

			}
			if (counter == 3)
			{
				exitProgram = false;
				system("CLS");

			}

		}

		colorNumber[0] = 7;
		colorNumber[1] = 7;
		colorNumber[2] = 7;

		if (counter == 1)
		{
			colorNumber[0] = 10;

		}
		if (counter == 2)
		{
			colorNumber[1] = 3;
		}
		if (counter == 3)
		{
			colorNumber[2] = 4;
		} 



	} while (exitProgram != false);


	system("cls");




}