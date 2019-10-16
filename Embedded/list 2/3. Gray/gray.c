#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */
#include <stdio.h>
#include <inttypes.h>


#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem 
#define DB_TIME 1000
#define BTN_CD 500

#define LED_DDR DDRD
#define LED_PORT PORTD


#define BTN_PIN PINB
#define BTN_PORT PORTB
#define BTN_NEXT PB0
#define BTN_PREV PB1
#define BTN_REST PB2
int debounce(uint8_t button){
    if(bit_is_clear(BTN_PIN, button)){
        _delay_us(DB_TIME);
        if(bit_is_clear(BTN_PIN,button))
            return 1;
    }
    return 0;
}

int main(void) {
    // -------- Inits --------- //
    UCSR0B  &= ~_BV(RXEN0) & ~_BV(TXEN0); //Enable PD0 & PD1
    LED_DDR = 0xff; // led as output
    DDRB &= ~(1 << BTN_NEXT);    /* Data Direction Register B:
                                   enables input. */
    DDRB &= ~(1 << BTN_PREV);
    DDRB &= ~(1 << BTN_NEXT);
    BTN_PORT |= (1<<BTN_NEXT);  // pull up
    BTN_PORT |= (1<<BTN_PREV);  // pull up
    BTN_PORT |= (1<<BTN_REST);  // pull up 
    uint8_t light = 0;
    uint8_t number = 0;
  // ------ Event loop ------ //
    LED_PORT &= 0;
  while (1) {
    if(debounce(BTN_REST)){
        LED_PORT &= ~light;
        light = 0; number = 0; 
        _delay_ms(BTN_CD);
        }
    if(debounce(BTN_NEXT)){
        number++; 
        LED_PORT &= ~light; 
        light = number ^ (number>>1);
        LED_PORT |= light;
        _delay_ms(BTN_CD);
        }
    if(debounce(BTN_PREV)){
        number--;  
        LED_PORT &= ~light; 
        light = number ^ (number>>1);
        LED_PORT |= light;
        _delay_ms(BTN_CD);
        }


 }                                      /* End event loop */
  return 0;                            /* This line is never reached */
}

