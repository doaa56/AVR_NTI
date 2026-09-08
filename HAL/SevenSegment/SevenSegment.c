#include "SevenSegment_interface.h"
STD_ReturnType SevenSegment_Init(uint8 port)
{
    if (port > GPIO_PORTD) // Assuming ports are numbered 0 to 3
    {
        return E_NOK; // Invalid port number
    }
    // Set the direction of the specified port to output (0xFF)
    return GPIO_SetPortDirection(port, 0xFF);

}

STD_ReturnType SevenSegment_Display(uint8 port, uint8 digit)
{
    if(port > GPIO_PORTD || digit > 9) // Assuming ports are numbered 0 to 3 and digits 0-9
    {
        return E_NOK; // Invalid port number or digit
    }
    // Implementation for displaying digit on the specified port
    const uint8 segmentMap[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
    return GPIO_SetPortValue(port, segmentMap[digit]);
}
