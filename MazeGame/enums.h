#pragma once
// Declaring and initializing WASD keys
enum class KEY : char
{
	LEFT = 'a',
	RIGHT = 'd',
	UP = 'w',
	DOWN = 's'
};

// Declaring and initializing the directions in which the maze cleaning function will try to clean tunnels
enum DIRECTIONS
{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3
};
