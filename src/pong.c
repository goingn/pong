/************************************************************************************
 * This file was developed as part of CS3841 Design of Operating Systems at the
 * Milwaukee School of Engineering.  This file is copyright 2008-2015 by MSOE.
 *
 * $Author: wws $
 * $Revision: 1.1 $
 * $Name:  $
 * This file manages serves as the main program for the pong game.
 * It is responsible for spawning all other threads and managing the overall
 * behavior of the game.  All global variables are owned by this file.
 *
 ************************************************************************************/
#define PONG_C

/************************************************************************************
 * External Includes
 ************************************************************************************/
#include <pthread.h>
#include <curses.h>
#include <sys/types.h>
#include <unistd.h>

#include "pong.h"
#include "paddlectrl.h"
#include "ballctrl.h"

#define THREAD_COUNT (2)

/************************************************************************************
 * Method header:
 * Function name: main
 * Function purpose: This is the main function for the program.
 * Function parameters: 
 *                   int argc  - This is a count of the number of command line parameters 
 *                               passed by the operating system.
 *                   char *vp[] - This is the array of strings which is passed to program.
 * Function return value: int.  0 will be returned upon normal exiting of the program.  
 *                                A negative value will indicate an error.
 ************************************************************************************/
int main(int argc, char* argv[]) {
	int rc1;
	int rc2;
	int rc3;

	int index;
	pthread_t threads[THREAD_COUNT];

	// Initialize all of the variables.
	// Global data - for inter-thread communication
	quit = false;

	// init window - see curses documentation for guidance
	win = initscr();
	cbreak();
	noecho();
	curs_set(0);
	keypad(win, TRUE);
	nodelay(win, TRUE);
	refresh();

	// Start the threads
	if ((rc1 = pthread_create(&threads[0], NULL, &moveball, NULL))) {
		fprintf(stderr, "Ball movement thread creation failed.");
	}
	if ((rc2 = pthread_create(&threads[1], NULL, &moveme, NULL))) {
		fprintf(stderr, "Player thread creation failed");
	}

	// Wait for the threads to exit
	for (index = 0; index < THREAD_COUNT; index++) {
		pthread_join(threads[index], NULL);
	}

	// tear down the window
	delwin(win);
	endwin();
	refresh();

	// get out of here
	return 0;
}
