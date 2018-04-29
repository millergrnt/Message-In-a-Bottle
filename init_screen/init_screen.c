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
*/
int init_screen(){
	initscr();
	clear();
	refresh();

	return EXIT_SUCCESS;
}