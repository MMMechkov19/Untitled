#pragma once

void printMaze(char** mazeBoard, int keysPressedCounter);
void movementSystem(bool notWin, char** mazeBoard);
void winMessage();
void resetArray(char** arr);
int isInBounds(int x, int y);
void cleanTunnels(int x, int y, char** arr);
void printMaze(char** arr);
void easyMode();
void mazeDeclaration();
