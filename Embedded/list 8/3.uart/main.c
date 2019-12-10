/******************************************************************************
 * Header file inclusions.
 ******************************************************************************/

#include "FreeRTOS.h"
#include "task.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "uart.h"

/******************************************************************************
 * Private macro definitions.
 ******************************************************************************/

#define mainLED_TASK_PRIORITY   1

#define mainUART_TASK_PRIORITY 2


/******************************************************************************
 * Private function prototypes.
 ******************************************************************************/

static void vBlinkLed(void* pvParameters);

static void vUart(void* pvParameters);

/******************************************************************************
 * Public function definitions.
 ******************************************************************************/

/**************************************************************************//**
 * \fn int main(void)
 *
 * \brief Main function.
 *
 * \return
 ******************************************************************************/
int main(void)
{
    QueueTransmit = xQueueCreate( 10, sizeof( uint8_t ) );
    QueueReceive = xQueueCreate( 10, sizeof( uint8_t ) );
    // Create task.
    xTaskHandle blink_handle;
    xTaskHandle uart_handle;
    xTaskCreate
        (
         vBlinkLed,
         "blink",
         configMINIMAL_STACK_SIZE,
         NULL,
         mainLED_TASK_PRIORITY,
         &blink_handle
        );

    xTaskCreate
        (
         vUart,
         "uart",
         configMINIMAL_STACK_SIZE,
         NULL,
         mainUART_TASK_PRIORITY,
         &uart_handle
        );

    // Start scheduler.
    vTaskStartScheduler();

    return 0;
}

/**************************************************************************//**
 * \fn static vApplicationIdleHook(void)
 *
 * \brief
 ******************************************************************************/
void vApplicationIdleHook(void)
{

}

/******************************************************************************
 * Private function definitions.
 ******************************************************************************/

/**************************************************************************//**
 * \fn static void vBlinkLed(void* pvParameters)
 *
 * \brief
 *
 * \param[in]   pvParameters
 ******************************************************************************/
static void vBlinkLed(void* pvParameters)
{
    DDRB |= _BV(PB5);

    for ( ;; )
    {
        PORTB ^= _BV(PB5);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}


/**************************************************************************//**
 * \fn static void vUart(void* pvParameters)
 *
 * \brief
 *
 * \param[in]   pvParameters
 ******************************************************************************/
static void vUart(void* pvParameters)
{
    uart_init();
    stdin = stdout = stderr = &uart_file;
    sei();
    char input;

    for ( ;; )
    {
        printf("Hello World\r\n");
        //scanf("%c",&input);//
        input = getchar();
        printf("You wrote %c\r\n", input); 
    }
}
