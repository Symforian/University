#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include <time.h>
#define GREEN OCR0A
#define RED OCR0B
#define BLUE OCR2A
void timers_init(){
    // COM1A = 10   -- non-inverting mode
    // WGM1  = 11 -- fast PWM , top=0xFF
    // CS = 001 -- no prescaling
    // Set PB0 - Fast PWM with TOP - mode 7
    TCCR0A |= _BV(COM0A1) | _BV(COM0B1)  | _BV(WGM01) | _BV(WGM00);
    TCCR0B |= _BV(CS00);
   // OCRA = 254;
    // COM2A = 10 -- non inverting mode
    // WGM1 = 1110 fast pwm top icr2
    // cs = 001 -- no prescaling
    TCCR2A |= _BV(COM2A1) | _BV(WGM21) | _BV(WGM20);
    TCCR2B |=  _BV(CS20);


}

void h11_to_rgb(uint16_t h,uint16_t *R,uint16_t *G,uint16_t *B) {

  h = ((h<<7)/60)<<1;
  uint16_t floor_h = h>>8;
  uint16_t fact = h & 0xFF;
  uint16_t q = (1<<8) - fact;


  switch (floor_h) {
    case 0: *R=255; *G=fact; *B=0; break;
    case 1: *R=q; *G=255; *B=0; break;
    case 2: *R=0; *G=255; *B=fact; break;
    case 3: *R=0; *G=q; *B=255; break;
    case 4: *R=fact; *G=0; *B=255; break;
    case 5: *R=255; *G=0; *B=q; break;

  }
}

int main(void)
{
    timers_init();
    DDRD |= _BV(PD5) | _BV(PD6);
    DDRB   |= _BV(PB3);
    const int16_t vals[] = {
	    0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
	    1, 1, 1, 1, 2, 2, 2, 2, 2, 2,
	    2, 2, 2, 3, 3, 3, 3, 3, 3, 3,
        4, 4, 4, 4, 5, 5, 5, 5, 5, 5,
        8, 8, 8, 9, 9, 11, 11, 12, 12,
        13, 13, 15, 15, 16, 17, 17, 18, 19,
        20, 21, 22, 23, 24, 25, 26, 27, 29,
        30, 31, 35, 39, 40, 42, 44, 47, 50,
        53, 57, 61, 65, 69, 74, 79, 84, 89,
        96, 102, 108, 114, 120, 126, 133, 140, 148,
        156, 165, 174, 184, 194, 205, 216, 228, 240, 255,
        -1
    };
    uint16_t R=0,G=0,B=0;
    uint16_t hue;
    int seed;
    time_t tt;
    seed = time(&tt);
    srand(seed);
    while (1)
    {


        hue = (uint16_t)rand()%360;
        h11_to_rgb(hue,&R,&G,&B);
        int dir = 1;
        for(int i=0;;){
        if(i==-1) break;
        if(vals[i] == -1) {dir=-1;i--;}

        GREEN=255-((G*vals[i])>>8);
        RED =255-((R*vals[i])>>8);
        BLUE= 255-((B*vals[i])>>8);
        i+=dir;
        _delay_ms(10);
        }

    }
} 

