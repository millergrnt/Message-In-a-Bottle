/*
	Author: Grant Miller <gem1086@rit.edu>
	Description:
		Initiates the screen for the program's usage
		Header file
*/

/**
	Initiates the screen, clears it for the program to be used
	and creates the object needed for curses to work
*/
int** init_screen();

/**
	Destroys the array created when finding screen rows and columns
	Params:
		rows_cols: Array of integers to be freed, only has two elements
*/
void teardown_screen(int **rows_cols);

/**
	Prints string to the screen at specified location
	Params:
		int x: Column Position
		int y: Row Position
		char *: message to be printed
*/
void print_at_pos(int x, int y, char *message);