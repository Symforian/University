#include <avr/io.h>
#include <util/delay.h>

#define LED PB5
#define LED_DDR DDRD
#define LED_PORT PORTD
#define DELAYTIME 85 

int main() {
  UCSR0B  &= ~_BV(RXEN0) & ~_BV(TXEN0); //Enable PD0 & PD1
  uint8_t i = 0;
  LED_DDR = 0xff;               // Data Direction Register B all set up for output 
  while (1) {
    while (i < 7) {
    LED_PORT = (1 << i);                 /* illuminate only i'th pin */
    _delay_ms(DELAYTIME);                                    /* wait */
    i = i + 1;                               /* move to the next LED */ 
    }
    while (i > 0)  {
    LED_PORT = (1 << i);                 /* illuminate only i'th pin */
    _delay_ms(DELAYTIME);                                    /* wait */
    i = i - 1;                           /* move to the previous LED */    
    }  
  }   
}

