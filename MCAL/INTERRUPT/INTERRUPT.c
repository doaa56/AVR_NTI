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

/*
 * INTERRUPT_EnableGlobal
 * 1. Set SREG I-bit (sei). Return E_OK.
 *
 * INTERRUPT_DisableGlobal
 * 1. Clear SREG I-bit (cli). Return E_OK.
 */

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
