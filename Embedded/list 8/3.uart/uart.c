#include "FreeRTOS.h"
#include "task.h"
#include <avr/io.h>
#include <stdio.h>
#include "uart.h"
#include <avr/interrupt.h>
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#ifndef BAUD
#define BAUD 9600
#endif
#include <util/setbaud.h>

int uart_transmit(char c, FILE *stream);
int uart_receive(FILE *stream);
FILE uart_file = FDEV_SETUP_STREAM(uart_transmit, uart_receive, _FDEV_SETUP_RW);

void uart_init() {
  UBRR0H = UBRRH_VALUE;
  UBRR0L = UBRRL_VALUE;
#if USE_2X
  UCSR0A |= _BV(U2X0);
#else
  UCSR0A &= ~(_BV(U2X0));
#endif
  UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); /* 8-bit data */
  UCSR0B = _BV(RXEN0) | _BV(TXEN0); /* Enable RX and TX */
  // enable rx int        dre int 
  UCSR0B |= _BV(RXCIE0) | _BV(UDRIE0);
}

int uart_transmit(char data, FILE *stream) {
    if (uxQueueSpacesAvailable(QueueTransmit)==0){
        while(!(UCSR0A & _BV(UDRE0))) taskYIELD();
    }
    xQueueSend(QueueTransmit,
               &data,
               (TickType_t) 10);
  
    /*UCSR0B |= _BV(UDRIE0);
    if(uxQueueSpacesAvailable(QueueTransmit)==10){
        UCSR0B &= ~_BV(UDRIE0);
    }*/

    return 0;
}

int uart_receive(FILE *stream) {
    if (uxQueueSpacesAvailable(QueueReceive)==0){
      while(!(UCSR0A & _BV(RXC0))) taskYIELD();

      return UDR0;
  } else {
    UCSR0B &= ~_BV(RXCIE0);
    uint8_t t;
    xQueueReceive(
                    QueueReceive,
                    (void*)&t,
                    (TickType_t) 10);//{};
    UCSR0B |= _BV(RXCIE0);    
    return t;
    
    }
}
//Rx complete
ISR(USART_RX_vect){
    BaseType_t HigherPriorityTaskWoken = pdFALSE;
    if(xQueueIsQueueEmptyFromISR(QueueReceive)!=pdFALSE){ 
    xQueueSendFromISR(
                    QueueReceive,
                    &UDR0,
                    HigherPriorityTaskWoken);//{};
    }
}
//Data register empty
ISR(USART_UDRE_vect){
    BaseType_t HigherPriorityTaskWoken = pdFALSE;
    if(xQueueIsQueueFullFromISR(QueueTransmit)!=pdFALSE){ 
    uint8_t save; 
    xQueueReceiveFromISR(
                    QueueTransmit,
                    (void*)&save,
                    HigherPriorityTaskWoken);//{};
    UDR0 = save;
    }
}

