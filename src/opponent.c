/************************************************************************************
 * This file was developed as part of CS3841 Design of Operating Systems at the
 * Milwaukee School of Engineering.  This file is copyright 2008-2015 by MSOE.
 *
 * $Author: wws $
 * $Revision: 1.1 $
 * $Name:  $
 * This file manages the motion of the computer player's paddle
 *
 ************************************************************************************/
#define OPPONENT_C

/************************************************************************************
 * External Includes
 ************************************************************************************/
#include <curses.h>
#include "pong.h"

/************************************************************************************
 * Private structure / type definitions
 ************************************************************************************/
#define PADDLE_SIZE (5)

/************************************************************************************
 * Private function / method prototypes
 ************************************************************************************/
static void drawPaddle(int maxx, int center);
static void undrawPaddle(int maxx,int center);

/************************************************************************************
 * Constant declarations / table declarations
 ***********************************************************************************/
static int oldBally;

/************************************************************************************
 * Method header:
 * Function name: drawPaddle
 * Function purpose: This function is responsible for drawing the paddle on the screen.
 * Function parameters:
 *                   int center - This is an integer value representing the center of
 *                                the paddle.
 * Function return value: None
 ************************************************************************************/
static void drawPaddle(int maxx, int center) {
	int i;

	for (i = center - (PADDLE_SIZE / 2); i <= center + (PADDLE_SIZE / 2); i++) {
		(void) move(i, maxx-1);
		(void) addch('|');
	}
}

/************************************************************************************
 * Method header:
 * Function name: undrawPaddle
 * Function purpose: This function is responsible for undrawing the paddle on the screen.
 * Function parameters:
 *                   int center - This is an integer value representing the center of
 *                                the paddle.
 * Function return value: None
 ************************************************************************************/
static void undrawPaddle(int maxx, int center) {
	int i;

	for (i = center - (PADDLE_SIZE / 2); i <= center + (PADDLE_SIZE / 2); i++) {
		(void) move(i, maxx-1);
		(void) addch(' ');
	}
}

/************************************************************************************
 * Method header:
 * Function name: moveopponent
 * Function purpose: This function is responsible for moving the computer's paddle.
 *                   It is spawned as a thread and will exit if and when quit is no longer true.
 * Function parameters:
 *                   void *vp - This is a pointer to the parameters passed into the
 *                              thread.  At the present time, this parameter is not used.
 * Function return value: void* This is the return value when the thread exits.
 *                              Currently, it is always NULL, as no data is directly
 *                              returned by the thread.
 ************************************************************************************/
// Run the computer's paddle
void *moveopponent(void* vp) {
	int ch;

	// get the extents of the screen
	int maxx;
	int maxy;
	getmaxyx(win, maxy, maxx);
	int vpos = maxy / 2;

	// draw the default paddle
	drawPaddle(maxx, vpos);

	//find the difference of the ball from the old position
	int yPositionChange = bally - oldBally;

	if(yPositionChange > 0){

	}
	else if(yPositionChange < 0){

	}
	else{

	}



	while (!quit) {

		case KEY_UP: // The user has pressed the up arrow.  Move the paddle one pixel upwards if possible.
			if (!pauseGame) {
				undrawPaddle(maxx, vpos);
				vpos--;
				if (vpos < 0 + PADDLE_SIZE / 2) {
					vpos = PADDLE_SIZE / 2;
				}
				drawPaddle(maxx, vpos);
			}
			break;

		case KEY_DOWN: // The user has pressed the down arrow.  Move the paddle one pixel downward if possible.
			if (!pauseGame) {
				undrawPaddle(maxx, vpos);
				vpos++;
				if (vpos > (maxy - (PADDLE_SIZE / 2))) {
					vpos = (maxy - (PADDLE_SIZE / 2));
				}
				drawPaddle(maxx, vpos);
			}
			break;

	}
	return NULL;
}
