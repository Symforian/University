#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#define BTN_DDR DDRD
#define BTN_PORT PORTD
#define BTN PD2
#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem
void io_init()
{
  // ustaw pull-up na PD2 (INT0 )
  BTN_PORT |= _BV(BTN);

  // ustaw wyzwalanie przerwania na INT0 zboczem narastającym
  EICRA |= _BV(ISC00) | _BV(ISC01);
  // odmaskuj przerwania dla INT0 
  EIMSK |= _BV(INT0);
}

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
// inicjalizacja ADC
void adc_init()
{
  ADMUX   = _BV(REFS0); // referencja AVcc, wejście ADC0
  DIDR0   = _BV(ADC0D); // wyłącz wejście cyfrowe na ADC0
  // częstotliwość zegara ADC 125 kHz (16 MHz / 128)
  ADCSRA  = _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2); // preskaler 128 
  ADCSRA |= _BV(ADIE); // ADC interrupt enable
  ADCSRA |= _BV(ADATE); // auto trigger adc
  ADCSRB = _BV(ADTS1); // source of auto trigger int0
  ADCSRA |= _BV(ADEN); // włącz ADC

}
volatile float v = 0;
ISR(ADC_vect) {
  ADCSRA |= _BV(ADIF);
            // weź zmierzoną wartość (0..1023)
  v = (ADC*5.0)/1023.0;
  v = 10000.0*((5.0/v) -1.0);
}
// Vout = (Vs x R2)/(R1 + R2)
// R1 = R2(Vs/Vout -1)
ISR(INT0_vect) {
  //ADCSRA |= _BV(ADSC); // wykonaj konwersję

}
FILE uart_file;
int main()//
{  
  // inicjalizacja INT0 i pullupa w przycisku                        
  io_init();
  // zainicjalizuj UART     
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  adc_init();
  sei();
    while(1){
    printf("%f\r\n", v);
    _delay_ms(100);
    }
}


