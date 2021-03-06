#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <stdio.h>
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
// inicjalizacja ADC
void adc_init()
{
  ADMUX   = _BV(REFS0); // referencja AVcc, wejście ADC0
  DIDR0   = _BV(ADC0D) | _BV(ADC1D); // wyłącz wejście cyfrowe na ADC0
  // częstotliwość zegara ADC 125 kHz (16 MHz / 128)
  ADCSRA  = _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2); // preskaler 128
  // adc interrupt enable
  ADCSRA |= _BV(ADIE);
  ADCSRA |= _BV(ADEN); // włącz ADC
}

void timer1_init()
{
  // PWM 500Hz - 1kHz
  // ustaw tryb licznika
  // COM1A = 10   -- non-inverting mode
  // WGM1  = 1000 -- Phase and Frequency Correct PWM Mode top=ICR1
  // CS1   = 100  -- prescaler 256
  // ICR1  = 60
  // częstotliwość 16e6/(256*2*60) = 520 Hz
  ICR1 = 60;
  OCR1A = ICR1/2;
  TCCR1A = _BV(COM1A1);
  TCCR1B = _BV(WGM13)| _BV(CS12);;
  // enable capture and overflow interrupts
  TIMSK1 |= _BV(ICIE1) | _BV(TOIE1);
  // ustaw pin OC1A (PB1) jako wyjście
  DDRB |= _BV(PB1);
}
uint16_t const width[16] = {3, 7, 11, 15, 18, 22, 26, 30, 33, 37, 41, 45, 48, 52, 56, 60};
volatile uint16_t v = 0;
volatile uint8_t flag = 0;
volatile uint8_t flag_pot = 0;
volatile uint16_t value_cap = 0;
volatile uint16_t value_ovf = 0;
//Timer/Counter1 Overflow
ISR(TIMER1_OVF_vect) {
    flag = 0;
    ADCSRA |= _BV(ADSC); // wykonaj konwersję
}
//Timer/Counter1 Capture Event
ISR(TIMER1_CAPT_vect) {
    flag = 1;
    ADCSRA |= _BV(ADSC);// wykonaj konwersję

}
ISR(ADC_vect) {
    v = ADC; // weź zmierzoną wartość (0..1023)
    ADMUX &= ~_BV(MUX0);
    if(flag == 0){
      value_ovf = v;
      flag = 2;
      ADCSRA |= _BV(ADSC); // wykonaj konwersję
    }
    else if (flag == 1){
      value_cap = v;
      flag = 2;
      ADCSRA |= _BV(ADSC); // wykonaj konwersję
    }
    else if(flag == 2){
      OCR1A = width[v>>6];
      ADMUX |= _BV(MUX0);
      flag  = 3;
    }


}
FILE uart_file;
int main()
{
  // zainicjalizuj UART     
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  // inicjalizacja adc
  adc_init();
  // Set sleep mode Idle
  SMCR = 0; 
  // uruchom licznik
  timer1_init();
  sei();
  while(1)
  {
    // ustaw wypełnienie
    SMCR |= _BV(SE); 
    printf("capt:%"PRIu32"mV\tovfl:%"PRIu32"mV\r\n",(uint32_t)(value_cap *(5000.0/1024.0)), (uint32_t)(value_ovf *(5000.0/1024.0)));
    //printf("%"PRIu16"mV\r\n",v);
    //_delay_ms(15);
  }
}


