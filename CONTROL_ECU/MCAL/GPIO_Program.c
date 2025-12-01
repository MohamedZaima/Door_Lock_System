/* ==========================================
   File: MCAL/GPIO_program.c
   ========================================== */

#include "STD_TYPES.h"
#include "GPIO_interface.h" // Your generic definitions

// TivaWare dependencies (HIDDEN from the rest of the system)
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/hw_memmap.h"  // <-- This file contains the "Addresses"

void GPIO_SetPinDirection(u8 PortID, u8 PinID, u8 Direction)
{
    uint32_t Tiva_Port_Address;
    uint8_t  Tiva_Pin_Bit;

    /* STEP 1: Translate Your "PortID" to TivaWare "Address" */
    switch(PortID)
    {
        case PORT_A: Tiva_Port_Address = GPIO_PORTA_BASE; break;
        case PORT_B: Tiva_Port_Address = GPIO_PORTB_BASE; break;
        case PORT_F: Tiva_Port_Address = GPIO_PORTF_BASE; break;
        // ... handle other ports
        default: return; // Error handling
    }

    /* STEP 2: Translate Your "PinID" to TivaWare "Bit" */
    // TivaWare uses bitmasks (0x01, 0x02) not numbers (0, 1). 
    // Usually 1 << PinID works if your PinID is 0-7.
    Tiva_Pin_Bit = (1 << PinID); 

    /* STEP 3: Call the TivaWare Function */
    if(Direction == OUTPUT)
    {
        // Using the address (Tiva_Port_Address) we found above
        GPIOPinTypeGPIOOutput(Tiva_Port_Address, Tiva_Pin_Bit);
    }
    else
    {
        GPIOPinTypeGPIOInput(Tiva_Port_Address, Tiva_Pin_Bit);
    }
}