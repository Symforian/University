#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem
#define LED PB5
#define LED_DDR DDRB
#define LED_PORT PORTB
#define DOT 1000
#define LINE 3000
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
void sigSpace()
{
    LED_PORT &= ~_BV(LED);
    _delay_ms(DOT*7);
        printf(" ");
}
void sigSeparationLetters()
{
    LED_PORT &= ~_BV(LED);
    _delay_ms(LINE);

}
void sigSeparationSignals()
{
    LED_PORT &= ~_BV(LED);
    _delay_ms(DOT);

}
void sigLn()
{
    LED_PORT |= _BV(LED);
    _delay_ms(LINE);
    LED_PORT &= ~_BV(LED);
    sigSeparationSignals();
}
void sigDot()
{
    LED_PORT |= _BV(LED);
    _delay_ms(DOT);
    LED_PORT &= ~_BV(LED);
    sigSeparationSignals();

}

void led_signal(char c);
int main()
{
  // zainicjalizuj UART
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  LED_DDR |= _BV(LED);
  while(1) {
    char args[50];
    scanf("%[^\r\n]%c", &args);
    for(int i = 0; args[i]!='\0';i++){
    //printf("Odczytano: '%c' \r\n", toupper(args[i]));
        if(args[i] == ' ')
            sigSpace();
        led_signal(args[i]);
        if(i<49 && args[i+1] != ' ' && args[i+1] != '\0')
            sigSeparationLetters();
        }
  }
}

void led_signal(char c){
    c = toupper(c);
    switch(c){
// 

// - - - - -
        case '0':
            sigLn();
            sigLn();
        case 'O':
            sigLn();
        case 'M':
            sigLn();
        case 'T':
            sigLn();
        break;
// - - - - .
        case '9':
        sigLn();
        sigLn();
        case 'G':
        sigLn();
        case 'N':
        sigLn();
        case 'E':
        sigDot();
        break;
// - - - . .
        case '8':
        sigLn();
        case 'Z':
        sigLn();
        case 'D':
        sigLn();
        case 'I':
        sigDot();
        sigDot();
        break;
// - - . . . 
        case '7':
        sigLn();
        case 'B':
        sigLn();
        case 'S':
        sigDot(); 
        sigDot();
        sigDot();
        break;
        
// - . . . .
        case '6':
        sigLn();
        case 'H':
        sigDot(); 
        sigDot();
        sigDot();
        sigDot();
        break;
// . - - - -
        case '1':
            sigDot();
            sigLn();
            sigLn();
            sigLn();
            sigLn();
        break;
// . . - - -
        case '2':
            sigDot();
        case 'J':
            sigDot();
            sigLn();
            sigLn();
            sigLn();
        break;
// . - .
        case 'R':
        sigDot();
        sigLn();
        sigDot();
        break;
// . - . .
        case 'L':
        sigDot();
        sigLn();   
        sigDot();
        sigDot();
        break;
        case 'P':
        sigDot();
        sigLn();
        sigLn();
        sigDot();
        break;
// . . - .
        case 'F':
        sigDot();
        sigDot();
        sigLn();
        sigDot();
        break;
// . . . - -
        case '3':
            sigDot();
            sigDot();
        case 'W':
            sigDot();
            sigLn();
            sigLn();
        break;
// . . . . -
        case '4':
            sigDot();
        case 'V':
            sigDot();
        case 'U':
            sigDot();
        case 'A':
            sigDot();
            sigLn();
        break;

// . . . . .
        case '5':
            sigDot();
            sigDot();
            sigDot();
            sigDot();
            sigDot();
        break;
        case 'K':
            sigLn();
            sigDot();
            sigLn();
            break;
        case 'Y':
            sigLn();
            sigDot();
            sigLn();
            sigLn();
            break;
        case 'C':
            sigLn();
            sigDot();
            sigLn();
            sigDot();
            break;
        case 'X':
            sigLn();
            sigDot();
            sigDot();
            sigLn();
            break;
        case 'Q':
            sigLn();
            sigLn();
            sigDot();
            sigLn();
            break;
        default:
            break;
    }
}


