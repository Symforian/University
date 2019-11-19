#include <avr/interrupt.h>
#include <avr/io.h> /* Defines pins, ports, etc */
#include <avr/sleep.h>
#include <inttypes.h>
#include <stdio.h>
#include <util/delay.h>
#define BAUD 9600                            // baudrate
#define UBRR_VALUE ((F_CPU) / 16 / (BAUD)-1) // zgodnie ze wzorem

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

// oczekiwanie na zakończenie transmisji
void uart_wait()
{
  while(!(UCSR0A & _BV(TXC0)));
}

// odczyt jednego znaku
int uart_receive(FILE *stream) {
  // czekaj aż znak dostępny
  while (!(UCSR0A & _BV(RXC0)))
    ;
  return UDR0;
}

// inicjalizacja licznika 1
void timer1_init() {
  TCCR1B = _BV(CS10);
  TIMSK1 |= _BV(ICIE1); // Enable input capture flag
}
void timer2_init() {
  // ustaw tryb licznika
  // WGM2  = 0 --  normal
  // CS2   = 111  -- prescaler 1024
  // TOP = 0xFF
  // częstotliwość 16e6/(256*1024) = 61Hz
  TCCR2B = _BV(CS20) | _BV(CS21) | _BV(CS22);
  TIMSK2 |= _BV(TOIE2); //Enable overflow flag
}
FILE uart_file;
// procedura obsługi przerwania przepełnienia licznika
volatile uint32_t counter = 0;
volatile uint32_t sixty_first = 0;
ISR(TIMER2_OVF_vect) {
    sixty_first++;
    if (sixty_first==61){
    printf("%"PRIu32"Hz\r\n",counter);
    uart_wait();
    counter=0;
    sixty_first=0;
    }
    
}
ISR(TIMER1_CAPT_vect) {  
    counter++;
}

int main() {

  PORTB |= _BV(PB0);
  // zainicjalizuj UART
  uart_init();
  timer1_init();
  timer2_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  // ustaw tryb uśpienia na tryb bezczynności
  set_sleep_mode(SLEEP_MODE_IDLE);
  // odmaskuj przerwania
  sei();
  // program testowy
  while (1) {
    sleep_mode();

  }
}

