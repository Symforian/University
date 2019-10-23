#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>
#include <util/delay.h>
#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem
#define LED_DDR DDRB
#define LED_PORT PORTB
#define LED PB5



// inicjalizacja ADC
void adc_init()
{
  ADMUX   = _BV(REFS0); // referencja AVcc, wejście ADC0
  DIDR0   = _BV(ADC0D); // wyłącz wejście cyfrowe na ADC0
  // częstotliwość zegara ADC 125 kHz (16 MHz / 128)
  ADCSRA  = _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2); // preskaler 128
  ADCSRA |= _BV(ADEN); // włącz ADC
}

int main()
{

  // zainicjalizuj ADC
  adc_init();
  LED_DDR |= _BV(LED);

  // mierz napięcie
  while(1) {
    ADCSRA |= _BV(ADSC); // wykonaj konwersję
LED_PORT &= ~_BV(LED);
    while (!(ADCSRA & _BV(ADIF))); // czekaj na wynik
    ADCSRA |= _BV(ADIF); // wyczyść bit ADIF (pisząc 1!)
    uint16_t const times[16] = {1,2,3,5,6,7,8,12,14,20,28,38,64,96,128,512};
    uint16_t v = ADC; // weź zmierzoną wartość (0..1023)
    uint16_t time =0;


        time = times[v>>6];

    while(time > 0){
        LED_PORT |= _BV(LED);
        _delay_us(1);
        time--;
    }
        LED_PORT &= ~_BV(LED);
        _delay_us(1);

  }
}


