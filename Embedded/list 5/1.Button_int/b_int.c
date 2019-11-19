#include <avr/interrupt.h>
#include <avr/io.h> /* Defines pins, ports, etc */
#include <avr/sleep.h>
#include <inttypes.h>
#include <stdio.h>
#include <util/delay.h>
#define DEBOUNCE_TIME 1000 /* microseconds */

#define LED PB5
#define LED_DDR DDRB
#define LED_PORT PORTB

#define BTN PD2
#define BTN_PIN PIND
#define BTN_PORT PORTD

void init() {
  // ustaw pull-up na PD2 (INT0 )
  BTN_PORT |= _BV(BTN);
  // ustaw wyjście na PB5
  LED_DDR |= _BV(LED);
}
// inicjalizacja licznika 2
void timer2_init() {
  // ustaw tryb licznika
  // COM1A = 10 -- clear on match set on bottom
  // WGM2  = 111 --  normal=0xOCRA
  // CS2   = 111  -- prescaler 1024
  // ICR1  = 624
  // częstotliwość 16e6/(256*1024) = 61 Hz
  // wzór: datasheet 20.12.3 str. 164
  // preskaler 256 
  TCCR2B = _BV(CS20) | _BV(CS21) | _BV(CS22) ;
  //OCR2A = 61;
  // odmaskowanie przerwania przepełnienia licznika | _BV(WGM22)
  TIMSK2 |= _BV(TOIE2);
}
volatile uint8_t reader = 0;
volatile uint8_t counter = 0;
volatile uint8_t buffor[62] = {0};
volatile uint8_t time = 61;
// procedura obsługi przerwania przepełnienia licznika
ISR(TIMER2_OVF_vect) {
  counter++;
  counter %= 62;
  buffor[counter] = bit_is_clear(BTN_PIN, BTN);
  if (time > 0 && counter >= time) {
    time = 0;
  }
  if (time == 0) {
    if (buffor[reader])
      LED_PORT |= _BV(LED);
    else
      LED_PORT &= ~_BV(LED);
    reader++;
    reader %= 62;
  }
}

int main() {
  // zainicjalizuj wejścia/wyjścia
  init();
  timer2_init();
  // ustaw tryb uśpienia na tryb bezczynności
  set_sleep_mode(SLEEP_MODE_IDLE);
  // odmaskuj przerwania
  sei();
  // program testowy
  while (1) {
    sleep_mode();
  }
}

