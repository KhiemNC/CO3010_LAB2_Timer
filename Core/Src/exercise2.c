/*
 * exercise2.c
 *
 *  Created on: Sep 26, 2024
 *      Author: nguye
 */

#include "exercise2.h"
#include "exercise1.h" // use display7SEG() and enable_seg()

#define LED_ON 0
#define LED_OFF 1

#define ENABLE_SEG 0
#define DISABLE_SEG 1

#define TIMER_7SEG 1
#define TIME_7SEG 500

#define TIMER_DOT 2
#define TIME_DOT 1000

#define TIMER_LED_BLINKY 3
#define TIME_LED_BLINKY 1000

typedef enum
{
	INIT,
	LED1,
	LED2,
	LED3,
	LED4
} Exercise2_State;

Exercise2_State ex2_state = INIT;

void exercise2_init()
{
	HAL_GPIO_TogglePin(EN_0_GPIO_Port, EN_0_Pin);
	HAL_GPIO_TogglePin(EN_1_GPIO_Port, EN_1_Pin);
	HAL_GPIO_TogglePin(EN_2_GPIO_Port, EN_2_Pin);
	HAL_GPIO_TogglePin(EN_3_GPIO_Port, EN_3_Pin);
	HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
	HAL_GPIO_TogglePin(SEG_0_GPIO_Port, SEG_0_Pin);
	HAL_GPIO_TogglePin(SEG_1_GPIO_Port, SEG_1_Pin);
	HAL_GPIO_TogglePin(SEG_2_GPIO_Port, SEG_2_Pin);
	HAL_GPIO_TogglePin(SEG_3_GPIO_Port, SEG_3_Pin);
	HAL_GPIO_TogglePin(SEG_4_GPIO_Port, SEG_4_Pin);
	HAL_GPIO_TogglePin(SEG_5_GPIO_Port, SEG_5_Pin);
	HAL_GPIO_TogglePin(SEG_6_GPIO_Port, SEG_6_Pin);

	setTimer(TIMER_DOT, TIME_DOT);
	setTimer(TIMER_LED_BLINKY, TIME_LED_BLINKY);
}

void exercise2_run()
{
	switch (ex2_state) {
		case INIT:
			if (1)
			{
				ex2_state = LED1;

				setTimer(TIMER_7SEG, TIME_7SEG);
			}
			break;
		case LED1:
			display7SEG(1);
			enable_seg(0);

			if (isFlag(TIMER_7SEG))
			{
				ex2_state = LED2;

				setTimer(TIMER_7SEG, TIME_7SEG);
			}
			break;
		case LED2:
			display7SEG(2);
			enable_seg(1);

			if (isFlag(TIMER_7SEG))
			{
				ex2_state = LED3;

				setTimer(TIMER_7SEG, TIME_7SEG);
			}
			break;
		case LED3:
			display7SEG(3);
			enable_seg(2);

			if (isFlag(TIMER_7SEG))
			{
				ex2_state = LED4;

				setTimer(TIMER_7SEG, TIME_7SEG);
			}
			break;
		case LED4:
			display7SEG(0);
			enable_seg(3);

			if (isFlag(TIMER_7SEG))
			{
				ex2_state = LED1;

				setTimer(TIMER_7SEG, TIME_7SEG);
			}
			break;
		default:
			break;
	}

	if (isFlag(TIMER_DOT))
	{
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		setTimer(TIMER_DOT, TIME_DOT);
	}

	if (isFlag(TIMER_LED_BLINKY))
	{
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		setTimer(TIMER_LED_BLINKY, TIME_LED_BLINKY);
	}
}
