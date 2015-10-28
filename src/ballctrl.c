/************************************************************************************
 * This file was developed as part of CS3841 Design of Operating Systems at the
 * Milwaukee School of Engineering.  This file is copyright 2008-2015 by MSOE.
 *
 * $Author: wws $
 * $Revision: 1.1 $
 * $Name:  $
 * This file manages the motion of the ball.  This includes collisions, edge
 * detections, paddle detection, etc.
 *
 ************************************************************************************/
#define BALLCTRL_C

/************************************************************************************
 * External Includes
 ************************************************************************************/
#include <unistd.h>
#include <math.h>
#include <string.h>
#include "ballctrl.h"
#include "pong.h"

/************************************************************************************
 * Private structure / type definitions
 ************************************************************************************/

/************************************************************************************
 * Private function / method prototypes
 ************************************************************************************/
static void collision();
static void checkForScore(int maxx, int maxy);

/************************************************************************************
 * Constant declarations / table declarations
 ***********************************************************************************/
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
static float ballAngle;
static bool flashBall = false;
static int score;
#define MAX_SCORE_CHARS (32)
/************************************************************************************
 * Method header:
 * Function name: moveball
 * Function purpose: This function is responsible for moving the ball within the game of pong.
 *                   It is spawned as a thread and will exit if and when quit is no longer true.
 *                   Ball will flash (display '*') on collision.
 * Function parameters: 
 *                   void *vp - This is a pointer to the parameters passed into the 
 *                              thread.  At the present time, this parameter is not used.
 * Function return value: void* This is the return value when the thread exits.  
 *                              Currently, it is always NULL, as no data is directly 
 *                              returned by the thread.
 ************************************************************************************/
// This thread is responsible for moving the ball
void *moveball(void* vp) {
	// get the extents of the screen
	int maxx;

	int maxy;
	// how does this work??
	getmaxyx(win, maxy, maxx);

	// these should be floating point to get slopes other than
	// +/- 45 degrees
	float yadder = 1.0f;
	float xadder = 1.0f;
	float xactual = maxx / 2.0f;
	float yactual = maxy / 2.0f;
	ballAngle = 315;

	while (!quit) {
		if (!pauseGame) {
			(void) move(bally, ballx);
			if (inch() == 'O' || inch() == '*') {
				pthread_mutex_lock(&mutex);
				(void) addch(' ');
				pthread_mutex_unlock(&mutex);
			}

			// Figure out the movement
			float angleInRadians = M_PI * ballAngle / 180.0;
			float xmovement = cos(angleInRadians);
			float ymovement = sin(angleInRadians);

			yactual += ymovement;
			xactual += xmovement;

			// truncate
			bally = (int) (yactual);
			ballx = (int) (xactual);
			if (bally >= maxy - 1) {
				ballAngle = 360 - ballAngle;
				collision();
			}
			else if (bally < 1) {
				ballAngle = 360 - ballAngle;
				collision();
			}
			else if (ballx >= maxx - 1) {
				ballAngle = 180 - ballAngle;
				collision();
			}
			else if (ballx < 1) {
				ballAngle = 180 - ballAngle;
				collision();
			}
			else{
				flashBall = false;
			}

			ballAngle = fmod(ballAngle + 360, 360.0f);

			checkForScore(maxx, maxy);

			if(!flashBall){
				if (inch() == ' ') {
					pthread_mutex_lock(&mutex);
					(void) move(bally, ballx);
					(void) addch('O');		//regular ball, no collision
					pthread_mutex_unlock(&mutex);
				}
			}
			else if(flashBall){
				if(inch() != '|'){
					pthread_mutex_lock(&mutex);
					(void) move(bally, ballx);
					(void) addch('*');		//flash ball on collision
					pthread_mutex_unlock(&mutex);
				}
			}
			(void) touchwin(win);
			(void) refresh();


			//pass ballMovementDelay to local variable so we can mutex lock/
			//unlock access of ballMovementDelay and not wait for delay to finish.

			pthread_mutex_lock(&mutex);
			int delayLocalCopy = ballMovementDelay;
			pthread_mutex_unlock(&mutex);

			(void) usleep(delayLocalCopy);
		}
	}
	return NULL;
}

/************************************************************************************
 * Method header:
 * Function name: collision
 * Function purpose: This method will be invoked when a ball collision is detected. 
 * Function parameters: 
 *                   None
 * Function return value: None
 ************************************************************************************/
// collision sound effects
static void collision() {
	flashBall = true;
	return;
}

/************************************************************************************
 * Method header:
 * Function name: checkForScore
 * Function purpose: This method will check to see if the ball has hit the left
 * 					 side of the screen. If so, increment the score. Note:
 * 					 score is the number of times the player has missed the ball.
 * Function parameters:
 *                   None
 * Function return value: None
 ************************************************************************************/
//checks score
void checkForScore(int maxx, int maxy){
	pthread_mutex_lock(&mutex);
	(void) move(bally, ballx);
	pthread_mutex_unlock(&mutex);
	//check if ball has hit the left side of the screen and no paddle
	if(ballx == 0 && inch() == ' '){
		//hit the left side of screen with no paddle,
		//so increment score and print top center.
		score++;

		char scoreString[MAX_SCORE_CHARS] = "Score: ";
		char scoreCharNum[MAX_SCORE_CHARS];
		(void) snprintf(scoreCharNum, MAX_SCORE_CHARS, "%d", score);
		strcat(scoreString, scoreCharNum);

		int posx = maxx / 2;

		for(int i = 0; i < strlen(scoreString); i++, posx++) {
			pthread_mutex_lock(&mutex);
			(void) move(0, posx);
			(void) addch(scoreString[i]);
			pthread_mutex_unlock(&mutex);
		}

		(void) refresh();
	}
}
