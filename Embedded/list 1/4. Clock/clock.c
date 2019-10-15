#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
//#include <inttypes.h>
#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem

#define LED_DDR DDRD
#define LED_PORT PORTD

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

int main()
{
  // zainicjalizuj UART
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
    UCSR0B  &= ~_BV(RXEN0) & ~_BV(TXEN0);

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
        if(i==10) i = 0;
        printf("%d\r\n",numbers[i]);
        LED_PORT = numbers[i];
        _delay_ms(1000);
        i++;
  }
}




