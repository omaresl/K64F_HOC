/*
 * app_LED.h
 *
 *  Created on: 19/02/2018
 *      Author: uidj2522
 */

#ifndef APP_LED_H_
#define APP_LED_H_

/* Typedef */
typedef enum
{
	RED,
	GREEN,
	BLUE,
	YELLOW,
	CYAN,
	PURPLE,
	WHITE,
	BLACK,
	N_COLORS
}E_COLOR;

/* Macros */
#define APP_LED_RED	0u

#define APP_LED_RED_PIN_NUMBER		22u
#define APP_LED_GREEN_PIN_NUMBER	26u
#define APP_LED_BLUE_PIN_NUMBER		21u

#define APP_LED_RED_ON		    GPIO_WritePinOutput(GPIOB, 			APP_LED_RED_PIN_NUMBER, 0u)
#define APP_LED_RED_OFF		    GPIO_WritePinOutput(GPIOB, 			APP_LED_RED_PIN_NUMBER, 1u)
#define APP_LED_RED_TOGGLE	    GPIO_TogglePinsOutput(GPIOB, (1 << 	APP_LED_RED_PIN_NUMBER))

#define APP_LED_GREEN_ON        GPIO_WritePinOutput(GPIOE, 			APP_LED_GREEN_PIN_NUMBER, 0u)
#define APP_LED_GREEN_OFF       GPIO_WritePinOutput(GPIOE, 			APP_LED_GREEN_PIN_NUMBER, 1u)
#define APP_LED_GREEN_TOGGLE    GPIO_TogglePinsOutput(GPIOE, (1 << 	APP_LED_GREEN_PIN_NUMBER))

#define APP_LED_BLUE_ON			GPIO_WritePinOutput(GPIOB, 			APP_LED_BLUE_PIN_NUMBER, 0u)
#define APP_LED_BLUE_OFF        GPIO_WritePinOutput(GPIOB, 			APP_LED_BLUE_PIN_NUMBER, 1u)
#define APP_LED_BLUE_TOGGLE     GPIO_TogglePinsOutput(GPIOB, (1 << 	APP_LED_BLUE_PIN_NUMBER))

extern void app_LED_Init(void);
extern void app_LED_Toogle(void);
extern void app_LED_RGB_Task(void);

#endif /* APP_LED_H_ */
