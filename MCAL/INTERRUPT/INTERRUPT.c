/*
 * Author: Ahmed Ellamie
 * Email:  ahmed.ellamiee@gmail.com
 *
 * STUDENT TASK — INTERRUPT.c  (ATmega32 EXTI + global I-bit)
 * Implement every prototype from INTERRUPT_interface.h.
 */

#include "STD_TYPES.h"
#include "INTERRUPT_interface.h"
#include "INTERRUPT_private.h"
#include "string.h"
#include <avr/interrupt.h>

/*
 * INTERRUPT_EnableGlobal
 * 1. Set SREG I-bit (sei). Return E_OK.
 *
 * INTERRUPT_DisableGlobal
 * 1. Clear SREG I-bit (cli). Return E_OK.
 */
static EXTI_CallbackType callback[3] = {NULL, NULL, NULL}; // Array of callback function pointers for INT0, INT1, INT2
/*
 * EXTI_SetSense
 * 1. Reject an unknown source.
 * 2. INT0 : write ISC01:ISC00 from Copy_u8Sense (0..3).
 * 3. INT1 : write ISC11:ISC10 the same way.
 * 4. INT2 : only EXTI_FALLING_EDGE (ISC2=0) or EXTI_RISING_EDGE (ISC2=1).
 *    Return E_NOK for low-level / any-change on INT2.
 */

/*
 * EXTI_ClearFlag
 * 1. Write 1 to INTF0 / INTF1 / INTF2 in GIFR (w1c).
 */

/*
 * EXTI_Enable
 * 1. Validate the source.
 * 2. Clear the stale flag first, then set INT0/INT1/INT2 in GICR.
 * 3. Order that always works: sense -> clear flag -> enable source -> sei().
 *
 * EXTI_Disable
 * 1. Clear the matching GICR bit.
 */

/*
 * Application reminder (do not write this ISR here unless the lab asks):
 *   #include <avr/interrupt.h>
 *   ISR(INT0_vect) { set a volatile flag; do not call _delay_ms(); }
 */
STD_ReturnType INTERRUPT_EnableGlobal(void){
    //sei();
    SREG |= (1 << 7); // Set the I-bit in SREG to enable global interrupts
    return E_OK;
}
STD_ReturnType INTERRUPT_DisableGlobal(void){
    //cli();
    SREG &= ~(1 << 7); // Clear the I-bit in SREG to disable global interrupts
    return E_OK;
}
STD_ReturnType EXTI_SetSense(uint8 Copy_u8Int, uint8 Copy_u8Sense){
    if(Copy_u8Int > EXTI_INT2) return E_NOK; // Reject unknown source
    switch(Copy_u8Int){
        case EXTI_INT0:
            MCUCR = (MCUCR & ~((1 << ISC01) | (1 << ISC00))) | ((Copy_u8Sense & 0x03) << ISC00);
            break;
        case EXTI_INT1:
            MCUCR = (MCUCR & ~((1 << ISC11) | (1 << ISC10))) | ((Copy_u8Sense & 0x03) << ISC10);
            break;
        case EXTI_INT2:
            if(Copy_u8Sense == EXTI_FALLING_EDGE){
                MCUCSR &= ~(1 << ISC2); // Falling edge
            } else if(Copy_u8Sense == EXTI_RISING_EDGE){
                MCUCSR |= (1 << ISC2); // Rising edge
            } else {
                return E_NOK; // Invalid sense for INT2
            }
            break;
    }
    return E_OK;
}
/*
 * Description : Clear the matching flag in GIFR (write 1), then set the enable
 *               bit in GICR (INT0 / INT1 / INT2). Call INTERRUPT_EnableGlobal after this.
 */
STD_ReturnType EXTI_Enable(uint8 Copy_u8Int){
    if(Copy_u8Int > EXTI_INT2) return E_NOK; // Reject unknown source
    // Clear the stale flag first
    switch(Copy_u8Int){
        case EXTI_INT0:
            GIFR |= (1 << INT0); // Clear INTF0
            GICR |= (1 << INT0); // Enable INT0
            break;
        case EXTI_INT1:
            GIFR |= (1 << INT1); // Clear INTF1
            GICR |= (1 << INT1); // Enable INT1
            break;
        case EXTI_INT2:
            GIFR |= (1 << INT2); // Clear INTF2
            GICR |= (1 << INT2); // Enable INT2
            break;
    }
    INTERRUPT_EnableGlobal(); // Enable global interrupts
    return E_OK;
}
/*
 * Description : Clear the GICR enable bit for INT0, INT1, or INT2.
 */
STD_ReturnType EXTI_Disable(uint8 Copy_u8Int){
    if(Copy_u8Int > EXTI_INT2) return E_NOK; // Reject unknown source
    switch(Copy_u8Int){
        case EXTI_INT0:
            GICR &= ~(1 << INT0); // Disable INT0
            break;
        case EXTI_INT1:
            GICR &= ~(1 << INT1); // Disable INT1
            break;
        case EXTI_INT2:
            GICR &= ~(1 << INT2); // Disable INT2
            break;
    }
    return E_OK;
}
/*
 * Description : Clear a stale INTF0 / INTF1 / INTF2 flag (write 1 to GIFR).
 */
STD_ReturnType EXTI_ClearFlag(uint8 Copy_u8Int){
    if(Copy_u8Int > EXTI_INT2) return E_NOK; // Reject unknown source
    switch(Copy_u8Int){
        case EXTI_INT0:
            GIFR |= (1 << INT0); // Clear INTF0
            break;
        case EXTI_INT1:
            GIFR |= (1 << INT1); // Clear INTF1
            break;
        case EXTI_INT2:
            GIFR |= (1 << INT2); // Clear INTF2
            break;
    }
    return E_OK;
}
/*
 * Description : Register the function the ISR calls when the source fires.
 *               Register it before EXTI_Init, so no edge can arrive with no
 *               handler in place. Registering again replaces the old one.
 * Parameters  : Copy_u8Int      — EXTI_INT0 / EXTI_INT1 / EXTI_INT2.
 *               Copy_pfCallback — void function taking void, must not be NULL.
 * Return      : E_NOK for an unknown source or a NULL function pointer.
 */
STD_ReturnType EXTI_SetCallback(
    uint8 Copy_u8Int,
    EXTI_CallbackType Copy_pfCallback
)
{
    if (Copy_u8Int > EXTI_INT2 || Copy_pfCallback == NULL)
    {
        return E_NOK;
    }

    callback[Copy_u8Int] = Copy_pfCallback;

    return E_OK;
}

ISR(INT0_vect)
{
    if (callback[EXTI_INT0] != NULL)
    {
        callback[EXTI_INT0]();
    }
}

ISR(INT1_vect)
{
    if (callback[EXTI_INT1] != NULL)
    {
        callback[EXTI_INT1]();
    }
}

ISR(INT2_vect)
{
    if (callback[EXTI_INT2] != NULL)
    {
        callback[EXTI_INT2]();
    }
}