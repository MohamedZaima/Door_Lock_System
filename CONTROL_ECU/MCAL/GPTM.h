#ifndef GPTM_H
#define GPTM_H

#include "../UTILS/std_types.h"

/* ================================================================= */
/* FUNCTION PROTOTYPES                                               */
/* ================================================================= */

/*
 * Function: GPTM_Init
 * Description: Initializes Timer0 as a 32-bit One-Shot timer.
 * Enables interrupts but does NOT start counting yet.
 */
void GPTM_Init(void);

/*
 * Function: GPTM_StartOneShot
 * Description: Loads the timer with a value corresponding to 'seconds'
 * and starts counting.
 * Parameters:  seconds - The duration to wait (e.g., 5 to 30).
 */
void GPTM_StartOneShot(u32 seconds);

/*
 * Function: GPTM_Stop
 * Description: Manually stops the timer (useful if user cancels/locks manually).
 */
void GPTM_Stop(void);

/*
 * Function: GPTM_SetCallback
 * Description: Register the function to call when time is up (e.g., Door_Lock).
 * Parameters:  ptr - Pointer to a void function(void).
 */
void GPTM_SetCallback(void (*ptr)(void));

#endif /* GPTM_H */