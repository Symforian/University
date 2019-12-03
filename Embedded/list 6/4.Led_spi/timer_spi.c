#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
//#include <inttypes.h>
#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem

#define _SPI DDRB
#define SPI_PORT PORTB
#define OE PB2
#define LA PB1
void init()
{
  _SPI |= _BV(LA) |_BV(OE);
}

// inicjalizacja SPI
void spi_init()
{
    // ustaw piny MOSI, SCK i ~SS jako wyjścia
    _SPI |= _BV(DDB3) | _BV(DDB5) | _BV(DDB2);
    // włącz SPI w trybie master z zegarem 250 kHz
    SPCR = _BV(SPE) | _BV(MSTR) | _BV(SPR1);
}

// transfer jednego bajtu
uint8_t spi_transfer(uint8_t data)
{
    // rozpocznij transmisję
    SPDR = data;
    // czekaj na ukończenie transmisji

    while (!(SPSR & _BV(SPIF)));

    // wyczyść flagę przerwania
    SPSR |= _BV(SPIF);
    // zwróć otrzymane dane
    return SPDR;
}
int main()
{
  init();
  spi_init();


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


  uint8_t i = 0;


  while(1) {
        if(i==10) i = 0;

        SPI_PORT |= _BV(OE);
        SPI_PORT &= ~_BV(LA);

        spi_transfer(~numbers[i]);

        SPI_PORT |= _BV(LA);
        SPI_PORT &= ~_BV(OE);
        _delay_ms(1000);

        i++;
  }
}




