#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

/*
 * Author: Ahmed Ellamie
 * Email:  ahmed.ellamiee@gmail.com
 *
 * MCAL TIMER — public API for ATmega32 Timer0 and Timer1.
 * Include this header from HAL, Logic, and main. Do not include TIMER_private.h there.
 */

#include "STD_TYPES.h"

/* ---------------- Timer0 waveform modes (TCCR0 WGM01:WGM00) ---------------- */
#define TIMER0_NORMAL          0u
#define TIMER0_PHASE_CORRECT   1u
#define TIMER0_CTC             2u
#define TIMER0_FAST_PWM        3u

/* ---------------- Timer0 / Timer1 clock select ---------------- */
#define TIMER_PRESC_STOP       0u
#define TIMER_PRESC_1          1u
#define TIMER_PRESC_8          2u
#define TIMER_PRESC_64         3u
#define TIMER_PRESC_256        4u
#define TIMER_PRESC_1024       5u
#define TIMER_EXT_FALLING      6u
#define TIMER_EXT_RISING       7u

/* Aliases used in the Timer lecture slides */
#define TIMER0_PRESC_1         TIMER_PRESC_1
#define TIMER0_PRESC_8         TIMER_PRESC_8
#define TIMER0_PRESC_64        TIMER_PRESC_64
#define TIMER0_PRESC_256       TIMER_PRESC_256
#define TIMER0_PRESC_1024      TIMER_PRESC_1024

/* ---------------- Timer0 OC0 (PB3) compare output ---------------- */
#define TIMER0_OC_DISCONNECTED 0u
#define TIMER0_OC_TOGGLE       1u    /* CTC / Normal only */
#define TIMER0_OC_NON_INVERT   2u    /* PWM: clear on compare, set at BOTTOM */
#define TIMER0_OC_INVERT       3u

/* ---------------- Timer1 waveform modes (subset) ---------------- */
#define TIMER1_NORMAL          0u
#define TIMER1_CTC_OCR1A       4u
#define TIMER1_FAST_PWM_8BIT   5u
#define TIMER1_FAST_PWM_ICR1   14u

/*
 * Description : Select the Timer0 waveform mode. Does not start the clock.
 */
STD_ReturnType TIMER0_Init(uint8 Copy_u8Mode);

/*
 * Description : Start Timer0 with the given CS02:0 prescaler value.
 */
STD_ReturnType TIMER0_Start(uint8 Copy_u8Prescaler);

/*
 * Description : Stop Timer0 (CS02:0 = 000). TCNT0 keeps its value.
 */
STD_ReturnType TIMER0_Stop(void);

/*
 * Description : Write OCR0. Period in CTC, duty in PWM.
 */
STD_ReturnType TIMER0_SetCompareValue(uint8 Copy_u8Value);

/*
 * Description : Configure COM01:0 (OC0 / PB3 behaviour).
 */
STD_ReturnType TIMER0_SetCompareOutput(uint8 Copy_u8ComMode);

/*
 * Description : Enable or disable Timer0 overflow / compare-match interrupts
 *               (TOIE0, OCIE0 in TIMSK). 1 = enable, 0 = disable.
 */
STD_ReturnType TIMER0_SetOverflowInterrupt(uint8 Copy_u8State);
STD_ReturnType TIMER0_SetCompareInterrupt(uint8 Copy_u8State);

/*
 * Description : Select a Timer1 mode (Normal, CTC on OCR1A, Fast PWM).
 */
STD_ReturnType TIMER1_Init(uint8 Copy_u8Mode);

/*
 * Description : Start / stop Timer1 (TCCR1B CS12:0).
 */
STD_ReturnType TIMER1_Start(uint8 Copy_u8Prescaler);
STD_ReturnType TIMER1_Stop(void);

/*
 * Description : 16-bit compare / top values.
 */
STD_ReturnType TIMER1_SetCompareA(uint16 Copy_u16Value);
STD_ReturnType TIMER1_SetICR1(uint16 Copy_u16Value);

#endif /* TIMER_INTERFACE_H */
