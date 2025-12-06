#include "Led.h"
#include "../CONFIG/Led_Cfg.h" // To know where the LED is connected
#include "../MCAL/Dio.h"       // To be able to write to pins

void Led_RedTurnOn(void)
{
    Dio_WriteChannel(LED_RED_PORT, LED_RED_PIN, HIGH);
}

void Led_RedInit(void)
{
    Dio_Init(LED_RED_PORT, LED_RED_PIN, OUTPUT);
}
void Led_RedTurnOff(void)
{
    Dio_WriteChannel(LED_RED_PORT, LED_RED_PIN, LOW);
}


void Led_BlueTurnOn(void)
{
    
    Dio_WriteChannel(LED_BLUE_PORT, LED_BLUE_PIN, HIGH);
}

void Led_BlueInit(void)
{
   
    Dio_Init(LED_BLUE_PORT, LED_BLUE_PIN, OUTPUT);
}
void Led_BlueTurnOff(void)
{
   
    Dio_WriteChannel(LED_BLUE_PORT, LED_BLUE_PIN, LOW);
}


void Led_GreenTurnOn(void)
{
    
    Dio_WriteChannel(LED_GREEN_PORT, LED_GREEN_PIN, HIGH);
}

void Led_GreenInit(void)
{
   
    Dio_Init(LED_GREEN_PORT, LED_GREEN_PIN, OUTPUT);
}
void Led_GreenTurnOff(void)
{
    
    Dio_WriteChannel(LED_GREEN_PORT, LED_GREEN_PIN, LOW);
}