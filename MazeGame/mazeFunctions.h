#pragma once

void currentPossition(char** arr);
void checkInitialMove(PLAYER& player);
void finalPossition(char** arr);
void movementSystem(bool doesNotWin, char** arr);
void winMessage();
void resetArray(char** arr);
int isInBounds(int x, int y);
void cleanTunnels(int x, int y, char** arr);