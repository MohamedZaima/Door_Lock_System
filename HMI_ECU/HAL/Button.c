#include "Button.h"
#include "../CONFIG/Led_Cfg.h" // To use PORT_F/PIN_0 defs if you want, or use local defines
#include "../MCAL/Dio.h"

void Button_Init(void)
{
    // Initialize PF0 as Input. 
    // Your Dio_Init MUST handle the "Unlock" and "Pull-Up" for this to work!
    Dio_Init(BUTTON_PORT, BUTTON_PIN, INPUT);
}

u8 Button_Read(void)
{
    // Read the physical pin
    u8 Val = Dio_ReadChannel(BUTTON_PORT, BUTTON_PIN);
    
    // Logic: The switch is Active LOW (0 when pressed).
    // Let's invert it so the App sees "1" when pressed (easier to think about).
    if (Val == LOW) 
    {
        return TRUE;  // Pressed
    }
    else 
    {
        return FALSE; // Released
    }
}