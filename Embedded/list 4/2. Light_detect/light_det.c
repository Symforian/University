#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#define LED_DDR DDRB
#define LED_PORT PORTB
#define LED PB1
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
void timer1_init()
{
  // ustaw tryb licznika
  // COM1A = 10   -- non-inverting mode
  // WGM1  = 1110 -- fast PWM top=ICR1
  // CS1   = 001  -- prescaler 1
  // ICR1  = 1023
  // częstotliwość 16e6/(1*(1+1023)) = 1 Hz
  // wzór: datasheet 20.12.3 str. 164
  ICR1 = 1999;
  TCCR1A = _BV(COM1A1) | _BV(WGM11);
  TCCR1B = _BV(WGM12) | _BV(WGM13) | _BV(CS10);
  // ustaw pin OC1A (PB1) jako wyjście
  DDRB |= _BV(PB1);
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
FILE uart_file;
int main()//
{                           //   {512,128,96,64,38,28,20,14,12,8,7,6,5,3,2,1};
    uint16_t const times[16] = {0,1,9,15,20,30,50,70,90,125,150,200,300,400,600,1500};
  // zainicjalizuj UART       //0 1 2 3 4 5 6  7  8  9 10 11 12 13 14  15
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  // uruchom licznik
  timer1_init();
  adc_init();
  // ustaw wypełnienie 50%
  //OCR1A = ICR1/2;
    while(1){
    ADCSRA |= _BV(ADSC); // wykonaj konwersję
LED_PORT &= ~_BV(LED);
    while (!(ADCSRA & _BV(ADIF))); // czekaj na wynik
    ADCSRA |= _BV(ADIF); // wyczyść bit ADIF (pisząc 1!)
    uint16_t v = ADC; // weź zmierzoną wartość (0..1023)
    printf("Odczytano: %"PRIu16"\r\n", v>>6);
 //   printf("Odczytano: %"PRIu16"\r\n", times[v>>6]);
    ICR1 = times[v>>6];
    }
}


