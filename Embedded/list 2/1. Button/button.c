#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */
#include <stdio.h>
#include <inttypes.h>
#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem
#define DEBOUNCE_TIME  1000                            /* microseconds */


#define LED PB5
#define LED_DDR DDRB
#define LED_PORT PORTB

#define BTN PB0
#define BTN_PIN PINB
#define BTN_PORT PORTB

uint8_t debounce(void) {
    if (bit_is_clear(BTN_PIN, BTN)) {      /* button is pressed now */
        _delay_us(DEBOUNCE_TIME);
        if (bit_is_clear(BTN_PIN, BTN)) {            /* still pressed */
            return (1);    
        }  
    }
    return (0);
}
int main(void) {

    // -------- Inits --------- //
    DDRB = 0xff; // led as output
    DDRB &= ~(1 << BTN);    /* Data Direction Register B:
                                   enables input. */
    BTN_PORT |= (1<<BTN);  // pull up 
    int8_t buffor[2000];
    int counter = 0;
    int reading = 0;
    int printing = 0;
//    int was_pressed = 0;
  // ------ Event loop ------ //
  while (1) {
        if (!reading && bit_is_clear(BTN_PIN, BTN)){ reading ++;}
      if(reading){
       // if(debounce()){
      //      if(! was_pressed){ 
        if(bit_is_clear(BTN_PIN, BTN)){
                buffor[counter] = 1;                        /* pressed */   
         //       was_pressed = 1; 
                }
//            }
        else {                                              /* not pressed */
        //    was_pressed = 0;
            buffor[counter] = 0;
            }
        counter ++;
      counter %= 2000;
       }


    if(counter == 1000) { printing = 1;}
    else if(printing == 1 && counter == 0){ printing = 2; }
    if(printing == 1){
            if(buffor[counter-1000]==1) { LED_PORT |= _BV(LED);}
            else if(buffor[counter-1000]==0)
                 {LED_PORT &= ~_BV(LED);}
            }

    
    else if (printing == 2){
            if(buffor[counter+1000]==1) { LED_PORT |= _BV(LED);}
            else if(buffor[counter+1000]==0)
                 {LED_PORT &= ~_BV(LED);}

            }

       _delay_ms(1);

  }                                                  /* End event loop */
  return 0;                            /* This line is never reached */
}
