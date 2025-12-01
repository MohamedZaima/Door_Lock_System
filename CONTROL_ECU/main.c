#include "HAL/Led.h" 
void Delay_MS(unsigned long time)
{
    // The Tiva runs at 16 MHz by default.
    // This loop count is an approximation for milliseconds.
    volatile unsigned long i;
    while(time > 0)
    {
        // 3180 is roughly 1ms loop count for 16MHz clock
        for (i = 0; i < 3180; i++); 
        time--;
    }
}

int main(void)
{
    /* 1. Initialize Ports (Red and Blue) */
    Led_Init();

    /* 2. Infinite Loop */
    while(1)
    {
        /* --- BLINK BLUE --- */
        Led_TurnOn();
        Delay_MS(500);  // Wait 500ms
        
        Led_TurnOff();
        Delay_MS(500);  // Wait 500ms
    }
    return 0;
}