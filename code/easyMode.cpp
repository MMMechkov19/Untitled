#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "easyMode.h"

using namespace std;

void printMaze(char** mazeBoard, int keysPressedCounter);
void movementSystem(bool notWin, char** mazeBoard);
void winMessage();
void mazeDeclaration();

int main()
{
	mazeDeclaration();
}