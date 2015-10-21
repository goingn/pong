/************************************************************************************
 * This file was developed as part of CS3841 Design of Operating Systems at the
 * Milwaukee School of Engineering.  This file is copyright 2008-2015 by MSOE.
 *
 * $Author: wws $
 * $Revision: 1.1 $
 * $Name:  $
 * This file servers as the interface header definition for the ball controller logic of the
 * pong game.
 *
 ************************************************************************************/
#ifndef PONG_H
#define PONG_H

#ifdef PONG_C
#define EXTERN_PFX 
#else
#define EXTERN_PFX extern
#endif

/************************************************************************************
 * External Includes
 ************************************************************************************/
#include <curses.h>
#include <stdbool.h>

/************************************************************************************
 * Public structure / type definitions
 ************************************************************************************/
// None as of right now.
/************************************************************************************
 * Public / global variable definitions
 ************************************************************************************/
// Global data - for inter-thread communication
EXTERN_PFX WINDOW *win;	// the curses window
EXTERN_PFX bool quit;  // a flag to stop all threads
EXTERN_PFX bool pauseGame; // a flag to pause all threads

/************************************************************************************
 * Public function / method prototypes
 ************************************************************************************/
EXTERN_PFX int main(int argc, char* argv[]);
#undef EXTERN_PFX
#endif
