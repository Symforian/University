#include <avr/interrupt.h>
#include <avr/io.h> /* Defines pins, ports, etc */
#include <avr/sleep.h>
#include <inttypes.h>
#include <stdio.h>
#include <util/delay.h>

#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem
#define SIZE 20
// inicjalizacja UART
void uart_init()
{
  // ustaw baudrate
  UBRR0 = UBRR_VALUE;
  // wyczyść rejestr UCSR0A
  UCSR0A = 0;
  // włącz odbiornik i nadajnik
  UCSR0B = _BV(RXEN0) | _BV(TXEN0);
  // enable rx int        tx int        dre int 
  UCSR0B |= _BV(RXCIE0) | _BV(TXCIE0) | _BV(UDRIE0);
  // ustaw format 8n1
  UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);
}

volatile char rbuff[SIZE]={};
volatile char tbuff[SIZE]={};
volatile uint8_t ri_r=0, ti_r=0, ri_w=0, ti_w=0;
volatile uint8_t rs=0, ts=0;
FILE uart_file;

// transmisja jednego znaku
int uart_transmit(char data, FILE *stream)
{
    if (ts != SIZE-1){
    tbuff[ti_w] = data;
    ti_w++;
    if(ti_w==SIZE) {ti_w=0;}
    ts++;
    }
    else{
      // czekaj aż transmiter gotowy
      while(!(UCSR0A & _BV(UDRE0)));
      tbuff[ti_w] = data;
      ti_w++;
      if(ti_w==SIZE) {ti_w=0;}
      ts++;
      return 0;
  }
    return 0;
}
// odczyt jednego znaku
int uart_receive(FILE *stream)
{
    if (rs == 0){
      // czekaj aż znak dostępny 
      while(!(UCSR0A & _BV(RXC0)));

      return UDR0;
  } else {
    int t = ri_r;
    ri_r++;
    if(ri_r==SIZE){ri_r=0;}
    rs--;
    return rbuff[t];
    
    }

}
//Rx complete
ISR(USART_RX_vect){
    if(rs>0){

    rbuff[ri_w] = UDR0;
    ri_w++;
    if(ri_w==SIZE) {ri_w=0;}
    rs++;
    }
}
//Data register empty
ISR(USART_UDRE_vect){
    if (ts>0){
        UDR0 = tbuff[ti_r];
    ti_r++;
    if(ti_r==SIZE){ti_r=0;}
    ts--;
    }
}
//Tx complete
ISR(USART_TX_vect){
    if (ts>0){
    ti_r++;
    if(ti_r==SIZE){ti_r=0;}
    ts--;
    }
}


int main()
{
  // zainicjalizuj UART
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  // program testowy
  // odmaskuj przerwania
  sei();
  printf("Hello world!\r\n");
  printf("Hello world!\r\n");
  printf("Hello world!\r\n");
  printf("Hello world!\r\n");

    int16_t a = 1;
  while(1) {
    printf("Odczytano: %"PRId16"\r\n", a);
      scanf("%"SCNd16, &a);
  }
}


