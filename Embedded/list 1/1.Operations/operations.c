#include <avr/io.h>
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

FILE uart_file;

int main()
{
  // zainicjalizuj UART
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  // program
  while(1) {
    // int 8
    int8_t a8 = 1;
    int8_t b8 = 1;

    scanf("%"SCNd8, &a8);
    scanf("%"SCNd8, &b8);
    // 8 + 8
    int8_t result8 = a8+b8;
    printf("int8:\r\n%"PRId8" + %"PRId8" = %"PRId8"\r\n", a8,b8,result8);
    // 8 * 8
    result8 = a8*b8;
    printf("%"PRId8" * %"PRId8" = %"PRId8"\r\n", a8,b8,result8);
    // 8 / 8
    result8 = a8/b8;
    printf("%"PRId8" / %"PRId8" = %"PRId8"\r\n", a8,b8,result8);

    //int 16
    int16_t a16 = 1;
    int16_t b16 = 1;

    scanf("%"SCNd16, &a16);
    scanf("%"SCNd16, &b16);
    // 16 + 16
    int16_t r16 = a16+b16; 
    printf("int16:\r\n%"PRId16" + %"PRId16" = %"PRId16"\r\n", a16,b16,r16);
    // 16 * 16
    r16 = a16*b16;
    printf("%"PRId16" * %"PRId16" = %"PRId16"\r\n", a16,b16,r16);
    // 16/16
    r16 = a16/b16;
    printf("%"PRId16" / %"PRId16" = %"PRId16"\r\n", a16,b16,r16);

    // int 32
    int32_t a32 = 1;
    int32_t b32 = 1;

    scanf("%"SCNd32, &a32);
    scanf("%"SCNd32, &b32);
    // 32+32
    int32_t r32 = a32+b32;
    printf("int32:\r\n%"PRId32" + %"PRId32" = %"PRId32"\r\n", a32,b32,r32);
    // 32 * 32
    r32 = a32 * b32;
    printf("%"PRId32" * %"PRId32" = %"PRId32"\r\n", a32,b32,r32);
    // 32/32
    r32 = a32/b32;
    printf("%"PRId32" / %"PRId32" = %"PRId32"\r\n", a32,b32,r32);

    // int 64
    int64_t a64 = 1;
    int64_t b64 = 1;

    scanf("%ld" , &a64);
    scanf("%ld", &b64);
    // 64+ 64
    int64_t r64 = a64+b64;
    printf("a = %ld, b = %ld\r\n",a64,b64);
    printf("int64 wyniki:\r\n%ld \r\n", r64);
    // 64 * 64
    r64 = a64 * b64;
    printf("%ld \r\n",r64);
    // 64/ 64
    r64 = a64 / b64;
    printf("%ld \r\n", r64);

    // float 
    float af = 1;
    float bf = 1;
    
    scanf("%f", &af);
    scanf("%f", &bf);
    // f + f
    float f = af+bf;
    printf("float:\r\n%f + %f = %f \r\n", af,bf,f);
    // f*f
    f = af * bf;
    printf("%f * %f = %f \r\n", af,bf,f);
    // f/f
    f = af/bf;
    printf("%f / %f = %f \r\n", af,bf,f);
    
    
    

  }
}


