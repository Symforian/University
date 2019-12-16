#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <inttypes.h>
#include "hd44780.h"
#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem
// inicjalizacja UART
void uart_init()
{
  // ustaw baudrate
  UBRR0 = UBRR_VALUE;
  // włącz odbiornik i nadajnik
  UCSR0B = _BV(RXEN0) | _BV(TXEN0);
  // ustaw format 8n1
  UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);
}

// odczyt jednego znaku
int uart_receive(FILE *stream)
{
  // czekaj aż znak dostępny
  while (!(UCSR0A & _BV(RXC0)));
  return UDR0;
}

int hd44780_transmit(char data, FILE *stream)
{
  LCD_WriteData(data);
  return 0;
}

FILE hd44780_file;
FILE uart_file;
int main()
{
  // skonfiguruj wyświetlacz
  LCD_Initialize();
  LCD_Clear();
  uart_init();
  // skonfiguruj strumienie wyjściowe
  fdev_setup_stream(&hd44780_file, hd44780_transmit, NULL, _FDEV_SETUP_WRITE);
  fdev_setup_stream(&uart_file, NULL, uart_receive, _FDEV_SETUP_READ);
  stdout = stderr = &hd44780_file;
  stdin = &uart_file;
  // program testowy
  char v = '0';
  uint8_t i = 0;
  uint8_t n = 0;
  char row[17] = {32};
  while(1) {
    scanf("%c",&v);
    if(v == 13)
        {
            if(n==0) {
                    n=1;
                    for (uint8_t j = 0; j < 17; j += 1)
                    {
                        row[j] = ' ';
                    }
                }
            else{
                    n=0;
                    LCD_Clear();
                    for (uint8_t j = 0; j < 17; j += 1)
                    {
                        LCD_GoTo(j, n);
                        printf("%c",row[j]);
                        row[j] = ' ';
                    }


                }
            i=0;
            LCD_GoTo(i, n);
        }
    else{
        LCD_GoTo(i, n);
        printf("%c", v);
        _delay_ms(250);
        row[i] = v;
        i++;
        if(n==1 && i==16){i=0;n=1;LCD_GoTo(i, n);}
        if(i==16){i=0;n++;LCD_GoTo(i, n);}
    }
    
  }
}


