/*
 * Author: Ahmed Ellamie
 * Email:  ahmed.ellamiee@gmail.com
 *
 * STUDENT TASK — ADC.c  (ATmega32, 10-bit)
 * Implement every prototype from ADC_interface.h.
 */

#include "STD_TYPES.h"
#include "ADC_interface.h"
#include "ADC_private.h"

/*
 * ADC_Init
 * 1. Reject an unknown reference or prescaler.
 * 2. Write REFS1:0 (and ADLAR = 0 for right adjust) in ADMUX.
 * 3. Write ADPS2:0, then set ADEN. Do not start a conversion yet.
 * 4. Target ADC clock 50..200 kHz (8 MHz / 64 = 125 kHz).
 */

/*
 * ADC_ReadChannel
 * 1. Reject Channel > 7 or a NULL pointer.
 * 2. Keep REFS bits, replace MUX4:0 with the channel.
 * 3. Set ADSC. Poll ADIF (or ADSC) until the conversion ends.
 * 4. Clear ADIF by writing 1 to it.
 * 5. Read ADCL then ADCH. Combine: reading = ADCL | ((uint16)ADCH << 8).
 */

/*
 * ADC_StartConversion
 * 1. Select the channel as above.
 * 2. Set ADSC and return. Used when the result will be read later or in an ISR.
 */

/*
 * ADC_GetResult
 * 1. If ADIF is 0, return E_NOK (still busy).
 * 2. Clear ADIF, read ADCL then ADCH, store the 10-bit value.
 */

/*
 * ADC_SetInterrupt
 * 1. Copy_u8State == 1 -> set ADIE.  == 0 -> clear ADIE.
 * 2. The ISR vector is ADC_vect. Do not write the ISR in this file unless asked.
 */
