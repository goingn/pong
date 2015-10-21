/************************************************************************************
 * This file was developed as part of CS3841 Design of Operating Systems at the
 * Milwaukee School of Engineering.  This file is copyright 2008-2015 by MSOE.
 *
 * $Author: wws $
 * $Revision: 1.1 $
 * $Name:  $
 * This file manages the timer.
 *
 ************************************************************************************/

/************************************************************************************
 * External Includes
 ************************************************************************************/
#include <unistd.h>
#include <string.h>
#include "pong.h"

/************************************************************************************
 * Method header:
 * Function name: timer
 * Function purpose: This function is responsible for keeping and displaying time
 * 					 elapsed.
 * Function parameters:
 *                   void *vp - This is a pointer to the parameters passed into the
 *                              thread.  At the present time, this parameter is not used.
 * Function return value: void* This is the return value when the thread exits.
 *                              Currently, it is always NULL, as no data is directly
 *                              returned by the thread.
 ************************************************************************************/
// This thread is responsible for moving the ball
void *timer(void* vp) {
	int maxx;
	int maxy;
	getmaxyx(win, maxy, maxx);
	int sec = 0;
	char secChar[32];
	while (!quit) {
		if (!pauseGame) {
			int posx = maxx / 2;
			snprintf(secChar, 32, "%d", sec);
			for(int i = 0; i < strlen(secChar); i++, posx++) {
				move(maxy - 1, posx);
				addch(secChar[i]);
			}
			addch('s');
			usleep(1000000);
			sec++;
		}
	}
	return NULL;
}
