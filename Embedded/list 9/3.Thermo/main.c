/******************************************************************************
 * Header file inclusions.
 ******************************************************************************/

#include "FreeRTOS.h"
#include "task.h"

#include <avr/io.h>

#include <stdlib.h>     /* strtol */
#include <stdio.h>
#include "uart.h"

/******************************************************************************
 * Private macro definitions.
 ******************************************************************************/
#define HEATER_DDR DDRB
#define HEATER_PORT PORTB
#define HEATER PB5

#define mainREAD_PRIORITY   2

#define mainADJUST_HEATER_PRIORITY 1
volatile uint16_t current_temp = 0;
volatile uint16_t temp = 5;
uint16_t temph = 1;
/******************************************************************************
 * Private function prototypes.
 ******************************************************************************/

static void vRead(void* pvParameters);

static void vHeater(void* pvParameters);

/******************************************************************************
 * Public function definitions.
 ******************************************************************************/
// inicjalizacja ADC
void adc_init()
{
  ADMUX   = _BV(REFS0) | _BV(REFS1); // referencja AVcc, wejście ADC0
  DIDR0   = _BV(ADC0D); // wyłącz wejście cyfrowe na ADC0
  // częstotliwość zegara ADC 125 kHz (16 MHz / 128)
        
  ADCSRA  = _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2); // preskaler 128
  ADCSRA |= _BV(ADEN); // włącz ADC
}
/**************************************************************************//**
 * \fn int main(void)
 *
 * \brief Main function.
 *
 * \return
 ******************************************************************************/
int main(void)
{
    // Create task.
    xTaskHandle read_handle;
    xTaskHandle heater_handle;

    xTaskCreate
        (
         vRead,
         "read",
         configMINIMAL_STACK_SIZE,
         NULL,
         mainREAD_PRIORITY,
         &read_handle
        );

    xTaskCreate
        (
         vHeater,
         "heater",
         configMINIMAL_STACK_SIZE,
         NULL,
         mainADJUST_HEATER_PRIORITY,
         &heater_handle
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
static void vRead(void* pvParameters)
{

    uart_init();

    stdin = stdout = stderr = &uart_file;
    char input_c;
    char input[6];
    uint8_t i = 0;
    char *endPtr;
    for ( ;; )
    {
        input_c = getchar();
        if(input_c=='r'){
            printf("Current temp: %"PRIu16"\r\n", current_temp);
            vTaskDelay(5 / portTICK_PERIOD_MS);
        }
        else if (input_c=='s'){
            puts("Setting temperature:\r");

            while(i == 0 || (i<6 && input[i-1] != 13 && input[i-1] != ' ' && input[i-1] != 0)){
                input[i] = getchar();
                i++;
            }
            i = 0;
            temp = (uint16_t)strtol(input,&endPtr,10);
            printf("Set temp to: %"PRIu16"\r\n", temp);
            vTaskDelay(5 / portTICK_PERIOD_MS);

        }

    }
}


/**************************************************************************//**
 * \fn static void vSerial(void* pvParameters)
 *
 * \brief
 *
 * \param[in]   pvParameters
 ******************************************************************************/
static void vHeater(void* pvParameters)
{
    adc_init();
    HEATER_DDR |= _BV(HEATER);
    for ( ;; )
    {
        ADCSRA |= _BV(ADSC); // wykonaj konwersję
        while (!(ADCSRA & _BV(ADIF))); // czekaj na wynik
        ADCSRA |= _BV(ADIF); // wyczyść bit ADIF (pisząc 1!)
        current_temp =  ((ADC*55)>>9)-50;
        if(current_temp>=temp){
                HEATER_PORT &= ~_BV(HEATER);
            }
        else if(current_temp<=(temp-temph)){
                HEATER_PORT |= _BV(HEATER);
            }
    }
}
