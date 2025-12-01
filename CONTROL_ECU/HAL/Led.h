#ifndef LED_H
#define LED_H

void Led_Init(void);
// This line tells main.c: "Trust me, there is a function called Led_TurnOn"
void Led_TurnOn(void); 
void Led_TurnOff(void);
#endif