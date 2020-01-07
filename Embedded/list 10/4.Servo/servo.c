#include <avr/io.h>
#include <util/delay.h>
// inicjalizacja ADC
void adc_init()
{
  ADMUX   = _BV(REFS0); // referencja AVcc, wejście ADC0
  DIDR0   = _BV(ADC0D); // wyłącz wejście cyfrowe na ADC0
  // częstotliwość zegara ADC 125 kHz (16 MHz / 128)
        
  ADCSRA  = _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2); // preskaler 128
  ADCSRA |= _BV(ADEN); // włącz ADC
}

void timer1_init()
{
  // PWM 50Hz
  // ustaw tryb licznika
  // COM1A = 10   -- non-inverting mode
  // WGM1  = 1110 -- fast PWM top=ICR1
  // CS1   = 100  -- prescaler 256
  // ICR1  = 124
  // częstotliwość 16e6/(256*(1+1249)) = 50  Hz
  // wzór: datasheet 20.12.3 str. 164
  ICR1 = 1249;
  TCCR1A = _BV(COM1A1) | _BV(WGM11);
  TCCR1B = _BV(WGM12) | _BV(WGM13) | _BV(CS12);
  // ustaw pin OC1A (PB1) jako wyjście
  DDRB |= _BV(PB1);
}

int main()
{
  // inicjalizacja adc
  adc_init();
  // uruchom licznik
  timer1_init();
  uint16_t const width[16] = {65,69,73,77,82,86,90,93,95,98,102,105,109,112,118,120};
  while(1)
  {
    // mierz napięcie
    ADCSRA |= _BV(ADSC); // wykonaj konwersję
    while (!(ADCSRA & _BV(ADIF))); // czekaj na wynik
    ADCSRA |= _BV(ADIF); // wyczyść bit ADIF (pisząc 1!)

    uint16_t v = ADC; // weź zmierzoną wartość (0..1023)
    // ustaw wypełnienie
    OCR1A = width[v>>6];
  }
}


