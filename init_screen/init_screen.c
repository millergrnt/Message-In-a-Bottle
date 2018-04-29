/*
	Author: Grant Miller <gem1086@rit.edu>
	Description:
		Initiates the screen for the program's usage
*/
#include <ncurses.h>
#include <curses.h>
#include <stdlib.h>


/**
	Initiates the screen, clears it for the program to be used
	and creates the object needed for curses to work
	Return:
		Returns an array of integers
		1st Element is the maximum amount of rows
		2nd Element is the maximum amount of colums
*/
int** init_screen(){
	int row, col;
	int** rows_cols;

	rows_cols = malloc(sizeof(int *) * 2);

	initscr();
	clear();
	refresh();
	getmaxyx(stdscr, row, col);

	rows_cols[0] = &row;
	rows_cols[1] = &col;

	return rows_cols;
}


/**
	Destroys the array created when finding screen rows and columns
	Params:
		rows_cols: Array of integers to be freed, only has two elements
*/
void teardown_screen(int **rows_cols){
	free(rows_cols[0]);
	free(rows_cols[1]);
	free(rows_cols);

	return;
}


/**
	Prints string to the screen at specified location
	Params:
		int x: Column Position
		int y: Row Position
		char *: message to be printed
*/
void print_at_pos(int x, int y, char *message){
	mvprintw(x, y, "%s", message);
	refresh();

	return;
}