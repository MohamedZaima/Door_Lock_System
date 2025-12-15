/******************************************************************************
 * File: GPTM.c
 * Module: General Purpose Timer Module (MCAL)
 * Description: Implementation for Timer0 One-Shot Logic
 ******************************************************************************/
#include "../UTILS/std_types.h"
#include <stdio.h>  // For printf
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"
#include "GPTM.h"




/* TivaWare Includes */


/* Global Callback Pointer */
static void (*g_Timer0ACallback)(void) = 0;

/* ================================================================= */
/* INITIALIZATION                                                    */
/* ================================================================= */
void GPTM_Init(void)
{
    /* 1. Enable the Timer0 Peripheral Clock */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);

    /* 2. Wait for it to be ready */
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER0));

    /* 3. Configure Timer0 as two 16-bit timers concatenated to 32-bit */
    TimerConfigure(TIMER0_BASE, TIMER_CFG_ONE_SHOT);

    /* 4. Enable Timeout Interrupt source inside the Timer */
    TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);

    /* 5. Enable the Timer0A Interrupt in the NVIC (Microcontroller Core) */
    IntEnable(INT_TIMER0A);
}

/* ================================================================= */
/* START TIMER                                                       */
/* ================================================================= */
void GPTM_StartOneShot(u32 seconds)
{
    /* 1. Get System Clock Frequency (e.g., 16,000,000 or 80,000,000) */
    u32 clockFreq = SysCtlClockGet();

    /* 2. Calculate Load Value: (Seconds * Clock_Hz) - 1 */
    /* Example: 5s * 16MHz = 80,000,000 ticks */
    u32 loadValue = (seconds * clockFreq);

    /* 3. Load the value into Timer0A */
    TimerLoadSet(TIMER0_BASE, TIMER_A, loadValue);

    /* 4. Start the Timer */
    TimerEnable(TIMER0_BASE, TIMER_A);
}

/* ================================================================= */
/* STOP TIMER                                                        */
/* ================================================================= */
void GPTM_Stop(void)
{
    TimerDisable(TIMER0_BASE, TIMER_A);
}

/* ================================================================= */
/* CALLBACK REGISTRATION                                             */
/* ================================================================= */
void GPTM_SetCallback(void (*ptr)(void))
{
    g_Timer0ACallback = ptr;
}

/* ================================================================= */
/* INTERRUPT SERVICE ROUTINE (ISR)                                   */
/* This function MUST be linked in startup_ewarm.c                   */
/* ================================================================= */
void Timer0A_Handler(void)
{
    /* 1. Clear the Interrupt Flag (Crucial! Otherwise, it loops forever) */
    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);

    /* 2. Execute the registered Application function (e.g., CloseDoor) */
    if(g_Timer0ACallback != 0)
    {
        g_Timer0ACallback();
    }
}