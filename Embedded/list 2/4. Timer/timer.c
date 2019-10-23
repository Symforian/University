#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
//#include <inttypes.h>
#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem

#define LED_DDR DDRD
#define LED_PORT PORTD

#define SWITCH_TIME 1
#define SWITCH_PORT PORTC
#define SWITCH_1 PC0 
#define SWITCH_2 PC1 

int main()
{
    UCSR0B  &= ~_BV(RXEN0) & ~_BV(TXEN0);
    DDRC |= (1 << SWITCH_1);    /* Data Direction Register C:
                                   enables input. */
    DDRC |= (1 << SWITCH_2);    /* Data Direction Register C:
                                   enables input. */
    uint8_t numbers[10]={0b11000000,0b11111001,0b10100100,0b10110000,0b10011001,0b10010010,0b00000010,0b11111000,0b10000000,0b00010000};
        // 0abcef    11111100 00000011
        // 1bc       01100000 10011111
        // 2abged    11011010 00100101
        // 3abgcd    11110010 00001101
        // 4fbgc     01100110 10011001
        // 5afgcd    10110110 01001001
        // 6afgecddp 10111111 01000000
        // 7abc      11100000 00011111
        // 8abcdefg  11111110 00000001
        // 9abgfcddp 11110111 00001000


LED_DDR = 0xff; 

  uint8_t i = 0;


  while(1) {
        int sec = 500;
        if(i==60) i = 0;
        while(sec > 0){
            _delay_ms(SWITCH_TIME);
		    SWITCH_PORT = 0b00000010;
            LED_PORT = numbers[i/10];

		    _delay_ms(SWITCH_TIME);
		    SWITCH_PORT = 0b00000001;
            LED_PORT = numbers[i%10];
            sec--;
        }


      // _delay_ms(1000);
        i++;
  }
}




