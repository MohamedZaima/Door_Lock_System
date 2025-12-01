#include "Led.h"
#include "../CONFIG/Led_Cfg.h" // To know where the LED is connected
#include "../MCAL/Dio.h"       // To be able to write to pins

void Led_TurnOn(void)
{
    // "I want to write HIGH to the RED LED Port and Pin"
    // Notice: calls the Generic MCAL function
    Dio_WriteChannel(LED_GREEN_PORT, LED_GREEN_PIN, HIGH);
}

void Led_Init(void)
{
    /* Initialize the Red LED Pin as an OUTPUT */
    /* Note: You need to define OUTPUT as 1 in std_types or Dio.h */
    Dio_Init(LED_GREEN_PORT, LED_GREEN_PIN, OUTPUT);
}
void Led_TurnOff(void)
{
    // Write LOW (0) to turn off Red
    Dio_WriteChannel(LED_GREEN_PORT, LED_GREEN_PIN, LOW);
}