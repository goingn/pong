/************************************************************************************
 * This file was developed as part of CS3841 Design of Operating Systems at the
 * Milwaukee School of Engineering.  This file is copyright 2008-2015 by MSOE.
 *
 * $Author: wws $
 * $Revision: 1.1 $
 * $Name:  $
 * This file servers as the interface header definition for the computer player
 *
 ************************************************************************************/
#ifndef OPPONENT_H
#define OPPONENT_H

#ifdef OPPONENT_C
#define EXTERN_PFX
#else
#define EXTERN_PFX extern
#endif

/************************************************************************************
 * External Includes
 ************************************************************************************/
// None as of right now.
/************************************************************************************
 * Public structure / type definitions
 ************************************************************************************/
// None as of right now.
/************************************************************************************
 * Public function / method prototypes
 ************************************************************************************/
// This thread is responsible for moving the computer's paddle
EXTERN_PFX void *moveopponent(void* vp);

#undef EXTERN_PFX
#endif
