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
  // włącz przerwania 
  UCSR0B |= _BV(RXCIE0);
  // ustaw format 8n1
  UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);
}



// procedura obsługi przerwania odczytu
ISR(USART_RX_vect) {

  uint8_t value = UDR0;
  UDR0=value;
}

int main() {
  uart_init();
  // ustaw tryb uśpienia na tryb bezczynności
  set_sleep_mode(SLEEP_MODE_IDLE);
  // odmaskuj przerwania
  sei();
  while (1) {
    sleep_mode();
  }
}

