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
 * Constant declarations / table declarations
 ***********************************************************************************/
#define TIME_STR_SIZE 32
#define SEC_IN_MICROSEC 1000000

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
// This thread is the total time timer
void *timer(void* vp) {
	int maxx;
	int maxy;
	getmaxyx(win, maxy, maxx);
	int sec = 0;
	char secChar[TIME_STR_SIZE];
	while (!quit) {
		if (!pauseGame) {
			int posx = maxx / 2;
			(void) snprintf(secChar, TIME_STR_SIZE, "%d", sec);
			pthread_mutex_lock(&mutex);
			for(int i = 0; i < strlen(secChar); i++, posx++) {
				(void) move(maxy - 1, posx);
				(void) addch(secChar[i]);
			}
			(void) addch('s');
			pthread_mutex_unlock(&mutex);
			(void) refresh();
			(void) usleep(SEC_IN_MICROSEC);
			sec++;
		}
	}
	return NULL;
}
