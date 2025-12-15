/******************************************************************************
 * File: uart.c
 * Module: UART (Universal Asynchronous Receiver/Transmitter)
 * Description: Source file for TM4C123GH6PM UART0 Driver (TivaWare)
 * Author: Ahmedhh
 * Date: December 10, 2025
 * 
 * Configuration:
 *   - UART0 (PA0: RX, PA1: TX)
 *   - Baud Rate: 115200
 *   - Data: 8 bits
 *   - Parity: None
 *   - Stop: 1 bit
 *   - System Clock: 16 MHz
 * 
 * Note: This implementation uses TivaWare peripheral driver library.
 *       TivaWare functions simplify UART configuration and provide
 *       higher-level abstractions compared to direct register access.
 ******************************************************************************/

#include "uart.h"
#include <stdint.h>
#include <stdbool.h>

/* TivaWare includes */
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"

/******************************************************************************
 *                              Definitions                                    *
 ******************************************************************************/

#define SYSTEM_CLOCK    16000000    /* 16 MHz system clock */
#define BAUD_RATE       115200      /* Target baud rate */

/******************************************************************************
 *                          Function Implementations                           *
 ******************************************************************************/

/*
 * UART0_Init
 * Initializes UART0 with 115200 baud rate, 8N1 configuration using TivaWare.
 * 
 * TivaWare functions used:
 *   - SysCtlPeripheralEnable(): Enable peripheral clocks
 *   - GPIOPinConfigure(): Configure pin muxing
 *   - GPIOPinTypeUART(): Configure pins for UART alternate function
 *   - UARTConfigSetExpClk(): Configure UART parameters
 *   - UARTEnable(): Enable UART module
 */
void UART0_Init(void)
{
    /* 1. Enable peripheral clocks for UART0 and GPIOA */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    
    /* Wait for peripherals to be ready */
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART0));
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA));
    
    /* 2. Configure GPIO pins for UART functionality */
    /* PA0: U0RX (UART0 Receive) */
    /* PA1: U0TX (UART0 Transmit) */
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    
    /* Set pin type to UART */
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    
    /* 3. Configure UART parameters */
    /* System clock, baud rate, 8 data bits, 1 stop bit, no parity */
    UARTConfigSetExpClk(UART0_BASE, SYSTEM_CLOCK, BAUD_RATE,
                        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | 
                         UART_CONFIG_PAR_NONE));
    
    /* 4. Enable UART0 */
    UARTEnable(UART0_BASE);
}

/*
 * UART0_SendChar
 * Transmits a single character through UART0 using TivaWare.
 * Uses UARTCharPut() which blocks until FIFO has space.
 */
void UART0_SendChar(char data)
{
    /* UARTCharPut() blocks until space is available in TX FIFO */
    UARTCharPut(UART0_BASE, data);
}

/*
 * UART0_ReceiveChar
 * Receives a single character from UART0 using TivaWare.
 * Uses UARTCharGet() which blocks until data is available.
 */
char UART0_ReceiveChar(void)
{
    /* UARTCharGet() blocks until data is available in RX FIFO */
    return (char)UARTCharGet(UART0_BASE);
}

/*
 * UART0_SendString
 * Transmits a null-terminated string through UART0.
 */
void UART0_SendString(const char *str)
{
    while (*str != '\0')
    {
        UART0_SendChar(*str);
        str++;
    }
}

/*
 * UART0_IsDataAvailable
 * Checks if data is available in the receive FIFO using TivaWare.
 * Uses UARTCharsAvail() to check RX FIFO status.
 */
uint8_t UART0_IsDataAvailable(void)
{
    /* UARTCharsAvail() returns true if characters are available */
    return (UARTCharsAvail(UART0_BASE)) ? 1 : 0;
}