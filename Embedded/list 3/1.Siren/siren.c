#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include "pitches.h"
#define BUZZ PB5
#define BUZZ_DDR DDRB
#define BUZZ_PORT PORTB

#define TONE(step, delay) \
    for (uint16_t i = 0; i < (uint32_t)1000 * (delay) / (step) / 2; i++) { \
      BUZZ_PORT |= _BV(BUZZ); \
      _delay_us(step); \
      BUZZ_PORT &= ~_BV(BUZZ); \
      _delay_us(step); \
    } 

int main() {
  // Inits
  static const uint16_t notes[] PROGMEM = {
NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_FS5,
NOTE_G5, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_A5,
NOTE_B5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_G5,
NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_G5, NOTE_D5,
0, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5,
NOTE_FS5, NOTE_G5, NOTE_G5, NOTE_FS5, NOTE_G5,
NOTE_A5, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_G5,
NOTE_G5, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_G5,
NOTE_D5, 0,NOTE_G5, NOTE_A5, NOTE_D5,
NOTE_D4, NOTE_C4, NOTE_B5, NOTE_A5, NOTE_B5,
NOTE_C4, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_FS5,
NOTE_G5, NOTE_FS5, NOTE_D5, 0,
NOTE_G5, NOTE_A5, NOTE_D5, NOTE_D4, NOTE_C4,
NOTE_B5, NOTE_A5, NOTE_B5, NOTE_C4, NOTE_B5,
NOTE_A5, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_FS5,
NOTE_G5, NOTE_A5, NOTE_B5, NOTE_A5, NOTE_G5,
0
 };
  static const uint16_t noteDiv[] PROGMEM = {
1000, 250, 500, 500, 500, 
1250, 500, 750, 1250, 750,
1500, 1500, 1000, 250, 500,
 500, 500, 1500, 500, 2000,
250, 1000, 250, 500, 500, 
500, 1250, 500, 750, 1250,
750, 1500, 1500, 1000, 250,
500, 500, 500, 1500, 500,
2000, 500, 1750, 1250, 250, 
1250, 500, 500, 1250, 500,
500, 1500, 1000, 250, 500, 
1000, 250, 1500, 500,
1750, 1250, 250, 1250, 500, 
500, 1250, 500, 500, 1500,
1000, 250, 500, 1000, 250, 
1000, 750, 1500, 1500, 3000,
5000
}; 
  BUZZ_DDR |= _BV(BUZZ);
  while (1) {

   for(int n = 0; n < 80; n++){
        uint16_t delay = pgm_read_word(&noteDiv[n]);
        uint16_t step = pgm_read_word(&notes[n]);
        if(step == 0) {
            while(delay>0) {
            _delay_ms(1); delay--;}
            continue;
            }
        for (uint16_t i = 0; i <  2*delay/3; i++) { 
          step = pgm_read_word(&notes[n]);
          BUZZ_PORT |= _BV(BUZZ);   
           while(step >0){
          _delay_us(1);
            step--;
            } 

          step = pgm_read_word(&notes[n]);
            BUZZ_PORT &= ~_BV(BUZZ); 
           while(step >0){
          _delay_us(1);
            step--;
            }          
        } 
        _delay_ms(10);
    }


    } //while end
}
  
/*
TONE(NOTE_G5, 1000);
_delay_ms(10);
TONE(NOTE_G5, 250);
_delay_ms(10);
TONE(NOTE_G5, 500);
_delay_ms(10);
TONE(NOTE_G5, 500);
_delay_ms(10);
TONE(NOTE_FS5, 500);
_delay_ms(10);
TONE(NOTE_G5,1500);//28
_delay_ms(10);
// ggggf#g
TONE(NOTE_G5, 500);//14
_delay_ms(10);
TONE(NOTE_FS5, 750);
_delay_ms(10);
TONE(NOTE_G5,1500);//27
_delay_ms(10);

TONE(NOTE_A5, 750);//16
_delay_ms(10);
TONE(NOTE_F5, 1500);//26
_delay_ms(10);
TONE(NOTE_A5,1500);//27
_delay_ms(10);


TONE(NOTE_G5, 1000);//24
_delay_ms(10);
TONE(NOTE_G5, 500);//9
_delay_ms(10);
TONE(NOTE_G5, 750);//17
_delay_ms(10);
TONE(NOTE_G5, 750);//16
_delay_ms(10);
TONE(NOTE_FS5, 750);
_delay_ms(10);
TONE(NOTE_G5, 1750);//35
_delay_ms(10);
TONE(NOTE_G5, 750);//15
_delay_ms(10);
TONE(NOTE_D5,3000);
_delay_ms(10);
// repeat
TONE(NOTE_G5, 1000);
_delay_ms(10);
TONE(NOTE_G5, 250);
_delay_ms(10);
TONE(NOTE_G5, 500);
_delay_ms(10);
TONE(NOTE_G5, 500);
_delay_ms(10);
TONE(NOTE_FS5, 500);
_delay_ms(10);
TONE(NOTE_G5,1500);//28
_delay_ms(10);
// ggggf#g
TONE(NOTE_G5, 500);//14
_delay_ms(10);
TONE(NOTE_FS5, 750);
_delay_ms(10);
TONE(NOTE_G5,1500);//27
_delay_ms(10);

TONE(NOTE_A5, 750);//16
_delay_ms(10);
TONE(NOTE_F5, 1500);//26
_delay_ms(10);
TONE(NOTE_A5,1500);//27
_delay_ms(10);


TONE(NOTE_G5, 1000);//24
_delay_ms(10);
TONE(NOTE_G5, 500);//9
_delay_ms(10);
TONE(NOTE_G5, 750);//17
_delay_ms(10);
TONE(NOTE_G5, 750);//16
_delay_ms(10);
TONE(NOTE_FS5, 750);
_delay_ms(10);
TONE(NOTE_G5, 1750);//35
_delay_ms(10);
TONE(NOTE_G5, 750);//15
_delay_ms(10);
TONE(NOTE_D5,3000);
_delay_ms(10);

G G G G Fis G
G Fis G
A H A
G G G G Fis G G D

G G G G Fis G
G Fis G
A H A
G G G G Fis G G D/*/

/*G
A
D D^ C H A
H C H
A G Fis G Fis C D*/
/*
TONE(NOTE_G5, 1750);//34
_delay_ms(10);

TONE(NOTE_A5, 1250);
_delay_ms(10);

TONE(NOTE_D5,250);
_delay_ms(10);
TONE(NOTE_D5,1250);//25
_delay_ms(10);
TONE(NOTE_C5,500);//12
_delay_ms(10);
TONE(NOTE_FS5,500);//12
_delay_ms(10);
TONE(NOTE_A5,1250);//28
_delay_ms(10);

TONE(NOTE_FS5,500);//12
_delay_ms(10);
TONE(NOTE_C5,500);//12
_delay_ms(10);
TONE(NOTE_FS5,1500);//32
_delay_ms(10);

//^ G A DDCHA HCH 

TONE(NOTE_A5,1000);//22
_delay_ms(10);
TONE(NOTE_G5,250);//6
_delay_ms(10);
TONE(NOTE_FS5,500);//12
_delay_ms(10);
TONE(NOTE_G5,1000);//28
_delay_ms(10);
TONE(NOTE_FS5,250);//`15
_delay_ms(10);
TONE(NOTE_C5,250);
_delay_ms(10);
TONE(NOTE_D5,250);
_delay_ms(10);
//AGF#GF#CD


TONE(NOTE_G5, 1750);//34
_delay_ms(10);

TONE(NOTE_A5, 1250);
_delay_ms(10);

TONE(NOTE_D5,250);
_delay_ms(10);
TONE(NOTE_D5,1250);//25
_delay_ms(10);
TONE(NOTE_C5,500);//12
_delay_ms(10);
TONE(NOTE_FS5,500);//12
_delay_ms(10);
TONE(NOTE_A5,1250);//28
_delay_ms(10);

TONE(NOTE_FS5,500);//12
_delay_ms(10);
TONE(NOTE_C5,500);//12
_delay_ms(10);
TONE(NOTE_FS5,1500);//32
_delay_ms(10);


TONE(NOTE_A5,1000);//22
_delay_ms(10);
TONE(NOTE_G5,250);//6
_delay_ms(10);
TONE(NOTE_FS5,500);//12
_delay_ms(10);
TONE(NOTE_G5,1000);//28
_delay_ms(10);
TONE(NOTE_E5,250);
_delay_ms(10);
TONE(NOTE_FS5,250);//
_delay_ms(10);
TONE(NOTE_G5,1000);//28
_delay_ms(10);

TONE(NOTE_A5, 750);//16
_delay_ms(10);
TONE(NOTE_F5, 1500);//26
_delay_ms(10);
TONE(NOTE_A5,1500);//27
_delay_ms(10);

TONE(NOTE_G5,3000);//28
_delay_ms(10);*/
//AGF#GEF#GAHAG
