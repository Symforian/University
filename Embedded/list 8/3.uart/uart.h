#ifndef _UART_H
#define _UART_H
#include "queue.h"
#include "task.h"
void uart_init(void);
QueueHandle_t QueueTransmit;
QueueHandle_t QueueReceive;
xTaskHandle* uart_task_handle_ptr;
FILE uart_file;

#endif
