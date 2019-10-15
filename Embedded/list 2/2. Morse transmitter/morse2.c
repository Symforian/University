#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */
#include <stdio.h>
#include <inttypes.h>


#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem 
                        /* microseconds */
#define LED PB5
#define LED_DDR DDRB
#define LED_PORT PORTB

#define BTN PD2
#define BTN_PIN PIND
#define BTN_PORT PORTD

#define DOT 1000
#define LINE 3000
#define START 15
#define ITER 8
// inicjalizacja UART
void uart_init()
{
  // ustaw baudrate
  UBRR0 = UBRR_VALUE;
  // wyczyść rejestr UCSR0A
  UCSR0A = 0;
  // włącz odbiornik i nadajnik
  UCSR0B = _BV(RXEN0) | _BV(TXEN0);
  // ustaw format 8n1
  UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);
}

// transmisja jednego znaku
int uart_transmit(char data, FILE *stream)
{
  // czekaj aż transmiter gotowy
  while(!(UCSR0A & _BV(UDRE0)));
  UDR0 = data;
  return 0;
}

// odczyt jednego znaku
int uart_receive(FILE *stream)
{
  // czekaj aż znak dostępny
  while (!(UCSR0A & _BV(RXC0)));
  return UDR0;
}

FILE uart_file;

uint8_t pressedHalfDot(void) {
    if (bit_is_clear(BTN_PIN, BTN)){
        _delay_ms(DOT/2);
        if (bit_is_clear(BTN_PIN, BTN)){
            return 1;    
        }  
    }
    return 0;
}
const char morse [30] = {'H','S','V','I','F','U','!','E','L','R','?','A','P','W','J','*','B','D','X','N','C','K','Y','T','Z','G','Q','M','@','O'};

char morseChar(uint8_t x,uint8_t n,uint8_t i) {
    //printf("%d\r\n",n);
    if( x == 0) return morse[n];
    if( x&1 )
        return morseChar(x>>2,n-i,i>>1);
    return morseChar(x>>2,n+i,i>>1);
}
char morseCode(uint8_t x){
    return morseChar(x,START,ITER);
}
int main(void) {
    // -------- Inits --------- //

  // zainicjalizuj UART
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
    LED_DDR = 0xff; // led as output
    DDRD &= ~(1 << BTN);    /* Data Direction Register D:
                                   enables input. */
    BTN_PORT |= (1<<BTN);  // pull up 
    uint8_t buffer = 0;
    int spaces = 0;
    int spac = 1;

//    int was_pressed = 0;
  // ------ Event loop ------ //
  while (1) {
    int dot =0;
    if(pressedHalfDot()){
        if(pressedHalfDot()){
            if(pressedHalfDot()){
                if(pressedHalfDot()){
                    if(pressedHalfDot()){
                        if(bit_is_clear(BTN_PIN, BTN)){ // after 2.5s
                            LED_PORT |= _BV(LED);
                            _delay_ms(500);
                            LED_PORT &= ~_BV(LED);
                            if(buffer >0 && spaces == 2){ buffer = 0; spaces = 0;}
                            /*printf("_\r\n"); */buffer |= 2;spaces = 0;
                        }// else dot=1;
                    }// else dot = 1;
                } else dot = 1;
                           
            } else  dot=1;
        } else dot=1;
    }//if not halfdot - ignore
 if(dot){
            if(buffer >0 && spaces == 2){ buffer = 0; spaces = 0;}
            /*printf("!.\r\n"); */buffer |= 1; spaces = 0;
 }
 if(!bit_is_clear(BTN_PIN, BTN)){
    _delay_ms(DOT);
    if(buffer > 0 && !bit_is_clear(BTN_PIN, BTN)){
        if(buffer > 0 && spaces == 3){     //buffer pelen
             while((buffer & 0b11)==0){  // while there is no info on last buffer place
                buffer>>=2;
             }
         //   printf("%d, %d<-\r\n",buffer,spaces);
             printf("%1c",morseCode(buffer));
             spac = 0;
             buffer = 0;
        //     if(spaces == 3){
        //        printf(",");}
        }
        //else  // reset if 2 spaces between words
        else{
           // printf("%d  )\n\r",buffer);
            if((buffer & 0b11000000)==0)
                buffer<<=2;
                LED_PORT |= _BV(LED);
                _delay_ms(100);
                LED_PORT &= ~_BV(LED);
            spaces++;
            }
        } 
        else if(!bit_is_clear(BTN_PIN, BTN) && (spaces < 7)){ spaces ++;}     
        else if(!bit_is_clear(BTN_PIN, BTN) && !spac && (spaces == 7)) {printf(" "); spac = 1;spaces = 0;} 
   } 
                                                  
 }                                      /* End event loop */
  return 0;                            /* This line is never reached */
}

