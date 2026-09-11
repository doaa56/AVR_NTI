/*
 * Author: Ahmed Ellamie
 * Email:  ahmed.ellamiee@gmail.com
 *
 * AVR_NTI application entry.
 * Layers: LIB (types) -> MCAL (drivers) -> HAL (devices) -> Logic (app) ->
 * main.
 */

#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "INTERRUPT_interface.h"
#include <util/delay.h>
#include "ADC_interface.h"
#include "GPIO_interface.h"
#include "TIMER_interface.h"

void INT0_ISR(void);

int main(void)
{
  GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN5, GPIO_OUTPUT);
  GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN6, GPIO_OUTPUT);
  GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN2, GPIO_INPUT);

  TIMER0_Init();
  //callback->sense->enable source->enable global
  EXTI_SetCallback(EXTI_INT0, INT0_ISR);
  EXTI_SetSense(EXTI_INT0, EXTI_ANY_CHANGE);
  EXTI_Enable(EXTI_INT0);
  INTERRUPT_EnableGlobal();

  while(1){
   GPIO_TogglePinValue(GPIO_PORTA, GPIO_PIN5);
   TIMER0_DelayMS(1000);
   
  }


 /* KeyPad_Init(GPIO_PORTB);
  SevenSegment_Init(GPIO_PORTA);
  uint8 pressedKey ;
  while(1){
    KeyPad_GetPressedKey(GPIO_PORTB, &pressedKey);
    if (pressedKey == 0xFF)
    {
    continue; // No key pressed, continue the loop
    }
    else
    {
    SevenSegment_Display(GPIO_PORTA, pressedKey);
    }
  
  }
*/

  /*
  uint8 sevenseg = 0;

  GPIO_SetPortDirection(GPIO_PORTA, 0xFF);

  while (1)
  {
    switch (sevenseg)
    {
    case 0:
      GPIO_SetPortValue(GPIO_PORTA, 0x3F);
      break;
    case 1:
      GPIO_SetPortValue(GPIO_PORTA, 0x06);
      break;
    case 2:
      GPIO_SetPortValue(GPIO_PORTA, 0x5B);
      break;
    case 3:
      GPIO_SetPortValue(GPIO_PORTA, 0x4F);
      break;
    case 4:
      GPIO_SetPortValue(GPIO_PORTA, 0x66);
      break;
    case 5:
      GPIO_SetPortValue(GPIO_PORTA, 0x6D);
      break;
    case 6:
      GPIO_SetPortValue(GPIO_PORTA, 0x7D);
      break;
    case 7:
      GPIO_SetPortValue(GPIO_PORTA, 0x07);
      break;
    case 8:
      GPIO_SetPortValue(GPIO_PORTA, 0x7F);
      break;
    case 9:
      GPIO_SetPortValue(GPIO_PORTA, 0x6F);
      break;
    default:
      GPIO_SetPortValue(GPIO_PORTA, 0x00);
      break;
    }

    _delay_ms(500);
    sevenseg++;

    if (sevenseg > 9)
    {
      sevenseg = 0;
    }
  }
*/

  return 0;
}
void INT0_ISR(void)
{
  // This function will be called when INT0 interrupt occurs
  // You can add your code here to handle the interrupt
  GPIO_TogglePinValue(GPIO_PORTA, GPIO_PIN6); // Toggle the value of pin PA6
}