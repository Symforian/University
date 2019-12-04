#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>

#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem
#define MISO PD7
#define MOSI PD6
#define SS PD5
#define SCK PD4
void init()
{
    // ustaw "Mastera" wyjścia: MOSI, SS, SCK
    DDRD |= _BV(PD6) | _BV(PD5) | _BV(PD4);
}
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

// inicjalizacja SPI
void spi_init()
{
    // ustaw pin MISO jako wyjście
    DDRB |= _BV(PB4);
    // włącz SPI w trybie slave z zegarem 250 kHz
    SPCR = _BV(SPE) | _BV(SPR1);
}
uint8_t read_spi()
{
    while (!(SPSR & _BV(SPIF)));
    // wyczyść flagę przerwania
    SPSR |= _BV(SPIF);
    // zwróć otrzymane dane
    return SPDR;
}
// transmit byte serially, MSB first
void send_spi(char data)
{
   // slave select (active low)
   PORTD &= ~_BV(PD5);
   // send bits
   for (uint8_t i = 0; i < 8; i++)
   {
       //map MSB to signal
       if (data & 0x80)
           PORTD |= _BV(PD6);
       else
           PORTD &= ~_BV(PD6);
       // pulse clock to indicate that bit value should be read
       PORTD |= _BV(PD4);
       PORTD &= ~_BV(PD4);
       data <<= 1;
   }
   // slave deselect
   PORTD |= _BV(PD5);
}
int main()
{
  init();
  // zainicjalizuj UART
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  // zainicjalizuj SPI
  spi_init();
  // program testujący połączenie
  uint8_t v = 0;
  uint8_t w = 0;
  while(1) {
    send_spi(v);
    w = read_spi();
    printf("Wysłano: %"PRId8" Odczytano: %"PRId8"\r\n", v,w);
    v++;

  }
}


