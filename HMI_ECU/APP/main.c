
/*****************************************************************************
 * File: main.c
 * Description: Example main for testing the 4x4 keypad driver
 * Author: Ahmedhh
 * Date: November 27, 2025
 *****************************************************************************/



#include "std_types.h"
#include <stdint.h>   // Defines uint32_t, uint8_t
#include <stdbool.h>  // Defines bool
#include <stdio.h>    // <--- REQUIRED for getchar()
#include "LCD.h"
#include "Led.h"
#include "Button.h"
#include "SYSTICK.h"
#include "keypad.h"


/*
 * Main function
 * Continuously reads keypad and outputs pressed key to console.
 * Replace printf with LCD/UART output as needed for your hardware.
 */
int main()
{
    SysTick_Init();
    //Lcd_Init();
    Keypad_Init(); // Initialize keypad pins
    
/* 3. Startup Screen */
   // Lcd_Clear();
   // Lcd_DisplayString("Keypad Test...");
   // SysTick_Wait(1000); // Wait 1s to read it
   // Lcd_Clear();
    while (1)
    {
        const char *key =  Keypad_GetKey(); // Get pressed key (string)
        if (key)
        {
          /* Debug Output to Terminal (View -> Terminal I/O) */
            printf("Key Pressed: %s\n", key);

            /* Output to LCD */
          //  Lcd_Clear();
           // Lcd_DisplayString((char*)key);
        }
    }
}
