#include <avr/io.h>
#include <util/delay.h>
#define RIGHT PD3
#define LEFT PD4
#define PORT_MOTOR PORTD
#define DDR_MOTOR DDRD
// inicjalizacja silnika
void motor_init()
{
  DDR_MOTOR |= _BV(RIGHT) | _BV(LEFT);
  PORT_MOTOR &= ~_BV(LEFT);
  PORT_MOTOR &= ~_BV(RIGHT);
}
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
  // PWM 500Hz - 1kHz
  // ustaw tryb licznika
  // COM1A = 10   -- non-inverting mode
  // WGM1  = 1110 -- fast PWM top=ICR1
  // CS1   = 100  -- prescaler 256
  // ICR1  = 124
  // częstotliwość 16e6/(256*(1+124)) = 500 Hz
  // wzór: datasheet 20.12.3 str. 164
  ICR1 = 124;
  TCCR1A = _BV(COM1A1) | _BV(WGM11);
  TCCR1B = _BV(WGM12) | _BV(WGM13) | _BV(CS12);
  // ustaw pin OC1A (PB1) jako wyjście
  DDRB |= _BV(PB1);
}

int main()
{
  // inicjalizacja silnika
  motor_init();
  // inicjalizacja adc
  adc_init();
  // uruchom licznik
  timer1_init();
  uint16_t const width[16] = {124, 108, 93, 77, 62, 46, 31, 15,15, 31, 46, 62, 77, 93, 108, 124};
  while(1)
  {
    // mierz napięcie
    ADCSRA |= _BV(ADSC); // wykonaj konwersję
    while (!(ADCSRA & _BV(ADIF))); // czekaj na wynik
    ADCSRA |= _BV(ADIF); // wyczyść bit ADIF (pisząc 1!)

    uint16_t v = ADC>>6; // weź zmierzoną wartość (0..1023)
    if(v < 8){
      PORT_MOTOR &= ~_BV(LEFT);
      PORT_MOTOR |= _BV(RIGHT);
    }
    else {
      PORT_MOTOR &= ~_BV(RIGHT);
      PORT_MOTOR |= _BV(LEFT);
    }
    // ustaw wypełnienie
    OCR1A = width[v];          
    _delay_ms(500);
  }
}


