/******************************************************************************
 * Header file inclusions.
 ******************************************************************************/

#include "FreeRTOS.h"
#include "task.h"

#include <avr/io.h>


#include <stdio.h>
#define LED PB5
#define LED_DDR DDRB
#define LED_PORT PORTB
#define LED_BAR_DDR DDRD
#define LED_BAR_PORT PORTD
#define DELAYTIME 85 
#define BTN PB0
#define BTN_PIN PINB
#define BTN_PORT PORTB
/******************************************************************************
 * Private macro definitions.
 ******************************************************************************/

#define mainBLINK_TASK_PRIORITY   2

#define mainCYLON_TASK_PRIORITY 1

/******************************************************************************
 * Private function prototypes.
 ******************************************************************************/

static void vBlinkLed(void* pvParameters);

static void vCylon(void* pvParameters);

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
    // Create task.
    xTaskHandle blink_handle;
    xTaskHandle serial_handle;

    xTaskCreate
        (
         vBlinkLed,
         "blink",
         configMINIMAL_STACK_SIZE,
         NULL,
         mainBLINK_TASK_PRIORITY,
         &blink_handle
        );

    xTaskCreate
        (
         vCylon,
         "cylon",
         configMINIMAL_STACK_SIZE,
         NULL,
         mainCYLON_TASK_PRIORITY,
         &serial_handle
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
    // -------- Inits --------- //
    DDRB = 0xff; // led as output
    DDRB &= ~(1 << BTN);    /* Data Direction Register B:
                                   enables input. */
    BTN_PORT |= (1<<BTN);  // pull up 
    int8_t buffor[100];
    int counter = 0;
    int reading = 0;
    int printing = 0;
  // ------ Event loop ------ //
  while (1) {
        if (!reading && bit_is_clear(BTN_PIN, BTN)){ reading ++;}
      if(reading){
        if(bit_is_clear(BTN_PIN, BTN)){
                buffor[counter] = 1;                        /* pressed */   
                }
        else {                                              /* not pressed */
            buffor[counter] = 0;
            }
        counter ++;
      counter %= 100;
       }


    if(counter == 50) { printing = 1;}
    else if(printing == 1 && counter == 0){ printing = 2; }
    if(printing == 1){
            if(buffor[counter-50]==1) { LED_PORT |= _BV(LED);}
            else if(buffor[counter-50]==0)
                 {LED_PORT &= ~_BV(LED);}
            }

    
    else if (printing == 2){
            if(buffor[counter+50]==1) { LED_PORT |= _BV(LED);}
            else if(buffor[counter+50]==0)
                 {LED_PORT &= ~_BV(LED);}

            }

       vTaskDelay(25/portTICK_PERIOD_MS);

  }                                                  /* End event loop */
}


/**************************************************************************//**
 * \fn static void vCylon(void* pvParameters)
 *
 * \brief
 *
 * \param[in]   pvParameters
 ******************************************************************************/
static void vCylon(void* pvParameters)
{
  UCSR0B  &= ~_BV(RXEN0) & ~_BV(TXEN0); //Enable PD0 & PD1
  uint8_t i = 0;
  LED_BAR_DDR = 0xff;               // Data Direction Register B all set up for output 
  for (;;) {
    while (i < 7) {
    LED_BAR_PORT = (1 << i);                 /* illuminate only i'th pin */
    vTaskDelay(DELAYTIME / portTICK_PERIOD_MS);  /* wait */
    i = i + 1;                               /* move to the next LED */ 
    }
    while (i > 0)  {
    LED_BAR_PORT = (1 << i);                 /* illuminate only i'th pin */
    vTaskDelay(DELAYTIME / portTICK_PERIOD_MS);  /* wait */
    i = i - 1;                           /* move to the previous LED */    
    }  
  }  

}
