/******************************************************************************
 * File: potentiometer.c
 * Module: Potentiometer HAL (Hardware Abstraction Layer)
 * Description: Source file for Potentiometer HAL on TM4C123GH6PM
 * Author: Ahmedhh
 * Date: December 8, 2025
 ******************************************************************************/
#include "../UTILS/std_types.h"
#include <stdio.h>  // For printf
#include <stdint.h>   // Defines uint32_t, uint8_t
#include <stdbool.h>  // Defines bool
#include "potentiometer.h"
#include "adc.h"

/******************************************************************************
 *                         Function Definitions                                *
 ******************************************************************************/

/*
 * Description: Initializes the potentiometer (ADC on PE3)
 * Parameters: None
 * Returns: None
 */
void POT_Init(void)
{
    /* Initialize ADC with channel 0 (PE3 = AIN0) */
    ADC_Init(POT_ADC_CHANNEL);
}


uint32_t POT_ReadMapped(uint32_t min, uint32_t max)
{
    uint16_t rawValue = ADC_Read();
    
    /* Map from 0-4095 to min-max range */
    /* Formula: min + (rawValue * (max - min)) / 4095 */
    return min + ((rawValue * (max - min)) / 4095UL);
}
