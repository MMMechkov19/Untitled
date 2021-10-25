#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include "easyMode.h"
#include "mainMenu.h"

using namespace std;



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

void printMainMenu()
{
	cout << endl;
	cout << endl;

	cout << "        __  __     __   __     ______   __     ______   __         ______     _____    " << endl;
	cout << "       /\\ \\/\\ \\   /\\ "" -.\\ \\  / \\__  _\\ /\\ \\   /\\__  _\\ /\\ \\       /\\  ___\\   /\\  __-.  " << endl;
	cout << "       \\ \\ \\_\\ \\  \\ \\ \\-.  \\ \\/_/\\ \\ / \\ \\ \\  \\/_/\\ \\/ \\ \\ \\____  \\ \\  __\\   \\ \\ \\/\\ \\ " << endl;
	cout << "        \\ \\_____\\  \\ \\_\\ \\""\\_\\   \\ \\_\\   \\ \\_\\    \\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\____- " << endl;
	cout << "         \\/_____/   \\/_/ \\/_/    \\/_/    \\/_/     \\/_/   \\/_____/   \\/_____/   \\/____/ " << endl;
}

void choosingModes()
{
	char key1;
	int counter1 = 1;
	int colorNumber1[] = { 7,7,7,7 };
	bool exitStatement = true;

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

		outputPosition(5, 13);
		color(colorNumber1[3]);
		cout << "4. Back to Main Menu";

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
				printMainMenu();
			}
			if (counter1 == 2)
			{
				exitStatement = true;
			}
			if (counter1 == 3)
			{
				exitStatement = true;
			}
			if (counter1 == 4)
			{
				system("CLS");
				system("color 7");
				printMainMenu();
				exitStatement = false;
			}
		}

		colorNumber1[0] = 7;
		colorNumber1[1] = 7;
		colorNumber1[2] = 7;
		colorNumber1[3] = 7;

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
		if (counter1 == 4)
		{
			colorNumber1[3] = 4;
		}

	} while (exitStatement != false);
}
void printOutRules()
{
	cout << "                                                 Listen, there are rules.                       " << endl;
	cout << "1. The game functions with W,S,A,D keys" << endl;
	cout << "2. There are 3 difficulties - easy(10x10),medium(20x20) and hard(30x30)" << endl;
	cout << "3. Guide the 'S' towards the 'F' to exit the maze, or go to the 'O' to unlock a secret finish" << endl;
	cout << "4. Enjoy the game!" << endl;

}

void rules()
{
	char key;
	int colorNumber[] = { 4 };
	bool exitStatement = true;

	printOutRules();

	do
	{
		outputPosition(5, 10);
		color(colorNumber[0]);
		cout << "1. Back to Main Menu";
		key = _getch();
		if (key == '\r')
		{
			exitStatement = false;
			system("CLS");
			system("color 7");
			printMainMenu();
		}
		else {}




	} while (exitStatement != false);

}
void mainMenu()
{

	int colorNumber[] = { 7, 7, 7, 7 };
	int counter = 1;
	char key;
	bool exitProgram = true;

	printMainMenu();

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
				choosingModes();
			}
			if (counter == 2)
			{
				system("CLS");
				rules();
			}
			if (counter == 3)
			{
				exitProgram = false;
				system("CLS");
				system("color 7");

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
