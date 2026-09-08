#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/*
 * Author: Ahmed Ellamie
 * Email:  ahmed.ellamiee@gmail.com
 *
 * STUDENT TASK — GPIO private layer (ATmega32)
 * Include this file ONLY from GPIO.c. Never from main, HAL, or Logic.
 *
 * This file contains the hardware register map used by GPIO.c only.
 * Public port constants remain in GPIO_interface.h.
 */

#include "STD_TYPES.h"

#define GPIO_DDRA_REG (*(volatile uint8 *)0x3A)
#define GPIO_PORTA_REG (*(volatile uint8 *)0x3B)
#define GPIO_PINA_REG (*(volatile uint8 *)0x39)

#define GPIO_DDRB_REG (*(volatile uint8 *)0x37)
#define GPIO_PORTB_REG (*(volatile uint8 *)0x38)
#define GPIO_PINB_REG (*(volatile uint8 *)0x36)

#define GPIO_DDRC_REG (*(volatile uint8 *)0x34)
#define GPIO_PORTC_REG (*(volatile uint8 *)0x35)
#define GPIO_PINC_REG (*(volatile uint8 *)0x33)

#define GPIO_DDRD_REG (*(volatile uint8 *)0x31)
#define GPIO_PORTD_REG (*(volatile uint8 *)0x32)
#define GPIO_PIND_REG (*(volatile uint8 *)0x30)

#define GPIO_PIN_MASK(pin) (1u << (pin))
#define GPIO_MAX_PIN 7u
#define GPIO_MAX_PORT 3u

#endif /* GPIO_PRIVATE_H */
