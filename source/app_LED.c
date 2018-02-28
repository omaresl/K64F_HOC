/*
 * app_LED.c
 *
 *  Created on: 19/02/2018
 *      Author: uidj2522
 */



#include "fsl_clock.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "app_LED.h"

E_COLOR re_CurrentColor = APP_LED_RED;

static void app_LED_NextColor(void);

/*
 *
 * Description: This function initialize the ports
 * 				related to the leds
 */
void app_LED_Init(void)
{
	/* Enable CLock */
	CLOCK_EnableClock(kCLOCK_PortB);
	CLOCK_EnableClock(kCLOCK_PortE);


	/* PIN as GPIO */
	PORT_SetPinMux(PORTB, APP_LED_RED_PIN_NUMBER, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTE, APP_LED_GREEN_PIN_NUMBER, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTB, APP_LED_BLUE_PIN_NUMBER, kPORT_MuxAsGpio);

	/* GPIO as Output */
	gpio_pin_config_t ls_PinConfig; //Variable Local Compleja

	ls_PinConfig.pinDirection = kGPIO_DigitalOutput;
	ls_PinConfig.outputLogic = 1u; //OFF


	GPIO_PinInit(GPIOB, APP_LED_RED_PIN_NUMBER, &ls_PinConfig);
	GPIO_PinInit(GPIOE, APP_LED_GREEN_PIN_NUMBER, &ls_PinConfig);
	GPIO_PinInit(GPIOB, APP_LED_BLUE_PIN_NUMBER, &ls_PinConfig);
}

void app_LED_Toogle(void)
{
	unsigned char lub_EstadoDelLed;

	lub_EstadoDelLed = GPIO_ReadPinInput(GPIOB, APP_LED_RED_PIN_NUMBER);

	if(lub_EstadoDelLed == 0u)
	{
		/* Si esta prendido apagalo*/
		GPIO_WritePinOutput(GPIOB, APP_LED_RED_PIN_NUMBER, 1u);
	}
	else
	{
		/* Si esta apagado prendelo */
		GPIO_WritePinOutput(GPIOB, APP_LED_RED_PIN_NUMBER, 0u);
	}
}

void app_LED_RGB_Task(void)
{
	switch(re_CurrentColor)
	{
	case RED:
	{
		APP_LED_GREEN_OFF;
		APP_LED_BLUE_OFF;
		APP_LED_RED_ON;
	}break;
	case GREEN:
	{
		APP_LED_RED_OFF;
		APP_LED_BLUE_OFF;
		APP_LED_GREEN_ON;
	}break;
	case BLUE:
	{
		APP_LED_RED_OFF;
		APP_LED_GREEN_OFF;
		APP_LED_BLUE_ON;
	}break;
	case YELLOW:
	{
		APP_LED_BLUE_OFF;
		APP_LED_RED_ON;
		APP_LED_GREEN_ON;
	}break;
	case CYAN:
	{
		APP_LED_RED_OFF;
		APP_LED_GREEN_ON;
		APP_LED_BLUE_ON;
	}break;
	case PURPLE:
	{
		APP_LED_GREEN_OFF;
		APP_LED_RED_ON;
		APP_LED_BLUE_ON;
	}break;
	case WHITE:
	{
		APP_LED_RED_ON;
		APP_LED_GREEN_ON;
		APP_LED_BLUE_ON;
	}break;
	case BLACK:
	{
		APP_LED_RED_OFF;
		APP_LED_GREEN_OFF;
		APP_LED_BLUE_OFF;
	}break;
	default:
	{
		APP_LED_RED_OFF;
		APP_LED_GREEN_OFF;
		APP_LED_BLUE_OFF;

		re_CurrentColor = 0u;
	}break;
	}

	app_LED_NextColor();
}

void app_LED_RED_ON(void)
{
	GPIO_WritePinOutput(GPIOB, APP_LED_RED_PIN_NUMBER, 0u);
}

void app_LED_RED_OFF(void)
{
	GPIO_WritePinOutput(GPIOB, APP_LED_RED_PIN_NUMBER, 1u);
}

static void app_LED_NextColor(void)
{
	if(re_CurrentColor < (N_COLORS - 1))
	{
		re_CurrentColor++;
	}
	else
	{
		re_CurrentColor = 0u; //RED
	}
}
