#pragma once

const int KEY_LEFT = 'a', KEY_RIGHT = 'd', KEY_UP = 'w', KEY_DOWN = 's';

extern int keysPressedCounter = 0;

enum size
{
	WIDTH = 11,
	HEIGHT = 11
};

struct Player
{
	char symbol;
	int x;
	int y;
};

enum directions
{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3
};