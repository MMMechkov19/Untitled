#pragma once
#include "structs.h"

void currentPosition(char** arr, int width, int height);
void checkInitialMove(PLAYER& player);
void finalPossition(char** arr, int width, int height);
void printMaze(char** arr, int width, int height);
void movementSystem(bool doesNotWin, char** arr, int width, int height);
void resetArray(char** arr, int width, int height);
int isInBounds(int x, int y, int width, int height);
void cleanTunnels(int x, int y, char** arr, int width, int height);
void gameMode(SIZES size);