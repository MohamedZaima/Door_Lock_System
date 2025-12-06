#include "SysTick.h"
#include <stdint.h>
#include <stdbool.h>
#include "driverlib/systick.h"
#include "driverlib/sysctl.h"
#include "inc/hw_nvic.h"
#include "inc/hw_types.h"

void SysTick_Init(void)
{
    /* 1. Disable SysTick during setup */
    SysTickDisable();
    
    /* 2. Configure Clock Source */
    /* Use the System Clock (e.g., 16MHz or 80MHz) */
    SysTickPeriodSet(0x00FFFFFF); // Max Value
    
    // We don't enable it yet. We only enable it when we need a delay.
}

void SysTick_Disable(void)
{
    SysTickDisable();
}

void SysTick_Wait(u32 time_ms)
{
    u32 i;
    u32 ClockFreq;
    u32 CyclesPerMS;

    /* 1. Get the current system clock frequency */
    /* This ensures accuracy even if you change PLL settings later */
    ClockFreq = SysCtlClockGet(); 
    
    /* 2. Calculate how many ticks constitute 1 millisecond */
    CyclesPerMS = ClockFreq / 1000;

    /* 3. Configure SysTick for 1ms Period */
    SysTickDisable();
    SysTickPeriodSet(CyclesPerMS - 1); // N-1 formula
    /* 4. Clear the Current Value Register */
    /* Writing ANY value to this register clears it to 0 */
    HWREG(NVIC_ST_CURRENT) = 0;

    /* 4. Enable SysTick (System Clock Source) */
    SysTickEnable();

    /* 5. Loop N times (for N milliseconds) */
    for(i = 0; i < time_ms; i++)
    {
        /* Wait for the COUNT flag (Bit 16) to be set */
        /* This bit reads as 1 when the timer counts down to 0 */
        while((HWREG(NVIC_ST_CTRL) & 0x00010000) == 0)
        {
            // Do nothing, just wait
        }
    }

    /* 6. Disable SysTick to save power/resources */
    SysTickDisable();
}