#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>
#include "i2c.h"
#include <stdlib.h>
#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem
#define SEC 0
#define DAY 4
#define NO_COMMAND 0
#define DATE 1
#define TIME 2
#define SET 4
#define SET_DATE 8
#define SET_TIME 16
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

const uint8_t clock_addr = 0xd0;

int main()
{
  // zainicjalizuj UART
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  // zainicjalizuj I2C
  i2cInit();
  // program testowy
  uint16_t addr = 0;
  #define i2cCheck(code, msg) \
    if ((TWSR & 0xf8) != (code)) { \
      printf(msg " failed, status: %.2x\r\n", TWSR & 0xf8); \
      i2cReset(); \
      continue; \
    }
    uint8_t request;
    uint8_t c =0;
    char command[20]={0};
  while(1) {
    scanf("%s",&command);
    if(!strcmp("date",command))
    {
        if(c == SET) c = SET_DATE;
        else c = DATE;
        request = DAY;
        printf("date\r\n");
    }
    else if(!strcmp("time",command))
    { 
        if(c == SET) c = SET_TIME;
        else c = TIME;
        request = SEC;
        printf("time\r\n");
    }
    else if(!strcmp("set",command))
    {
        c = SET;
        printf("set ");
    }
    else{
        c = NO_COMMAND;
        printf("Unknown command: \"%s\"\n\r",command);
    }
    if(c == TIME || c == DATE){

        uint8_t data[3];
        i2cStart();
        i2cCheck(0x08, "I2C start")
        i2cSend(clock_addr | ((addr & 0x100) >> 7));
        i2cCheck(0x18, "I2C write request")
        i2cSend(request);
        i2cCheck(0x28, "I2C set address")

        i2cStart();
        i2cCheck(0x10, "I2C start")
        i2cSend(clock_addr | 0x1 | ((addr & 0x100) >> 7));
        i2cCheck(0x40, "I2C read request")
        for (uint8_t i = 0; i < 2; i += 1)
        {
                data[i] = i2cReadAck();
                i2cCheck(0x50, "I2C read")
        }
        data[2] = i2cReadNoAck();
        i2cCheck(0x58, "I2C read")
        i2cStop();
        i2cCheck(0xf8, "I2C stop")
        if(c==DATE){
            printf("%.2x-%.2x-%.2d%.2x\r\n",data[0],data[1]&0x7F, ((data[1]&0x80) != 0)?21:20,data[2]);
        }
        else if(c==TIME){
            printf("%.2x:%.2x:%.2x\r\n",data[2],data[1],data[0]);
        }
        c = NO_COMMAND;
    }       
    else if(c == SET_TIME || c == SET_DATE){
        char separator = '-';
        if(c == SET_TIME) separator = ':';
        char * pEnd;
        char input[2];
        uint8_t data[3];
        for (uint8_t i = 0;i < 2;i += 1)
        {
            scanf("%2s",&input);
            data[i] = strtol(input,&pEnd,16);
            printf("%.2x",data[i]);
            scanf("%1s",&input);
            if(input[0]!=separator){c = NO_COMMAND; printf("Wrong format!\r\n"); continue;}
            printf("%c",separator);
        }
        if(c == SET_DATE)
        {
            scanf("%2s",&input);  
            data[1] |= input[1]<<7; 
            printf("%.2x",strtol(input,&pEnd,16));
        }
        scanf("%2s",&input);
        data[2] = strtol(input,&pEnd,16);
        printf("%.2x\n\r",data[2]);
        if(c == SET_TIME){
            uint8_t temp = data[0];
            data[0] = data[2];
            data[2] = temp;
        }
        i2cStart();
        i2cCheck(0x08, "I2C start")
        i2cSend(clock_addr | ((addr & 0x100) >> 7));
        i2cCheck(0x18, "I2C write request")
        i2cSend(request);
        i2cCheck(0x28, "I2C set address")
        for (uint8_t i = 0; i < 3; i += 1)
        {
            i2cSend(data[i]);
            i2cCheck(0x28, "I2C send data")
        }
        i2cStop();
        i2cCheck(0xf8, "I2C stop")

        c = NO_COMMAND;
    }
  }
}
