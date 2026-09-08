/*
 * Author: Ahmed Ellamie
 * Email:  ahmed.ellamiee@gmail.com
 *
 * STUDENT TASK — GPIO.c  (ATmega32)
 * Implement every prototype from GPIO_interface.h. Return E_NOK on bad arguments.
 */

#include <stddef.h>
#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "MATH.h"

/*
 * GPIO_SetPinDirection
 * 1. Reject Port > GPIO_PORTD or Pin > GPIO_PIN7.
 * 2. INPUT        : clear DDRx bit, clear PORTx bit (Hi-Z).
 * 3. OUTPUT       : set DDRx bit.
 * 4. INPUT_PULLUP : clear DDRx bit, set PORTx bit.
 */
STD_ReturnType GPIO_SetPinDirection(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Direction)
{
    if ((Copy_u8Port > GPIO_PORTD) || (Copy_u8Pin > GPIO_PIN7))
    {
        return E_NOK;
    }
    switch(Copy_u8Port){
        case GPIO_PORTA:
            if(Copy_u8Direction == GPIO_INPUT){
                CLEAR_BIT(GPIO_DDRA_REG, Copy_u8Pin);
                CLEAR_BIT(GPIO_PORTA_REG, Copy_u8Pin);
            }
            else if(Copy_u8Direction == GPIO_OUTPUT){
                SET_BIT(GPIO_DDRA_REG, Copy_u8Pin);
                CLEAR_BIT(GPIO_PORTA_REG, Copy_u8Pin);
            }
            break;
        case GPIO_PORTB:
            if(Copy_u8Direction == GPIO_INPUT){
                CLEAR_BIT(GPIO_DDRB_REG, Copy_u8Pin);
                CLEAR_BIT(GPIO_PORTB_REG, Copy_u8Pin);
            }
            else if(Copy_u8Direction == GPIO_OUTPUT){
                SET_BIT(GPIO_DDRB_REG, Copy_u8Pin);
                CLEAR_BIT(GPIO_PORTB_REG, Copy_u8Pin);
            }
            break;
        case GPIO_PORTC:
            if(Copy_u8Direction == GPIO_INPUT){
                CLEAR_BIT(GPIO_DDRC_REG, Copy_u8Pin);
                CLEAR_BIT(GPIO_PORTC_REG, Copy_u8Pin);
            }
            else if(Copy_u8Direction == GPIO_OUTPUT){
                SET_BIT(GPIO_DDRC_REG, Copy_u8Pin);
                CLEAR_BIT(GPIO_PORTC_REG, Copy_u8Pin);
            }
            break;
        case GPIO_PORTD:        
            if(Copy_u8Direction == GPIO_INPUT){
                CLEAR_BIT(GPIO_DDRD_REG, Copy_u8Pin);
                CLEAR_BIT(GPIO_PORTD_REG, Copy_u8Pin);
            }
            else if(Copy_u8Direction == GPIO_OUTPUT){
                SET_BIT(GPIO_DDRD_REG, Copy_u8Pin);
                CLEAR_BIT(GPIO_PORTD_REG, Copy_u8Pin);
            }                                               
            break;
        default:
            return E_NOK;       

          
            return E_OK;
    }
}

/*
 * GPIO_SetPinValue
 * 1. Validate port and pin.
 * 2. GPIO_HIGH -> set PORTx bit.  GPIO_LOW -> clear PORTx bit.
 */
STD_ReturnType GPIO_SetPinValue(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Value)
{
    if ((Copy_u8Port > GPIO_PORTD) || (Copy_u8Pin > GPIO_PIN7))
    {
        return E_NOK;
    }

    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        if (Copy_u8Value == GPIO_HIGH)
        {
            SET_BIT(GPIO_PORTA_REG, Copy_u8Pin);
        }
        else
        {
            CLEAR_BIT(GPIO_PORTA_REG, Copy_u8Pin);
        }
        return E_OK;

    case GPIO_PORTB:
        if (Copy_u8Value == GPIO_HIGH)
        {
            SET_BIT(GPIO_PORTB_REG, Copy_u8Pin);
        }
        else
        {
            CLEAR_BIT(GPIO_PORTB_REG, Copy_u8Pin);
        }
        return E_OK;

    case GPIO_PORTC:
        if (Copy_u8Value == GPIO_HIGH)
        {
            SET_BIT(GPIO_PORTC_REG, Copy_u8Pin);
        }
        else
        {
            CLEAR_BIT(GPIO_PORTC_REG, Copy_u8Pin);
        }
        return E_OK;

    case GPIO_PORTD:
        if (Copy_u8Value == GPIO_HIGH)
        {
            SET_BIT(GPIO_PORTD_REG, Copy_u8Pin);
        }
        else
        {
            CLEAR_BIT(GPIO_PORTD_REG, Copy_u8Pin);
        }
        return E_OK;

    default:
        return E_NOK;
    }
}

/*
 * GPIO_GetPinValue
 * 1. Validate port, pin, and that Copy_pu8Value is not NULL.
 * 2. Read PINx bit into *Copy_pu8Value as GPIO_HIGH or GPIO_LOW.
 */
STD_ReturnType GPIO_GetPinValue(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 *Copy_pu8Value)
{
    if ((Copy_u8Port > GPIO_PORTD) || (Copy_u8Pin > GPIO_PIN7) || (Copy_pu8Value == NULL))
    {
        return E_NOK;
    }

    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        *Copy_pu8Value = GET_BIT(GPIO_PINA_REG, Copy_u8Pin);
        return E_OK;

    case GPIO_PORTB:
        *Copy_pu8Value = GET_BIT(GPIO_PINB_REG, Copy_u8Pin);
        return E_OK;

    case GPIO_PORTC:
        *Copy_pu8Value = GET_BIT(GPIO_PINC_REG, Copy_u8Pin);
        return E_OK;

    case GPIO_PORTD:
        *Copy_pu8Value = GET_BIT(GPIO_PIND_REG, Copy_u8Pin);
        return E_OK;

    default:
        return E_NOK;
    }
}

/*
 * GPIO_TogglePinValue
 * 1. Validate port and pin.
 * 2. Flip the matching PORTx bit (PORTx ^= mask).
 */
STD_ReturnType GPIO_TogglePinValue(uint8 Copy_u8Port, uint8 Copy_u8Pin)
{
    if ((Copy_u8Port > GPIO_PORTD) || (Copy_u8Pin > GPIO_PIN7))
    {
        return E_NOK;
    }

    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        TOGGLE_BIT(GPIO_PORTA_REG, Copy_u8Pin);
        return E_OK;

    case GPIO_PORTB:
        TOGGLE_BIT(GPIO_PORTB_REG, Copy_u8Pin);
        return E_OK;

    case GPIO_PORTC:
        TOGGLE_BIT(GPIO_PORTC_REG, Copy_u8Pin);
        return E_OK;

    case GPIO_PORTD:
        TOGGLE_BIT(GPIO_PORTD_REG, Copy_u8Pin);
        return E_OK;

    default:
        return E_NOK;
    }
}

/*
 * GPIO_SetPortDirection
 * 1. Validate port. Direction is GPIO_INPUT or GPIO_OUTPUT.
 * 2. Write 0x00 or 0xFF to that port's DDRx.
 */
STD_ReturnType GPIO_SetPortDirection(uint8 Copy_u8Port, uint8 Copy_u8Direction)
{
    if (Copy_u8Port > GPIO_MAX_PORT)
    {
        return E_NOK;
    }

    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        GPIO_DDRA_REG = Copy_u8Direction;
        return E_OK;

    case GPIO_PORTB:
        GPIO_DDRB_REG = Copy_u8Direction;
        return E_OK;

    case GPIO_PORTC:
        GPIO_DDRC_REG = Copy_u8Direction;
        return E_OK;

    case GPIO_PORTD:
        GPIO_DDRD_REG = Copy_u8Direction;
        return E_OK;

    default:
        return E_NOK;
    }
}

/*
 * GPIO_SetPortValue
 * 1. Validate port.
 * 2. Write Copy_u8Value to PORTx.
 */
STD_ReturnType GPIO_SetPortValue(uint8 Copy_u8Port, uint8 Copy_u8Value)
{
    if (Copy_u8Port > GPIO_PORTD)
    {
        return E_NOK;
    }

    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        GPIO_PORTA_REG = Copy_u8Value;
        return E_OK;

    case GPIO_PORTB:
        GPIO_PORTB_REG = Copy_u8Value;
        return E_OK;

    case GPIO_PORTC:
        GPIO_PORTC_REG = Copy_u8Value;
        return E_OK;

    case GPIO_PORTD:
        GPIO_PORTD_REG = Copy_u8Value;
        return E_OK;

    default:
        return E_NOK;
    }
}

/*
 * GPIO_GetPortValue
 * 1. Validate port and that Copy_pu8Value is not NULL.
 * 2. Read PINx into *Copy_pu8Value.
 */
STD_ReturnType GPIO_GetPortValue(uint8 Copy_u8Port, uint8 *Copy_pu8Value)
{
    if ((Copy_u8Port > GPIO_PORTD) || (Copy_pu8Value == NULL))
    {
        return E_NOK;
    }

    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        *Copy_pu8Value = GPIO_PINA_REG;
        return E_OK;

    case GPIO_PORTB:
        *Copy_pu8Value = GPIO_PINB_REG;
        return E_OK;

    case GPIO_PORTC:
        *Copy_pu8Value = GPIO_PINC_REG;
        return E_OK;

    case GPIO_PORTD:
        *Copy_pu8Value = GPIO_PIND_REG;
        return E_OK;

    default:
        return E_NOK;
    }
}
