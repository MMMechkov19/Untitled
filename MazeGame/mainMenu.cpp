﻿#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include "mainMenu.h"
#include "mazeFunctions.h"

using namespace std;

SIZES easyMode = { 11,11 };
SIZES mediumMode = { 21,21 };
SIZES hardMode = { 29,29 };

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

void printWinMessage()
{
	color(14);
	outputPosition(19, 2);
	cout << "       ______                             __       __";
	outputPosition(19, 3);
	cout << "      / ____/___  ____  ____ __________ _/ /______/ /" << endl;
	outputPosition(19, 4);
	cout << "     / /   / __ \\/ __ \\/ __ `/ ___/ __ `/ __/ ___/ / " << endl;
	outputPosition(19, 5);
	cout << "    / /___/ /_/ / / / / /_/ / /  / /_/ / /_(__  )_/  " << endl;
	outputPosition(19, 6);
	cout << "    \\____/\\____/_/ /_/\\__, /_/   \\__,_/\\__/____(_)   " << endl;
	outputPosition(19, 7);
	cout << "       __  __        /____/ _       ___       __     " << endl;
	outputPosition(19, 8);
	cout << "       \\ \\/ /___  __  __   | |     / (_)___  / /     " << endl;
	outputPosition(19, 9);
	cout << "        \\  / __ \\/ / / /   | | /| / / / __ \\/ /      " << endl;
	outputPosition(19, 10);
	cout << "        / / /_/ / /_/ /    | |/ |/ / / / / /_/       " << endl;
	outputPosition(19, 11);
	cout << "       /_/\\____/\__,_/     |__/|__/_/_/ /_(_)        " << endl;
	
}

void printLogo()
{
	color(14);
	outputPosition(22, 7);
	cout << "   __  ___   ____________________    __________ ";
	outputPosition(22, 8);
	cout << "  / / / / | / /_  __/  _/_  __/ /   / ____/ __ \\" << endl;
	outputPosition(22, 9);
	cout << " / / / /  |/ / / /  / /  / / / /   / __/ / / / /" << endl;
	outputPosition(22, 10);
	cout << "/ /_/ / /|  / / / _/ /  / / / /___/ /___/ /_/ / " << endl;
	outputPosition(22, 11);
	cout << "\\____/_/ |_/ /_/ /___/ /_/ /_____/_____/_____/  " << endl;
}

void printGame()
{
	outputPosition(21, 8);
	color(15);
	cout << "  __  __   _    _______    ___   _   __  __ ___ " << endl;
	outputPosition(13, 9);
	color(7);
	cout << char(254) << char(254) << char(254) << char(254) << char(254) << char(254) << char(254) << char(254);
	color(15);
	cout << " |  \\/  | /_\\  |_  / __|  / __| /_\\ |  \\/  | __| ";
	color(7);
	cout << char(254) << char(254) << char(254) << char(254) << char(254) << char(254) << char(254) << char(254) << endl;
	outputPosition(13, 10);
	color(6);
	cout << char(254) << char(254) << char(254) << char(254) << char(254) << char(254) << char(254) << char(254);
	color(15);
	cout << " | |\\/| |/ _ \\  / /| _|  | (_ |/ _ \\| |\\/| | _|  ";
	color(6);
	cout << char(254) << char(254) << char(254) << char(254) << char(254) << char(254) << char(254) << char(254) << endl;
	outputPosition(13, 11);
	color(3);
	cout << char(254) << char(254) << char(254) << char(254) << char(254) << char(254) << char(254) << char(254);
	color(15);
	cout << " |_|  |_/_/ \\_\\/___|___|  \\___/_/ \\_\\_|  |_|___| ";
	color(3);
	cout << char(254) << char(254) << char(254) << char(254) << char(254) << char(254) << char(254) << char(254) << endl;
}

void printBackground()
{
	color(11);
	outputPosition(8, 4);
	cout << "   *            *          .                                +            *  " << endl;
	outputPosition(8, 5);
	cout << "                                             +                              " << endl;
	outputPosition(8, 6);
	cout << "    .                 .         *                                   '       " << endl;
	outputPosition(8, 7);
	cout << "           +                                                    +           " << endl;
	outputPosition(8, 8);
	cout << "                         *        '                     *                   " << endl;
	outputPosition(8, 9); 
	cout << "    *                                    *                            *     " << endl;
	outputPosition(8, 10);
	cout << "         +         *             .                  *        +              " << endl;
	outputPosition(8, 11);
	cout << "                                          '                                " << endl;
	outputPosition(8, 12);
	cout << "   *            *          .                                +               " << endl;
	outputPosition(8, 13);
	cout << "                                             +                      *       " << endl;
	outputPosition(8, 14);
	cout << "    .                 .         *                             .             " << endl;
	outputPosition(8, 15);
	cout << "           +    '                                                      .    " << endl;
	outputPosition(8, 16);
	cout << "                         *        '                '     *                  " << endl;
	outputPosition(8, 17); 
	cout << "    *                                    *                                 " << endl;
	outputPosition(8, 18);
	cout << "      .          +                                                         " << endl;
	outputPosition(8, 19);
	cout << "                              +      '           .              *          " << endl;
	outputPosition(8, 20);
	cout << "           +                                                              " << endl;
	outputPosition(8, 21);
	cout << "                         *                             *                  " << endl;
	outputPosition(8, 22);
	cout << "         +         *             .         '         *                 '  " << endl;
	outputPosition(8, 23);
	cout << "                                                                   *      " << endl;
	outputPosition(8, 24);
	cout << "   *            *          .                                  +           " << endl;
	outputPosition(8, 25);
	cout << "                    '                        +                         +   " << endl;
	outputPosition(8, 26);
	cout << "    .                 .         *                               .         " << endl;
	outputPosition(8, 27);
	cout << "           +                                                              " << endl;
	outputPosition(8, 28);
	cout << "                         *        '                     *          .      " << endl;
	outputPosition(8, 29);
	cout << "         +         *             .         '         *         '        *  " << endl;
}

void printGround()
{
	outputPosition(1, 18);
	color(11);
	cout << "_____--^-__/\\----___________-^--__^--/\\--_________--^--^-/\\-__________--^---_______--/\\^-______--^--_____" << endl;
	cout << " --^--        /\\---  __-^-___/\\__                      ---^--/\\^___  --^--__               --^-   __/\\__ " << endl;
	cout << "       ---_     __-                   __-       --__                _-          ---_____        -_--     ";
}

void printGameMachine()
{
	outputPosition(0, 1);
	color(5);
	cout << "      ________________________________________________________________________________" << endl;
	cout << "     |  ____________________________________________________________________________  |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |____________________________________________________________________________| |" << endl;
	cout << "     |________________________________________________________________________________|" << endl;
	cout << "    /    ";
	color(7);
	cout << char(254) << char(254) << char(254);
	cout << "                                                                   ";
	cout << char(254) << char(254) << char(254);
	color(5);
	cout << "     \\  " << endl;
	cout << "   /     ";
	color(7);
	cout << "_|_";
	color(13);
	cout << "          o ";
	color(5);
	cout << "o";
	color(7);
	cout << " o";
	color(2);
	cout << " o";
	color(14);
	cout << " o";
	color(15);
	cout << " o";
	color(9);
	cout << " o";
	color(11);
	cout << " o";
	color(10);
	cout << " o";
	color(6);
	cout << " o";
	color(13);
	cout << " o";
	color(12);
	cout << " o";
	color(15);
	cout << " o";
	color(4);
	cout << " o";
	color(5);
	cout << " o";
	color(3);
	cout << " o";
	color(9);
	cout << " o";
	color(6);
	cout << " o";
	color(8);
	cout << " o";
	color(5);
	cout << " o";
	color(10);
	cout << " o";
	color(4);
	cout << " o";
	color(3);
	cout << " o ";
	color(12);
    cout <<"o          ";
	color(7);
	cout << "_|_";
	color(5);
	cout << "      \\" << endl;
	cout << "  /     ";
	color(7);
	cout << "|___|";
	color(13);
	cout << "         o ";
	color(12);
	cout << "o";
	color(14);
	cout << " o";
	color(3);
	cout << " o";
	color(4);
	cout << " o";
	color(5);
	cout << " o";
	color(6);
	cout << " o";
	color(7);
	cout << " o";
	color(9);
	cout << " o";
	color(10);
	cout << " o";
	color(11);
	cout << " o";
	color(5);
	cout << " o";
	color(13);
	cout << " o";
	color(14);
	cout << " o";
	color(15);
	cout << " o";
	color(2);
	cout << " o";
	color(3);
	cout << " o";
	color(4);
	cout << " o";
	color(14);
	cout << " o";
	color(4);
	cout << " o";
	color(6);
	cout << " o";
	color(8);
	cout << " o";
	color(10);
	cout << " o ";
	color(14);
	cout << "o         ";
	color(7);
	cout << "|___|";
	color(5);
	cout << "      \\" << endl;
	color(5);
	cout << " /________________________________________________________________________________________\\" << endl;
}

void choosingModes()
{
	char key1;
	int counter1 = 1;
	int colorNumber1[] = { 7,7,7,7 };
	bool exitStatement = true;

	bool alredayPlayed = false;

	do {

		if (alredayPlayed == false)
		{
			outputPosition(1, 2);
			color(7);
			printLogo();
		}
		else
		{
			outputPosition(1, 2);
			color(7);
			printWinMessage();
		}

		outputPosition(39, 9);
		color(14);
		cout << "G A M E   M O D E" << endl;

		outputPosition(39, 16);
		color(14);
		cout << "Team Untitled";

		printGround();

		outputPosition(39, 11);
		color(colorNumber1[0]);
		cout << "Easy Mode";

		outputPosition(39, 12);
		color(colorNumber1[1]);
		cout << "Medium Mode";

		outputPosition(39, 13);
		color(colorNumber1[2]);
		cout << "Hard Mode";

		outputPosition(39, 14);
		color(colorNumber1[3]);
		cout << "Back to Main Menu";

		key1 = _getch();

		if (key1 == 'w' && (counter1 >= 2 && counter1 <= 5))
		{
			counter1--;
		}

		if (key1 == 's' && (counter1 >= 1 && counter1 <= 3))
		{
			counter1++;
		}
		if (key1 == '\r') {

			if (counter1 == 1)
			{
				system("CLS");
				gameMode(easyMode);
				alredayPlayed = true;
			}
			if (counter1 == 2)
			{
				system("CLS");
				gameMode(mediumMode);
			}
			if (counter1 == 3)
			{
				system("CLS");
				gameMode(hardMode);
			}
			if (counter1 == 4)
			{
				system("CLS");
				system("color 7");
				printLogo();
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
	color(14);
	outputPosition(34, 1);
	cout << "    ____        __              ";
	outputPosition(34, 2);
	cout << "   / __ \\__  __/ /__  _____   _ " << endl;
	outputPosition(34, 3);
	cout << "  / /_/ / / / / / _ \\/ ___/  (_)" << endl;
	outputPosition(34, 4);
	cout << " / _, _/ /_/ / /  __(__  )  _   " << endl;
	outputPosition(34, 5);
	cout << "/_/ |_|\\__,_/_/\\___/____/  (_)  " << endl;

	outputPosition(39, 7);
	color(14);
	cout << "G A M E   R U L E S" << endl;

	outputPosition(33, 9);
	color(7);
	cout << "The game functions with WSAD keys" << endl;
	outputPosition(17, 10);
	color(7);
	cout << "There are 3 difficulties - Easy(10x10), Medium(20x20) and Hard(30x30)" << endl;
	outputPosition(4, 11);
	color(7);
	cout << "Guide the 'S' towards the 'F' to exit the maze, or go to the 'o' to unlock a secret finish" << endl;
	outputPosition(41, 12);
	color(7);
	cout << "Enjoy the game!" << endl;

	printGround();
}
void rules()
{
	char key;
	int colorNumber[] = { 14 };
	bool exitStatement = true;

	do
	{
		printOutRules();

		outputPosition(40, 14);
		color(colorNumber[0]);
		cout << "Back To Main Menu";
		key = _getch();
		if (key == '\r')
		{
			exitStatement = false;
			system("CLS");
			color(14);
			printBackground();
			printLogo();
			printMainMenu();
		}
		else {}

	} while (exitStatement != false);

}

void printMainMenu()
{
	outputPosition(38, 15);
	color(6);
	cout << "G A M E   M E N U" << endl;

	outputPosition(38, 21);
	cout << "TEAM  UNTITLED";

	outputPosition(14, 25);
	cout << "Maze Game Sprint";

	outputPosition(59, 25);
	cout << "Move using the WASD";

}

void mainMenu()
{

	int colorNumber[] = { 7, 7, 7, 7 };
	int counter = 1;
	char key;
	bool exitProgram = true;

	printGameMachine();
	printBackground();

	outputPosition(1, 2);
	color(7);
	printLogo();

	printMainMenu();

	do
	{
		outputPosition(38, 17);
		color(colorNumber[0]);
		cout << "P L A Y";

		outputPosition(38, 18);
		color(colorNumber[1]);
		cout << "R U L E S";

		outputPosition(38, 19);
		color(colorNumber[2]);
		cout << "E X I T";

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
