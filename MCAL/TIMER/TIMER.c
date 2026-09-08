/*
 * Author: Ahmed Ellamie
 * Email:  ahmed.ellamiee@gmail.com
 *
 * STUDENT TASK — TIMER.c  (ATmega32 Timer0 + Timer1)
 * Implement every prototype from TIMER_interface.h.
 */

#include "STD_TYPES.h"
#include "TIMER_interface.h"
#include "TIMER_private.h"

/*
 * TIMER0_Init
 * 1. Reject an unknown mode.
 * 2. NORMAL          : WGM01=0 WGM00=0
 *    PHASE_CORRECT   : WGM01=0 WGM00=1
 *    CTC             : WGM01=1 WGM00=0
 *    FAST_PWM        : WGM01=1 WGM00=1
 * 3. Do not change CS02:0 here — TIMER0_Start owns the clock.
 */

/*
 * TIMER0_Start
 * 1. Write CS02:0 from Copy_u8Prescaler (1, 8, 64, 256, 1024, or ext T0).
 * 2. Leave WGM and COM bits as they are.
 */

/*
 * TIMER0_Stop
 * 1. Clear CS02:0 only. TCNT0 is unchanged.
 */

/*
 * TIMER0_SetCompareValue
 * 1. Write Copy_u8Value to OCR0.
 * 2. CTC period: ticks = OCR0 + 1.
 *    8 MHz / 64, OCR0 = 124 -> 1 ms tick.
 */

/*
 * TIMER0_SetCompareOutput
 * 1. Write COM01:0. For PWM on an LED, set PB3 as GPIO_OUTPUT first.
 */

/*
 * TIMER0_SetOverflowInterrupt / TIMER0_SetCompareInterrupt
 * 1. Set or clear TOIE0 / OCIE0 in TIMSK.
 * 2. Vectors: TIMER0_OVF_vect , TIMER0_COMP_vect. Global I-bit is INTERRUPT's job.
 */

/*
 * TIMER1_Init / TIMER1_Start / TIMER1_Stop
 * 1. WGM13:0 live in TCCR1A (WGM11:10) and TCCR1B (WGM13:12).
 * 2. CTC on OCR1A is mode 4: WGM13:0 = 0100.
 * 3. CS12:0 are in TCCR1B.
 */

/*
 * TIMER1_SetCompareA / TIMER1_SetICR1
 * 1. 16-bit write: high byte first, then low byte (or assign the 16-bit register).
 */
