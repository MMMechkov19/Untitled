#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;
bool exitProgram = true;
void color(int color)
{
    if (SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color)) { return; }
    else {}
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    if (SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c)) { return; }
    else {}
}

void mainMenu()
{

    int Set[] = { 7,7,7 };
    int counter = 3;
    char key;
    cout << endl;
    cout << endl;
    cout << "        _Main menu_" << endl;


    cout << "       |           |   __  __     __   __     ______   __     ______   __         ______     _____    " << endl;
    cout << "       |           |  /\\ \\/\\ \\   /\\ "" -.\\ \\  / \\__  _\\ /\\ \\   /\\__  _\\ /\\ \\       /\\  ___\\   /\\  __-.  " << endl;
    cout << "       |           |  \\ \\ \\_\\ \\  \\ \\ \\-.  \\ \\/_/\\ \\ / \\ \\ \\  \\/_/\\ \\/ \\ \\ \\____  \\ \\  __\\   \\ \\ \\/\\ \\ " << endl;
    cout << "       |           |   \\ \\_____\\  \\ \\_\\ \\""\\_\\   \\ \\_\\   \\ \\_\\    \\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\____- " << endl;
    cout << "       |           |    \\/_____/   \\/_/ \\/_/    \\/_/    \\/_/     \\/_/   \\/_____/   \\/_____/   \\/____/ " << endl;
    cout << "       |           |" << endl;
    cout << "       |___________|" << endl;

    do
    {


        gotoxy(10, 5);
        color(Set[0]);
        cout << "1. PLay";

        gotoxy(10, 6);
        color(Set[1]);
        cout << "2. Help";

        gotoxy(10, 7);
        color(Set[2]);
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

                exitProgram = false;

            }
            if (counter == 2)
            {
                exitProgram = false;

            }
            if (counter == 3)
            {
                exitProgram = false;

            }

        }

        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;





        if (counter == 1)
        {
            Set[0] = 12;

        }
        if (counter == 2)
        {
            Set[1] = 12;
        }
        if (counter == 3)
        {
            Set[2] = 12;
        }



    } while (exitProgram != false);


    system("cls");




}