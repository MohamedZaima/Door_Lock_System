/*****************************************************************************
 * File: main.c
 * Description: Keypad (PA/PC) + LCD (I2C PB2/PB3)
 *****************************************************************************/

#include "std_types.h"
#include <stdint.h>   
#include <stdio.h>    
#include "../HAL/LCD.h"      // Expects I2C implementation
#include "SYSTICK.h"
#include "keypad.h"

int main()
{
    /* 1. Initialization */
    SysTick_Init();      
    
    /* Initialize I2C LCD (Uses PB2/PB3) */
    Lcd_Init();          
    
    /* Initialize Keypad (Uses PA2-PA5 and PC4-PC7) */
    Keypad_Init();       
    
    /* 2. Startup Screen */
    Lcd_Clear();
    Lcd_DisplayString("System Ready");
    SysTick_Wait(1000);
    Lcd_Clear();
    
    while (1)
    {
        /* 3. Read Keypad */
        const char *key = Keypad_GetKey(); 
        
        if (key != 0) 
        {
            // printf("Key: %s\n", key); // Debug to PC

            /* Output to I2C LCD */
            Lcd_Clear();                
            Lcd_DisplayString("Key Pressed:"); 
            Lcd_GoToRowColumn(1, 0); // Move to 2nd line
            Lcd_DisplayString((char*)key); 
            
            SysTick_Wait(250); // Debounce
        }
    }
}