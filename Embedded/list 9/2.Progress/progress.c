#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <inttypes.h>
#include "hd44780.h"


int hd44780_transmit(char data, FILE *stream)
{
  LCD_WriteData(data);
  return 0;
}

FILE hd44780_file;
int main()
{
  // skonfiguruj wyświetlacz
  LCD_Initialize();
  LCD_Clear();
  // skonfiguruj strumienie wyjściowe
  fdev_setup_stream(&hd44780_file, hd44780_transmit, NULL, _FDEV_SETUP_WRITE);
  stdout = stderr = &hd44780_file;
                    //   |data |
  uint8_t b = 0x10; // 00010000
  uint8_t offset = 0;

  for (uint8_t i = 0; i < 5; i += 1)
  {
    LCD_WriteCommand(HD44780_CGRAM_SET | offset);
    for (uint8_t j = 0; j < 8; j += 1)
    {
        LCD_WriteData(b);
    }
    b|=(b>>1);
    offset+=8;
  }
  uint8_t i = 0;
  char states[6] = {' ',0,1,2,3,4};

  while(1) {
    for (i = 0; i < 16; i += 1)
    {
        for (uint8_t j = 0; j < 6; j += 1)
        {
            LCD_GoTo(i, 0);
            printf("%c", states[j]);
            _delay_ms(500);        
        }
        _delay_ms(500);
    }
    LCD_Clear(); 
  }
}


