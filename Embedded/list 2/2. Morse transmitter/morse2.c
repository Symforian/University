#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */
#include <stdio.h>
#include <inttypes.h>
#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem
#define DEBOUNCE_TIME  1000                            /* microseconds */
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
uint8_t debounce(void) {
    if (bit_is_clear(PIND, PD2)) {      /* button is pressed now */
        _delay_us(DEBOUNCE_TIME);
        if (bit_is_clear(PIND, PD2)) {            /* still pressed */
            return (1);    
        }  
    }
    return (0);
}
const char morse [30] = {'H','S','V','I','F','U','!','E','L','R','?','A','P','W','J','*','B','D','X','N','C','K','Y','T','Z','G','Q','M','@','O'};

char morseChar(uint8_t x,uint8_t n,uint8_t i) {
  //  printf("%d\r\n",n);
    if( x == 0) return morse[n];
    if( x&1 )
        return morseChar(x>>2,n-i,i>>1);
    return morseChar(x>>2,n+i,i>>1);
}
char morseCode(uint8_t x){
    return morseChar(x,START,ITER);
}
int main(void) {
// to jak klik to . jak dl klik to _
// T1 OUTPUT . _ ON SCREEN
// znak spacja Z
// word_space  S
// kod spacja ' '
    // -------- Inits --------- //

  // zainicjalizuj UART
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
    DDRB = 0xff; // led as output
    DDRD &= ~(1 << PD2);    /* Data Direction Register B:
                                   enables input. */
    PORTD |= (1<<PD2);  // pull up 
    int8_t buffer = 0;

//    int was_pressed = 0;
  // ------ Event loop ------ //
  while (1) {
//areas of correction +- .5 s extract function <<<TODO 
    if(bit_is_clear(PIND, PD2)){
       _delay_ms(DOT);
       if(bit_is_clear(PIND, PD2)){
            _delay_ms(DOT);
            if(bit_is_clear(PIND, PD2)){
                    if(bit_is_clear(PIND, PD2)){
                        PORTB = 0b00111100;
                        _delay_ms(100);
                        PORTB = 0b11000011;
                        printf("_\r\n");
                        buffer |= 2;
                    }
                    else
                    {printf(".\r\n");
                        buffer |= 1;}
            }
            else
            {printf(".\r\n");
                        buffer |= 1;}
        }
    }
   /* else{
    _delay_ms(DOT);
    if(bit_is_clear(PIND, PD2)){
        buffer<<=2;
 //       printf(" ");
        } else {
        _delay_ms(DOT);
        _delay_ms(DOT);
        if(bit_is_clear(PIND, PD2)){
                printf("%c",morseCode(buffer));
                buffer =0;
                }
        else {
            _delay_ms(DOT);
            _delay_ms(LINE);
            if(!bit_is_clear(PIND, PD2)){
                printf("%c\r\n",morseCode(buffer));
                buffer =0;
                }
            }
        }

    }*/
        if(!(buffer==0)) {
                printf("%c\r\n",morseCode(buffer));
                buffer =0;}
    
  }                                                  /* End event loop */
  return 0;                            /* This line is never reached */
}



/*
4 znaki max, 3 mozliwosci . _ 0 
00 = 0
01 = . 
10 = _
7 3 2 1 0 i i i  0 0 i i  0 0 0 i
E = 00 00 00 01
Z = 01 01 10 10
a b a= 0 b = 28
R = . - .
R = 00 01 10 01





1 3 = 2
1 7 = 4
5 7 = 6





*/
