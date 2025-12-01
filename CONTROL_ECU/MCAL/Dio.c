#include "Dio.h"

#include <stdint.h>   // Defines uint32_t, uint8_t
#include <stdbool.h>  // Defines bool
// TIVAWARE INCLUDES (Hidden from everyone else)
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "std_types.h"
/* Add this to your Includes if not already there */
#include "driverlib/sysctl.h" 

void Dio_Init(u8 PortId, u8 PinId, u8 Direction)
{
    u32 Tiva_Port_Base;
    u32 Tiva_Peripheral_ID;
    u8  Tiva_Pin_Mask = (1 << PinId);

    /* 1. Map Generic PORT to TivaWare Peripheral ID & Base Address */
    switch(PortId)
    {
        case PORT_F: 
            Tiva_Peripheral_ID = SYSCTL_PERIPH_GPIOF; // Clock ID
            Tiva_Port_Base     = GPIO_PORTF_BASE;     // Address
            break;
        // Add other cases (PORT_A, PORT_B...) here
        default: return; 
    }

    /* 2. ENABLE CLOCK (The most important step!) */
    SysCtlPeripheralEnable(Tiva_Peripheral_ID);

    /* 3. Wait for the clock to stabilize */
    while(!SysCtlPeripheralReady(Tiva_Peripheral_ID));

    /* 4. Set Pin Direction */
    if(Direction == OUTPUT)
    {
        GPIOPinTypeGPIOOutput(Tiva_Port_Base, Tiva_Pin_Mask);
    }
    else
    {
        GPIOPinTypeGPIOInput(Tiva_Port_Base, Tiva_Pin_Mask);
        // Optional: Enable Pull-ups if needed for inputs
        // GPIOPadConfigSet(Tiva_Port_Base, Tiva_Pin_Mask, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
    }
}
void Dio_WriteChannel(u8 PortId, u8 PinId, u8 Level)
{
    u32 Tiva_Port_Base = 0; // Initialize to 0 for safety
    u8  Tiva_Pin_Mask = (1 << PinId);

    /* 1. Translate Generic PORT to Address */
    switch(PortId) {
        case PORT_F: Tiva_Port_Base = GPIO_PORTF_BASE; break;
        // Add other ports here later
        default: return; // SAFETY EXIT: If port is wrong, do nothing!
    }

    /* 2. CALL TIVAWARE */
    if(Level == HIGH) {
        GPIOPinWrite(Tiva_Port_Base, Tiva_Pin_Mask, Tiva_Pin_Mask);
    } else {
        GPIOPinWrite(Tiva_Port_Base, Tiva_Pin_Mask, 0);
    }
}