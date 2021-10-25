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
	outputPosition(18, 3);
	cout << "   __  __     __   __     ______   __     ______   __         ______     _____    " << endl;
	outputPosition(18, 4);
	cout << "  /\\ \\/\\ \\   /\\ "" -.\\ \\  / \\__  _\\ /\\ \\   /\\__  _\\ /\\ \\       /\\  ___\\   /\\  __-.  " << endl;
	outputPosition(18, 5);
	cout << "  \\ \\ \\_\\ \\  \\ \\ \\-.  \\ \\/_/\\ \\ / \\ \\ \\  \\/_/\\ \\/ \\ \\ \\____  \\ \\  __\\   \\ \\ \\/\\ \\ " << endl;
	outputPosition(18, 6);
	cout << "   \\ \\_____\\  \\ \\_\\ \\""\\_\\   \\ \\_\\   \\ \\_\\    \\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\____- " << endl;
	outputPosition(18, 7);
	cout << "    \\/_____/   \\/_/ \\/_/    \\/_/    \\/_/     \\/_/   \\/_____/   \\/_____/   \\/____/ " << endl;
}
void choosingModes()
{
	char key1;
	int counter1 = 1;
	int colorNumber1[] = { 7,7,7,7 };
	bool exitStatement = true;

	do {


		outputPosition(56, 10);
		color(colorNumber1[0]);
		cout << "1. Easy Mode";

		outputPosition(56, 11);
		color(colorNumber1[1]);
		cout << "2. Medium Mode";

		outputPosition(56, 12);
		color(colorNumber1[2]);
		cout << "3. Hard Mode";

		outputPosition(56, 13);
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
		printOutRules();

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

	outputPosition(1, 1);
	color(5);
	cout << " *     * *     *    *       *       *     *      *     *      *            *        *   *        *        *     *   *" << endl;
	cout << "   *      *    *        *        *             *           *         *     *      *        *      *      *       *    *" << endl << endl;
	cout << " *    *   *    *    *    *         *      *            *       *          *       *    *    *     *   *    *    *    *      " << endl;
	cout << "    *       *        *      *      *           *                *         *                *           *          " << endl << endl;
	cout << " *    *    *   *        *                *                         *        *             *           *     *    *  * " << endl;
	cout << " *            *      *             *       *                         *                     *    *            *    *    " << endl;
	cout << " *     * *         *       *       *     *      *     *      *            *        *   *        *        *        *" << endl;
	cout << "   *          *         *       *             *           *         *     *      *              *      *       *    *" << endl << endl;
	cout << " *       *            *               *            *       *          *         *      *            *        *      " << endl << endl;
	cout << "    *       *        *      *      *           *                *         *                *           *          " << endl << endl;
	cout << " *    *    *   *        *       *        *          *       *        *        *      *      *     *     *     *    *  * " << endl;
	cout << " *            *      *             *       *           *              *                     *    *            *    *    " << endl;

	color(11);
	cout << "_-_____--____-^--________--^-____________-^---___________--^-^-__________--^-____-^-______________--^-_______-^---_____" << endl;

	outputPosition(1, 2);
	color(7);
	printMainMenu();

	outputPosition(48, 11);
	color(11);
	cout << "G A M E   M O D E" << endl;

	do
	{

		outputPosition(50, 13);
		color(colorNumber[0]);
		cout << "1.  P l a y";

		outputPosition(50, 14);
		color(colorNumber[1]);
		cout << "2.  R u l e s";

		outputPosition(50, 15);
		color(colorNumber[2]);
		cout << "3.  E x i t";



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
				system("CLS");
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

			}

		}

		colorNumber[0] = 7;
		colorNumber[1] = 7;
		colorNumber[2] = 7;

		if (counter == 1)
		{
			colorNumber[0] = 11;

		}
		if (counter == 2)
		{
			colorNumber[1] = 11;
		}
		if (counter == 3)
		{
			colorNumber[2] = 11;
		}

	} while (exitProgram != false);


	system("cls");




}