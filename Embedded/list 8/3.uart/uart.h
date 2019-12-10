#ifndef _UART_H
#define _UART_H
#include "queue.h"
void uart_init(void);
QueueHandle_t QueueTransmit;
QueueHandle_t QueueReceive;
FILE uart_file;

#endif
