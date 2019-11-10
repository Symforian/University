#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <inttypes.h>

#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem

// inicjalizacja UART
void uart_init()
{
  // ustaw baudrate
  UBRR0 = UBRR_VALUE;
  // wyczyść rejestr UCSR0A
  UCSR0A = 0;
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
  // WGM1  = 0000 -- normal
  // CS1   = 001  -- prescaler 1
  TCCR1B = _BV(CS10);
}
FILE uart_file;

int main()
{
  // zainicjalizuj UART
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  // zainicjalizuj licznik
  timer1_init();
  // program
    volatile uint16_t t0, t1;
  //while(1) {
    // int 8

    volatile int8_t a8 = 30;
    volatile int8_t b8 = 15;
    volatile int8_t result8;
    t0 =  TCNT1;
    // 8 + 8
    result8 = a8+b8;
    //--
    t1 = TCNT1;
    printf("int8 +: %"PRId16"\r\n",t1 - t0);
    t0 =  TCNT1;
    // 8 * 8
    result8 = a8*b8;
    //--
    t1 = TCNT1;
    printf("int8 *: %"PRId16"\r\n",t1 - t0);
    t0 =  TCNT1;
    // 8 / 8
    result8 = a8/b8;
    //--
    t1 = TCNT1;
    printf("int8 /:%"PRId16"\r\n",t1 - t0);
    _delay_ms(1000);

    //int 16
    volatile int16_t a16 = 521;
    volatile int16_t b16 = 123;
    volatile int16_t r16;
    t0 =  TCNT1;
    // 16 + 16
    r16 = a16+b16; 
    //--
    t1 =  TCNT1;
    printf("int16 +: %"PRId16"\r\n",t1 - t0);
    t0 =  TCNT1;
    // 16 * 16
    r16 = a16*b16;
    //--    
    t1 =  TCNT1;
    printf("int16 *: %"PRId16"\r\n",t1 - t0);
    t0 =  TCNT1;
    // 16/16
    r16 = a16/b16;
    //--    
    t1 =  TCNT1;
    printf("int16 /: %"PRId16"\r\n",t1 - t0);
    _delay_ms(1000);

    // int 32
    volatile int32_t a32 = 33321;
    volatile int32_t b32 = 121;
    volatile int32_t r32;
    t0 =  TCNT1;
    // 32+32
    r32 = a32+b32;
    //--
    t1 =  TCNT1;
    printf("int32 +: %"PRId16"\r\n",t1 - t0);
    t0 =  TCNT1;
    // 32 * 32
    r32 = a32 * b32;
    //--
    t1 =  TCNT1;
    printf("int32 *: %"PRId16"\r\n",t1 - t0);
    t0 =  TCNT1;
    // 32/32
    r32 = a32/b32;
    //--
    t1 =  TCNT1;
    printf("int32 /: %"PRId16"\r\n",t1 - t0);
    _delay_ms(1000);

    // int 64
    volatile int64_t a64 = 765321;
    volatile int64_t b64 = 1231;
    volatile int64_t r64;
    t0 =  TCNT1;
    // 64+ 64
    r64 = a64+b64;
    //--
    t1 =  TCNT1;
    printf("int64 +: %"PRId16"\r\n",t1 - t0);
    t0 =  TCNT1;
    // 64 * 64
    r64 = a64 * b64;
    //--
    t1 =  TCNT1;
    printf("int64 *: %"PRId16"\r\n",t1 - t0);
    t0 =  TCNT1;
    // 64/ 64
    r64 = a64 / b64;
    //--
    t1 =  TCNT1;
    printf("int64 /: %"PRId16"\r\n",t1 - t0);
    _delay_ms(1000);

    // float 
    volatile float af = 14.6;
    volatile float bf = 123.3;
    volatile float f;
    t0 =  TCNT1;
    // f + f
    f = af+bf;
    //--
    t1 =  TCNT1;
    printf("float +: %"PRId16"\r\n",t1 - t0);
    t0 =  TCNT1;
    // f*f
    f = af * bf;
    //--
    t1 =  TCNT1;
    printf("float *: %"PRId16"\r\n",t1 - t0);
    t0 =  TCNT1;
    // f/f
    f = af/bf;
    //--
    t1 =  TCNT1;
    printf("float /: %"PRId16"\r\n",t1 - t0);
    _delay_ms(1000);
  
}


