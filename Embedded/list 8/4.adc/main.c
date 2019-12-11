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
  ADCSRA |= _BV(ADIE);  
  ADCSRA |= _BV(ADEN); // włącz ADC
}
SemaphoreHandle_t mutex;
SemaphoreHandle_t first_place;
SemaphoreHandle_t second_place;
xTaskHandle foto_handle;
xTaskHandle potent_handle;
xTaskHandle thermo_handle;
xTaskHandle currentTask;
volatile uint16_t result;
uint16_t readADC(uint8_t mux)
{


    if(xSemaphoreTake(second_place,portMAX_DELAY)==pdTRUE){
        printf("S1: %"PRIu8"\r\n",mux);
        if(xSemaphoreTake(first_place,portMAX_DELAY)==pdTRUE){
            printf("S2: %"PRIu8"\r\n",mux);
            xSemaphoreGive(second_place);
            if(xSemaphoreTake(mutex,portMAX_DELAY)==pdTRUE){
                printf("M: %"PRIu8"\r\n",mux);
                xSemaphoreGive(first_place);
                ADMUX  =_BV(REFS0) | mux;
                if(xSemaphoreTake(adc_result,portMAX_DELAY)==pdTRUE){
                    printf("R: %"PRIu8"\r\n",mux);
                    uint16_t val = result;
                    xSemaphoreGive(mutex);
                    return val;
                }
            }           
        }
    }
    readADC(mux);
}
ISR(ADC_vect) {
    ADCSRA |= _BV(ADIF);
    result = ADC;
    xTaskResumeFromISR(  currentTask );

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
    sei();
    mutex = xSemaphoreCreateMutex();
    first_place = xSemaphoreCreateMutex();
    second_place = xSemaphoreCreateMutex();    
    while(mutex==NULL || first_place==NULL || second_place==NULL);
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
        vTaskDelay(100 / portTICK_PERIOD_MS);
        uint16_t v = readADC(mux);
        //printf("FOTO: %"PRIu16"\r\n",v);

    }

}


static void vPotent(void* pvParameters)
{
    uint8_t mux = MUX0;
    for (;;)
    {
        vTaskDelay(100 / portTICK_PERIOD_MS);
        uint16_t v = readADC(mux);
        //printf("POTENT: %"PRIu16"\r\n",v);

    }

}


static void vThermo(void* pvParameters)
{

    uint8_t mux = MUX2;
    for (;;)
    {
        vTaskDelay(100 / portTICK_PERIOD_MS);
        uint16_t v = readADC(mux);
        //printf("THERMO: %"PRIu16"\r\n",v);

    }


}
