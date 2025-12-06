#ifndef SYSTICK_H
#define SYSTICK_H

#include "../UTILS/std_types.h"

/* Initialize the SysTick Timer (Disables it on startup) */
void SysTick_Init(void);

/* Disable SysTick (Stop counting) */
void SysTick_Disable(void);

/* Blocking Delay for N milliseconds */
/* Example: SysTick_WaitBlocking(1000) pauses for exactly 1 second */
void SysTick_Wait(u32 time_ms);

#endif