/************************************************************************************
 * This file was developed as part of CS3841 Design of Operating Systems at the
 * Milwaukee School of Engineering.  This file is copyright 2008-2015 by MSOE.
 *
 * $Author: wws $
 * $Revision: 1.1 $
 * $Name:  $
 * This file manages the splash screen.
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
#define TWO_SEC_IN_MICROSEC 2000000

/************************************************************************************
 * Method header:
 * Function name: splashscreen
 * Function purpose: This function is responsible for displaying the splash screen.
 * Function parameters:
 *                   void *vp - This is a pointer to the parameters passed into the
 *                              thread.  At the present time, this parameter is not used.
 * Function return value: void* This is the return value when the thread exits.
 *                              Currently, it is always NULL, as no data is directly
 *                              returned by the thread.
 ************************************************************************************/
// This thread is responsible for displaying the splash screen
void *splashscreen(void* vp) {
	int maxx;
	int maxy;
	getmaxyx(win, maxy, maxx);
	printf("HERE 1: maxx: %d, maxy: %d", maxx, maxy);
	char* gameName = "Pong";
	char* author1 = "Noah Going";
	char* author2 = "Noel Mrowiec";
	char* year = "2015";

	int posx = maxx / 2;
	for (int i = 0; i < strlen(gameName); i++, posx++) {
		(void) move((maxy / 2) - 6, posx);
		(void) addch(gameName[i]);
	}
	posx = (maxx / 2) - 3;
	for (int i = 0; i < strlen(author1); i++, posx++) {
		(void) move((maxy / 2) - 3, posx);
		(void) addch(author1[i]);
	}
	posx = (maxx / 2) - 4;
	for (int i = 0; i < strlen(author2); i++, posx++) {
		(void) move(maxy / 2, posx);
		(void) addch(author2[i]);
	}
	posx = maxx / 2;
	for (int i = 0; i < strlen(year); i++, posx++) {
		(void) move((maxy / 2) + 3, posx);
		(void) addch(year[i]);
	}
	(void) refresh();

	(void) usleep(TWO_SEC_IN_MICROSEC);

	posx = maxx / 2;
	for (int i = 0; i < strlen(gameName); i++, posx++) {
		(void) move((maxy / 2) - 6, posx);
		(void) addch(' ');
	}
	posx = (maxx / 2) - 3;
	for (int i = 0; i < strlen(author1); i++, posx++) {
		(void) move((maxy / 2) - 3, posx);
		(void) addch(' ');
	}
	posx = (maxx / 2) - 4;
	for (int i = 0; i < strlen(author2); i++, posx++) {
		(void) move(maxy / 2, posx);
		(void) addch(' ');
	}
	posx = maxx / 2;
	for (int i = 0; i < strlen(year); i++, posx++) {
		(void) move((maxy / 2) + 3, posx);
		(void) addch(' ');
	}
	(void) refresh();

	return NULL;
}
