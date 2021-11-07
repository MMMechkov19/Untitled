#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include "mainMenu.h"
#include "mazeFunctions.h"

using namespace std;

// Initializing mazes' sizes for the different difficulties
SIZES easyMode = { 11,11 };
SIZES mediumMode = { 21,21 };
SIZES hardMode = { 21,31 };

/// \file

/// \brief  Change output's colors
/// \param  Color
/// \return void
void color(int color)
{
	if (SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color))
	{
		return;
	}
	else {}
}

/// \file

/// \brief  Set player's fixed position
/// \param  int x, int y
/// \return void
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

/// \file

/// \brief  Print winning message
/// \param  none
/// \return void
void printWinMessage()
{
	color(14);
	outputPosition(19, 3);
	cout << "       ______                             __       __";
	outputPosition(19, 4);
	cout << "      / ____/___  ____  ____ __________ _/ /______/ /" << endl;
	outputPosition(19, 5);
	cout << "     / /   / __ \\/ __ \\/ __ `/ ___/ __ `/ __/ ___/ / " << endl;
	outputPosition(19, 6);
	cout << "    / /___/ /_/ / / / / /_/ / /  / /_/ / /_(__  )_/  " << endl;
	outputPosition(19, 7);
	cout << "    \\____/\\____/_/ /_/\\__, /_/   \\__,_/\\__/____(_)   " << endl;
	outputPosition(19, 8);
	cout << "       __  __        /____/ _       ___       __     " << endl;
	outputPosition(19, 9);
	cout << "       \\ \\/ /___  __  __   | |     / (_)___  / /     " << endl;
	outputPosition(19, 10);
	cout << "        \\  / __ \\/ / / /   | | /| / / / __ \\/ /      " << endl;
	outputPosition(19, 11);
	cout << "        / / /_/ / /_/ /    | |/ |/ / / / / /_/       " << endl;
	outputPosition(19, 12);
	cout << "       /_/\\____/\__,_/      |__/|__/_/_/ /_(_)        " << endl;

	// Print the movements used to get out of the maze
	outputPosition(37, 14);
	color(7);
	cout << "USED MOVEMENTS: " << keysPressedCounter << endl;
}

/// \file

/// \brief  Print team logo
/// \param  none
/// \return void
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

/// \file

/// \brief  Print starry background
/// \param  none
/// \return void
void printBackground()
{
	color(3);
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

/// \file

/// \brief  Print ground
/// \param  none
/// \return void 
void printGround()
{
	color(11);
	outputPosition(8, 26);
	cout << "_____--^-__/\\----___________-^--__^--/\\--_________--^--^-/\\-__________--^---" << endl;
	outputPosition(8, 27);
	cout << " --^--        /\\---  __-^-___/\\__                      ---^--/\\^___  --^--__" << endl;
	outputPosition(8, 28);
	cout << "       ---_     __-                   __-       --__                _-      " << endl;
	outputPosition(8, 29);
	cout << "   ____                __       --         -__-           -_             __-";
}


/// \file

/// \brief  Print game machine
/// \param  none
/// \return void 
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
	cout << "o          ";
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

/// \file

/// \brief  This function lets you choose a game mode
/// \param  none
/// \return void 
void choosingModes()
{
	char key1;
	int counter1 = 1;
	int colorNumber1[] = { 7,7,7,7 };
	bool exitStatement = true;

	bool alreadyPlayed = false;

	do {

		// Check weather the player has already played the game
		if (alreadyPlayed == false)
		{
			printGameMachine();
			// Print team logo
			printLogo();
			printGround();
		}
		else
		{
			printGameMachine();
			// Print winning message
			printWinMessage();
			printGround();
		}


		// Set different output coordinates depending on the displayed message
		if (alreadyPlayed == true) 
		{
			outputPosition(38, 16);
		}
		else
		{
			outputPosition(38, 15);
		}
		
		color(14);
		cout << "G A M E   M O D E" << endl;


		// Set different output coordinates depending on the displayed message
		if (alreadyPlayed == true)
		{
			outputPosition(38, 23);
		}
		else
		{
			outputPosition(38, 22);
		}

		color(14);
		cout << "TEAM  UNTITLED";


		// Set different output coordinates depending on the displayed message

		printGround();

		if (alreadyPlayed == true)
		{
			outputPosition(38, 18);
		}
		else
		{
			outputPosition(38, 17);
		}

		color(colorNumber1[0]);
		cout << "EASY MODE";


		// Set different output coordinates depending on the displayed message

		if (alreadyPlayed == true)
		{
			outputPosition(38, 19);
		}
		else
		{
			outputPosition(38, 18);
		}

		color(colorNumber1[1]);
		cout << "MEDIUM MODE";


		// Set different output coordinates depending on the displayed message
		if (alreadyPlayed == true)
		{
			outputPosition(38, 20);
		}
		else
		{
			outputPosition(38, 19);
		}

		color(colorNumber1[2]);
		cout << "HARD MODE";


		// Set different output coordinates depending on the displayed message
		if (alreadyPlayed == true)
		{
			outputPosition(38, 21);
		}
		else
		{
			outputPosition(38, 20);
		}

		color(colorNumber1[3]);
		cout << "BACK TO MAIN MENU";

		key1 = _getch();

		// Move up through the menu
		if (key1 == 'w' && (counter1 >= 2 && counter1 <= 5))
		{
			counter1--;
		}
		// Move down through the menu
		if (key1 == 's' && (counter1 >= 1 && counter1 <= 3))
		{
			counter1++;
		}
		if (key1 == '\r') {
			// Resset movements' counter
			keysPressedCounter = 0;

			// Easy mode
			if (counter1 == 1)
			{
				system("CLS");
				gameMode(easyMode);
				alreadyPlayed = true;
			}
			// Medium mode
			if (counter1 == 2)
			{
				system("CLS");
				gameMode(mediumMode);
				alreadyPlayed = true;
			}
			// Hard mode
			if (counter1 == 3)
			{
				system("CLS");
				gameMode(hardMode);
				alreadyPlayed = true;
			}
			// Go back to main menu
			if (counter1 == 4)
			{
				system("CLS");
				system("color 7");
				printLogo();
				mainMenu();
				exitStatement = false;
			}
		}

		// Resset options' color
		colorNumber1[0] = 7;
		colorNumber1[1] = 7;
		colorNumber1[2] = 7;
		colorNumber1[3] = 7;

		// Change option's color if it is selected
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

/// \file

/// \brief  This function prints the game rules
/// \param  none
/// \return void 
void printOutRules()
{
	// Print game machine
	printGameMachine();

	// Print rules
	color(14);
	outputPosition(30, 6);
	cout << "    ____        __              ";
	outputPosition(30, 7);
	cout << "   / __ \\__  __/ /__  _____   _ " << endl;
	outputPosition(30, 8);
	cout << "  / /_/ / / / / / _ \\/ ___/  (_)" << endl;
	outputPosition(30, 9);
	cout << " / _, _/ /_/ / /  __(__  )  _   " << endl;
	outputPosition(30, 10);
	cout << "/_/ |_|\\__,_/_/\\___/____/  (_)  " << endl;

	outputPosition(37, 13);
	color(14);
	cout << "G A M E   R U L E S" << endl;

	color(7);
	outputPosition(11, 15);
	cout << "Hello, this is a C++ console maze game!" << endl;

	outputPosition(11, 17);
	cout << " - The game functions with the WSAD keys" << endl;

	outputPosition(11, 18);
	cout << " - There are 3 difficulties of the maze" << endl;

	outputPosition(11, 19);
	cout << " - To win you have to move the 'o' through the maze to the final(F)" << endl;

	outputPosition(11, 20);
	cout << " - You can go back by pressing ENTER" << endl;

	outputPosition(11, 21);
	cout << " - Enjoy the game!" << endl;

	// Print ground
	printGround();
}

/// \file

/// \brief  This function prints the game rules
/// \param  none
/// \return void 
void rules()
{
	char key;
	bool exitStatement = true;

	do
	{
		printOutRules();

		outputPosition(60, 23);
		color(14);
		cout << "BACK TO MAIN MENU";

		key = _getch();

		// Go back to main menu 
		if (key == '\r')
		{
			exitStatement = false;

			system("CLS");

			printGameMachine();
			printBackground();
			printLogo();
			mainMenuTexts();
		}

	} while (exitStatement != false);

}

/// \file

/// \brief  Print main menu basics
/// \param  none
/// \return void 
void mainMenuTexts()
{
	outputPosition(38, 15);
	color(14);
	cout << "G A M E   M E N U" << endl;

	outputPosition(38, 21);
	cout << "TEAM  UNTITLED";

	outputPosition(14, 25);
	cout << "Maze Game Sprint";

	outputPosition(59, 25);
	cout << "Move using the WASD";
}

/// \file

/// \brief  Print main menu
/// \param  none
/// \return void 
void mainMenu()
{
	int colorNumber[] = { 7, 7, 7, 7 };
	int counter = 1;
	char key;
	bool exitProgram = true;

	printGameMachine();
	printBackground();
	printLogo();
	mainMenuTexts();

	while (exitProgram != false)
	{
		// Main menu options
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

		// Move up through the menu
		if (key == 'w' && (counter >= 2 && counter <= 5))
		{
			counter--;
		}
		// Move down through the menu
		if (key == 's' && (counter >= 1 && counter <= 2))
		{
			counter++;
		}
		// Select option
		if (key == '\r')
		{
			// Choosing mode option
			if (counter == 1)
			{
				system("CLS");
				choosingModes();
			}

			// Rules option
			if (counter == 2)
			{
				system("CLS");
				rules();
			}

			// Exit option
			if (counter == 3)
			{
				system("CLS");
				color(7);
				exit(-1);
			}
		}

		// Resset options' color 
		colorNumber[0] = 7;
		colorNumber[1] = 7;
		colorNumber[2] = 7;

		// Change option's color if it is selected
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
	}
}
