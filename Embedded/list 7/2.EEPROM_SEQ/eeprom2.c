#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include "i2c.h"

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

const uint8_t eeprom_addr = 0xa0;


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
    char command[20]={0};
  while(1) {
    scanf("%s",&command);
    if(!strcmp("read",command))
    {
        uint8_t length = 0;
        uint8_t checksum = 0;
        scanf("%"SCNu16,&addr);
        addr &= 0x1ff;
        checksum+=addr+(addr>>8);
        scanf("%"SCNu8,&length);
        printf("read %"PRIu16" %"PRIu8"\r\n", addr, length);
        checksum+=length;
        uint8_t i = 0;
        printf(":LLAAAATTNN...NNCC\r\n");
        printf(":%.2x%.2x%.2x00", length, eeprom_addr, ((addr & 0x100) >> 7));
        i2cStart();
        i2cCheck(0x08, "I2C start")
        i2cSend(eeprom_addr | ((addr & 0x100) >> 7));
        i2cCheck(0x18, "I2C EEPROM write request")
        i2cSend(addr & 0xff);
        i2cCheck(0x28, "I2C EEPROM set address")

        i2cStart();
        i2cCheck(0x10, "I2C start")
        i2cSend(eeprom_addr | 0x1 | ((addr & 0x100) >> 7));
        i2cCheck(0x40, "I2C EEPROM read request")
            while (i<length)
            {
            uint8_t data = 0;
            if(i==length){
                data = i2cReadNoAck();
                i2cCheck(0x58, "I2C EEPROM read")

            }
            else
            {
                data = i2cReadAck();
               i2cCheck(0x50, "I2C EEPROM read")
            }
            printf("%.2x", data);
            checksum+=data;
            i++;

        }
            i2cStop();
            i2cCheck(0xf8, "I2C stop")
            printf("%x\n\r",checksum);
    }
    else if(!strcmp("write",command))
    {

        uint8_t length = 20;
        uint8_t i =0;
        scanf("%"SCNu16,&addr);
        while(length>i){
            printf("L:%"PRIu8", I:%"PRIu8"\n\r",length, i);
            printf("ADDR:%"PRIu16"\n\r",(addr & 0x100) >> 7);
            addr &= 0x1ff;
            uint8_t rest_of_page = 0x10 - (addr & 0xF); //%16
            printf("ROP:%"PRIu8"\n\r",rest_of_page);
            i2cStart();
            i2cCheck(0x08, "I2C start")
            i2cSend(eeprom_addr | ((addr & 0x100) >> 7));
            i2cCheck(0x18, "I2C EEPROM write request")
            i2cSend(addr & 0xff);
            i2cCheck(0x28, "I2C EEPROM set address")
            uint8_t n = 0;
            uint8_t data = 0;
            while (n<rest_of_page && length>i) {
                scanf("%"SCNu8,&data);
                i2cSend(data);
                i2cCheck(0x28, "I2C EEPROM send data")
                printf("write %"PRIu16" %"PRIu8"\r\n",addr+n,data);
                n++;
                i++;
            }
            addr +=n;
            i2cStop();
            i2cCheck(0xf8, "I2C stop")
        }
    }
    else{
    printf("Unknown command: \"%s\"\n\r",command);
    }

  }
}


