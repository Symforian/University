#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#define LED PB5
#define LED_PORT PORTB
#define LED_DDR DDRB
#define LED_IR PB1
#define DET PB0
#define IR_DDR DDRB
#define IR_PORT PORTB
#define IR_PIN PINB
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
  // WGM1  = 10 -- fast pwm top=OCR1
  // CS1   = 001  -- prescaler 1
  // ICR1  = 15624
  // częstotliwość 16e6/(1024*(1+15624)) = 1 Hz
  // wzór: datasheet 20.12.3 str. 164
  //16e6/(8*(1+51)) ~  384000 Hz
  //16e6/(1*(1+421)) ~ 37914.69194 Hz
  ICR1 = 421;
  TCCR1A = _BV(COM1A1) | _BV(WGM11);
  TCCR1B = _BV(CS10) | _BV(WGM12) | _BV(WGM13);
  // ustaw pin OC0A (PB0) jako wyjście
  //IR_DDR |= _BV(LED_IR);
}
FILE uart_file;
int main()
{
  timer1_init();
uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
    IR_DDR |= _BV(LED_IR);
    LED_DDR  |= _BV(LED);
    IR_DDR &= ~_BV(DET);
    IR_PORT |= _BV(DET);
  // uruchom licznik

    while(1){
        OCR1A = ICR1/4;
        if(IR_PIN & _BV(DET))
            LED_PORT &= ~_BV(LED);
        else
            LED_PORT |= _BV(LED);



    }
}


