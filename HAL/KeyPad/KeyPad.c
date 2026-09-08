#include "KeyPad_interface.h"
#include "string.h"

STD_ReturnType KeyPad_Init(uint8 port)
{
    if (port > GPIO_PORTD) // Assuming ports are numbered 0 to 3
    {
        return E_NOK; // Invalid port number
    }

    // Implementation for initializing the KeyPad on the specified port
    GPIO_SetPortDirection(port, 0xF0); 
    return E_OK;
}

STD_ReturnType KeyPad_GetPressedKey(uint8 port, uint8 *pressedKey)
{
    if (port > GPIO_PORTD || pressedKey == NULL) // Assuming ports are numbered 0 to 3
    {
        return E_NOK; // Invalid port number or null pointer
    }
    uint8 keyMap[4][4] = {
        {7, 8, 9, '/'},
        {4, 5, 6, '*'},
        {1, 2, 3, '-'},
        {'C', 0, '=', '+'}
    };
    // Implementation for getting the pressed key on the specified port
    GPIO_SetPortDirection(port, 0xF0); 
    uint8 colValues;

    for(uint8 row=0;row<4;row++){
        GPIO_SetPortValue(port, ~(1<<(row+4))); 
        for(uint8 col=0;col<4;col++){
            GPIO_GetPortValue(port, &colValues);
            if(!(colValues & (1<<col))){
                *pressedKey = keyMap[row][col]; 
                return E_OK;
            }
        }

    }

    *pressedKey = 0xFF; // No key pressed
    return E_OK;
}



