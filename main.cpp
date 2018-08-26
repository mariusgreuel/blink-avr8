//
// main.cpp
// Copyright (C) 2018 Marius Greuel. All rights reserved.
//

#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <util/delay.h>

///////////////////////////////////////////////////////////////////////////////

#if defined (BOARD_ArduinoUno) || defined (BOARD_ArduinoNano)
#define LED_DDR DDRB
#define LED_PORT PORTB
#define LED_BIT 5 // Pin 13 (built-in LED)
#elif defined (BOARD_Digispark) || defined (BOARD_DigisparkPro)
#define LED_DDR DDRB
#define LED_PORT PORTB
#define LED_BIT 1 // Pin 1 (built-in LED)
#elif defined (BOARD_ProMicro)
#define LED_DDR DDRB
#define LED_PORT PORTB
#define LED_BIT 0 // Pin 17 (built-in Rx LED)
#elif defined (BOARD_FabISP)
#define LED_DDR DDRA
#define LED_PORT PORTA
#define LED_BIT 5 // PA5/MISO
#elif defined (BOARD_USBASP)
#define LED_DDR DDRC
#define LED_PORT PORTC
#define LED_BIT 0 // PC0 (built-in LED 2)
#else
#error Unsupported board
#endif

int main(void)
{
    wdt_disable();

    LED_DDR = _BV(LED_BIT);

    for (;;)
    {
        LED_PORT |= _BV(LED_BIT);
        _delay_ms(500);
        LED_PORT &= ~_BV(LED_BIT);
        _delay_ms(500);
    }

    return 0;
}
