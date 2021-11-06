#pragma once

// Declaring and initializing a counter for the movements used to get out of the maze 
__declspec(selectany) int keysPressedCounter = 0;

// Declaring and initializing player's coordinates and symbol
struct PLAYER
{
	char symbol;
	int x;
	int y;
};

// Declaringand maze's sizes
struct SIZES
{
	int WIDTH;
	int HEIGHT;
};