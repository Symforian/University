/******************************************************************************
 * Header file inclusions.
 ******************************************************************************/

#include "FreeRTOS.h"
#include "task.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include "queue.h"
#include "semphr.h" 

#include <stdio.h>
#include "uart.h"
//*****************************************************************************
// inicjalizacja ADC
void adc_init()
{
  ADMUX   = _BV(REFS0); // referencja AVcc, wejście ADC0
  DIDR0   = _BV(ADC0D) |_BV(ADC1D)| _BV(ADC2D); // wyłącz wejście cyfrowe na ADC0 ADC1 ADC2
  // częstotliwość zegara ADC 125 kHz (16 MHz / 128)
  ADCSRA  = _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2); // preskaler 128
  ADCSRA |= _BV(ADEN); // włącz ADC
}
SemaphoreHandle_t mutex;
xTaskHandle foto_handle;
xTaskHandle potent_handle;
xTaskHandle thermo_handle;
uint8_t Current;
uint16_t readADC(uint8_t mux)
{
    Current = mux;
    uint16_t result;
    ADMUX   = _BV(REFS0);
    ADMUX |= mux;
    ADCSRA |= _BV(ADSC); // wykonaj konwersję
    while (!(ADCSRA & _BV(ADIF))); // czekaj na wynik
    ADCSRA |= _BV(ADIF); // wyczyść bit ADIF (pisząc 1!)   
    result = ADC;
    return result; // weź zmierzoną wartość (0..1023)
}
ISR(ADC_vect) {
    ADCSRA |= _BV(ADIF);
    if(Current == MUX0)
        xTaskResumeFromISR(potent_handle);
    else if(Current == MUX1)
        xTaskResumeFromISR(foto_handle);
    else if(Current == MUX2)
        xTaskResumeFromISR(thermo_handle);
}

/******************************************************************************
 * Private macro definitions.
 ******************************************************************************/

#define mainFOTO_TASK_PRIORITY 1

#define mainPOTENT_TASK_PRIORITY 1

#define mainTHERMO_TASK_PRIORITY 1
/******************************************************************************
 * Private function prototypes.
 ******************************************************************************/
static void vFoto(void* pvParameters);

static void vPotent(void* pvParameters);

static void vThermo(void* pvParameters);

/******************************************************************************
 * Public function definitions.
 ******************************************************************************/

int main(void)
{
    uart_init();
    stdin = stdout = stderr = &uart_file;
    adc_init();
    mutex = xSemaphoreCreateMutex();
    // Create task.
    xTaskCreate
        (
         vFoto,
         "foto",
         configMINIMAL_STACK_SIZE,
         NULL,
         mainFOTO_TASK_PRIORITY,
         &foto_handle
        );
    xTaskCreate
        (
         vPotent,
         "potent",
         configMINIMAL_STACK_SIZE,
         NULL,
         mainPOTENT_TASK_PRIORITY,
         &potent_handle
        );

    xTaskCreate
        (
         vThermo,
         "thermo",
         configMINIMAL_STACK_SIZE,
         NULL,
         mainTHERMO_TASK_PRIORITY,
         &thermo_handle
        );

    // Start scheduler.
    vTaskStartScheduler();

    return 0;
}

void vApplicationIdleHook(void)
{

}

/******************************************************************************
 * Private function definitions.
 ******************************************************************************/

static void vFoto(void* pvParameters)
{
    uint8_t mux = MUX1;
    for (;;)
    {
        if(xSemaphoreTake(mutex, ( TickType_t ) 10)==pdTRUE){
            uint16_t v = readADC(mux);
            printf("t: %"PRIu16"\r\n",v);
            xSemaphoreGive(mutex);
        }
        else
        {
            vTaskSuspend(NULL);
        }
    }

}


static void vPotent(void* pvParameters)
{
    uint8_t mux = MUX0;
    for (;;)
    {
        if(xSemaphoreTake(mutex, ( TickType_t ) 10)==pdTRUE){
            uint16_t v = readADC(mux);
            printf("t: %"PRIu16"\r\n",v);
            xSemaphoreGive(mutex);
        }
        else
        {
            vTaskSuspend(NULL);
        }
    }

}


static void vThermo(void* pvParameters)
{
    uint8_t mux = MUX2;
    for (;;)
    {
        if(xSemaphoreTake(mutex, ( TickType_t ) 10)==pdTRUE){
            uint16_t v = readADC(mux);
            printf("t: %"PRIu16"\r\n",v);
            xSemaphoreGive(mutex);
        }
        else
        {
            vTaskSuspend(NULL);
        }
    }


}
