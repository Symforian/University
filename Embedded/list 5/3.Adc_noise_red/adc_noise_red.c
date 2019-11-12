#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/sleep.h>
#include <inttypes.h>
#include <stdio.h>
#include <util/delay.h>
#define BAUD 9600                            // baudrate
#define UBRR_VALUE ((F_CPU) / 16 / (BAUD)-1) // zgodnie ze wzorem
#define SIZE 60
// inicjalizacja UART
void uart_init() {
  // ustaw baudrate
  UBRR0 = UBRR_VALUE;
  // włącz odbiornik i nadajnik
  UCSR0B = _BV(RXEN0) | _BV(TXEN0);
  // ustaw format 8n1
  UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);
}

// transmisja jednego znaku
int uart_transmit(char data, FILE *stream) {
  // czekaj aż transmiter gotowy
  while (!(UCSR0A & _BV(UDRE0)))
    ;
  UDR0 = data;
  return 0;
}

// odczyt jednego znaku
int uart_receive(FILE *stream) {
  // czekaj aż znak dostępny
  while (!(UCSR0A & _BV(RXC0)))
    ;
  return UDR0;
}

// inicjalizacja ADC
void adc_init() {
  ADMUX = _BV(REFS0); // referencja AVcc, wejście ADC0
  DIDR0 = _BV(ADC0D); // wyłącz wejście cyfrowe na ADC0
  // częstotliwość zegara ADC 125 kHz (16 MHz / 128)

  ADCSRA = _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2); // preskaler 128
  ADCSRA |= _BV(ADIE);                           // ADC Interrupt Enabled
  ADCSRA |= _BV(ADEN);                           // włącz ADC
}

FILE uart_file;
volatile uint16_t counter = 0;
volatile float v = 0;
volatile float red[SIZE / 2];
ISR(ADC_vect) {

  if (counter == SIZE) {
    float average = 0;
    for (int i = 0; i < SIZE / 2; i++) {
      average += red[i];
    }
    average /= (SIZE / 2);
    float variance = 0;
    for (int i = 0; i < SIZE / 2; i++) {
      float temp = red[i] - average;
      variance += (temp * temp);
    }
    variance /= (SIZE / 2);
    printf("Wariancja z noise reduction: \t%f\r\n", variance);
    _delay_ms(100);
    /*  if(variance < 0){
      printf("TSOOOOO:\n%" PRId32 "",average);
      for (int i = 0; i < SIZE / 2; i++) {
        printf("T[%d] = %" PRId32 "\r\n",i, red[i]);
          _delay_ms(1000);
      }*/
    //}
  } else {
    ADCSRA |= _BV(ADIF);
    v = (1024.0 * 1.1) / ADC;
    red[counter % (SIZE / 2)] = v;
  }
}

int main() {
  // zainicjalizuj UART
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  // zainicjalizuj ADC
  adc_init();
  SMCR |= _BV(SM0); // Set sleep mode ADC noise reduction
  float no_red[SIZE / 2];
  ADCSRA |= _BV(ADSC); // wykonaj konwersję
  while (!(ADCSRA & _BV(ADIF)))
    ;                  // czekaj na wynik
  ADCSRA |= _BV(ADIF); // wyczyść bit ADIF (pisząc 1!)
  // first rubbish output
  while (1) {

    // mierz napięcie
    if (counter < (SIZE / 2)) {
      cli();
      ADCSRA |= _BV(ADSC); // wykonaj konwersję
      while (!(ADCSRA & _BV(ADIF))); // czekaj na wynik
      ADCSRA |= _BV(ADIF); // wyczyść bit ADIF (pisząc 1!)
      v = (1024.0 * 1.1) / ADC;
      no_red[counter] = v;

    } else if (counter >= (SIZE / 2)) {

      sei();
      SMCR |= _BV(SE); // Sleep mode
      sleep_mode();
      SMCR &= ~_BV(SE);
    }
    counter++;
    counter %= SIZE + 1;
    if (counter == SIZE / 2) {
      float average = 0;
      for (int i = 0; i < SIZE / 2; i++) {
        average += no_red[i];
      }
      average /= (SIZE / 2);
      float variance = 0;
      for (int i = 0; i < SIZE / 2; i++) {
        int temp = no_red[i] - average;
        variance += (temp * temp);
      }
      variance /= (SIZE / 2);
      printf("Wariancja bez noise reduction: \t%f\r\n", variance);
      _delay_ms(100);
    }
    _delay_ms(25);
  }
}

