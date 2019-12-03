#include <avr/io.h>
#include <avr/pgmspace.h>
#include <inttypes.h>
#include <util/delay.h>
#include "sound.h"
#define CS PB2
#define PORT_MCP PORTB
// init
void init(){
    DDRB |= _BV(CS);
}
// inicjalizacja SPI
void spi_init()
{
    // ustaw piny MOSI, SCK i ~SS jako wyjścia
    DDRB |= _BV(DDB3) | _BV(DDB5) | _BV(DDB2);
    // włącz SPI w trybie master z zegarem 250 kHz
    SPCR = _BV(SPE) | _BV(MSTR) | _BV(SPR1);
    //SPCR &= ~_BV(CPOL);
    //SPCR &= ~_BV(CPHL);
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


int main() {
 unsigned int audio_wav_len = 5796;
    init();
spi_init();
  while (1) {
// NOTE
//            NOTEH                 NOTEL
// |0 BUF GA\ SHDN\ D7 D6 D5 D4| D3 D2 D1 D0 X X X X|
   for(int n = 0; n < audio_wav_len; n++){
        uint8_t note = pgm_read_word(&audio_wav[n]);
        uint8_t noteh = note>>4;
        noteh |= 0x70;
        uint8_t notel = note<<4;
        PORT_MCP &= ~_BV(CS);
        spi_transfer(noteh);
        spi_transfer(notel);
        PORT_MCP |= _BV(CS);
        _delay_us(10);
        } 
    }


} 
