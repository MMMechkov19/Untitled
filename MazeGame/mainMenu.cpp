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

void printLogo()
{
	color(14);
	outputPosition(28, 2);
	cout << "   __  __      __  _ __  __         __";
	outputPosition(28, 3);
	cout << "  / / / /___  / /_(_) /_/ /__  ____/ /" << endl;
	outputPosition(28, 4);
	cout << " / / / / __ \\/ __/ / __/ / _ \\/ __  / " << endl;
	outputPosition(28, 5);
	cout << "/ /_/ / / / / /_/ / /_/ /  __/ /_/ /  " << endl;
	outputPosition(28, 6);
	cout << "\\____/_/ /_/\\__/_/\\__/_/\\___/\\__,_/   " << endl;
}

void printBackground()
{
	outputPosition(1, 1);
	color(11);
	cout << "         +         *             .         '         *               '            *                " << endl;
	cout << "                                                                                                 " << endl;
	cout << "   *            *          .                                +                          *         " << endl;
	cout << "                                             +                            *                      " << endl;
	cout << "    .                 .         *                             .                   +           +  " << endl;
	cout << "           +                                                                                     " << endl;
	cout << "                         *        '                     *                     +            .      " << endl;
	cout << "    *                                    *                          *                            " << endl;
	cout << "         +         *             .                  *                           *                " << endl;
	cout << "                                                                                                 " << endl;
	cout << "   *            *          .                                +                          *         " << endl;
	cout << "                                             +                            *                      " << endl;
	cout << "    .                 .         *                             .                   +           +  " << endl;
	cout << "           +    '                                                                                " << endl;
	cout << "                         *        '                '     *                     +            .      " << endl;
	cout << "    *                                    *                          *                            " << endl;
	cout << "      .          +                                                                  *            " << endl;
	cout << "                              +      '           .           *               .                +  " << endl;
	cout << "           +                                                                                     " << endl;
	cout << "                         *                             *                     +            .      " << endl;
}

void printGround()
{

	outputPosition(1, 16);
	color(11);
	cout << "_____--^-__/\\----___________-^--__^--/\\--_________--^--^-/\\-__________--^---_______--/\\^-______--^--_____" << endl;
	cout << " --^--        /\\---  __-^-___/\\__                      ---^--/\\^___  --^--__               --^-   __/\\__ " << endl;
	cout << "       ---_     __-                   __-       --__                _-          ---_____        -_--     ";
}

void printMainMenu()
{
	outputPosition(39, 9);
	color(14);
	cout << "G A M E   M E N U" << endl;

	outputPosition(39, 13);
	color(14);
	cout << "Team Untitled";

	outputPosition(10, 17);
	color(14);
	cout << "Maze Game Sprint";

	outputPosition(66, 17);
	color(14);
	cout << "Move using the WASD";

}

void choosingModes()
{
	char key1;
	int counter1 = 1;
	int colorNumber1[] = { 7,7,7,7 };
	bool exitStatement = true;

	outputPosition(1, 2);
	color(7);
	printLogo();

	outputPosition(39, 9);
	color(14);
	cout << "G A M E   M O D E" << endl;

	outputPosition(39, 14);
	color(14);
	cout << "Team Untitled";

	printGround();

	do {
		outputPosition(39, 10);
		color(colorNumber1[0]);
		cout << "Easy Mode";

		outputPosition(39, 11);
		color(colorNumber1[1]);
		cout << "Medium Mode";

		outputPosition(39, 12);
		color(colorNumber1[2]);
		cout << "Hard Mode";

		outputPosition(39, 13);
		color(colorNumber1[3]);
		cout << "Back to Main Menu";

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
			if (counter1 == 7)
			{
				exitStatement = true;
			}
			if (counter1 == 7)
			{
				exitStatement = true;
			}
			if (counter1 == 4)
			{
				system("CLS");
				system("color 7");
				mainMenu();
				exitStatement = false;
			}
		}

		colorNumber1[0] = 7;
		colorNumber1[1] = 7;
		colorNumber1[2] = 7;
		colorNumber1[3] = 7;

		if (counter1 == 1)
		{
			colorNumber1[0] = 12;
		}
		if (counter1 == 2)
		{
			colorNumber1[1] = 12;
		}
		if (counter1 == 3)
		{
			colorNumber1[2] = 12;
		}
		if (counter1 == 4)
		{
			colorNumber1[3] = 12;
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
			printLogo();
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

	printBackground();

	outputPosition(1, 2);
	color(7);
	printLogo();

	printMainMenu();
	
	do
	{
		outputPosition(39, 10);
		color(colorNumber[0]);
		cout << "P l a y";

		outputPosition(39, 11);
		color(colorNumber[1]);
		cout << "R u l e s";

		outputPosition(39, 12);
		color(colorNumber[2]);
		cout << "E x i t";

		key = _getch();

		if (key == 'w' && (counter >= 2 && counter <= 5))	
		{
				counter--;
		}
		if (key == 's' && (counter >= 1 && counter <= 2))
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
				system("color 7");

			}

		}

		colorNumber[0] = 7;
		colorNumber[1] = 7;
		colorNumber[2] = 7;

		if (counter == 1)
		{
			colorNumber[0] = 12;

		}
		if (counter == 2)
		{
			colorNumber[1] = 12;
		}
		if (counter == 3)
		{
			colorNumber[2] = 12;
		}

	} while (exitProgram != false);

	system("cls");




}
