/*
 * exercise1.c
 *
 *  Created on: Sep 24, 2024
 *      Author: nguye
 */

#include "exercise1.h"

#define LED_ON 0
#define LED_OFF 1

#define ENABLE_SEG 0
#define DISABLE_SEG 1

#define TIMER_USE 0
#define TIME 500

typedef enum
{
	INIT,
	LED1,
	LED2
} Exercise1_State;

Exercise1_State ex1_state = INIT;

/**
  * @brief Use for testing all GPIOs necessary
  */
void exercise1_init()
{
	HAL_GPIO_TogglePin(EN_0_GPIO_Port, EN_0_Pin);
	HAL_GPIO_TogglePin(EN_1_GPIO_Port, EN_1_Pin);
	HAL_GPIO_TogglePin(SEG_0_GPIO_Port, SEG_0_Pin);
	HAL_GPIO_TogglePin(SEG_1_GPIO_Port, SEG_1_Pin);
	HAL_GPIO_TogglePin(SEG_2_GPIO_Port, SEG_2_Pin);
	HAL_GPIO_TogglePin(SEG_3_GPIO_Port, SEG_3_Pin);
	HAL_GPIO_TogglePin(SEG_4_GPIO_Port, SEG_4_Pin);
	HAL_GPIO_TogglePin(SEG_5_GPIO_Port, SEG_5_Pin);
	HAL_GPIO_TogglePin(SEG_6_GPIO_Port, SEG_6_Pin);
}

/**
  * @brief Simulate a single 7-SEGMENT led, show numbers in sequence from 0 to 9
  */
void exercise1_run()
{
	switch (ex1_state) {
		case INIT:
			if (1)
			{
				ex1_state = LED1;

				setTimer(TIMER_USE, TIME);
			}
			break;
		case LED1:
			display7SEG(1);
			enable_seg(0);

			if (isFlag(TIMER_USE))
			{
				ex1_state = LED2;

				setTimer(TIMER_USE, TIME);
			}
			break;
		case LED2:
			display7SEG(2);
			enable_seg(1);

			if (isFlag(TIMER_USE))
			{
				ex1_state = LED1;

				setTimer(TIMER_USE, TIME);
			}
			break;
		default:
			break;
	}
}

/**
  * @brief Display a single number (0 to 9) on a 7-SEGMENT led
  * @param  num: Specifies the number need to display, from 0 to 11
  * @retval None
  */
void display7SEG(int num)
{
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_OFF);
			break;
		case 1:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_OFF);
			break;
		case 2:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_ON);
			break;
		case 3:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_ON);
			break;
		case 4:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_ON);
			break;
		case 5:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_ON);
			break;
		case 6:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_ON);
			break;
		case 7:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_OFF);
			break;
		case 8:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_ON);
			break;
		case 9:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_ON);
			break;
		default:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_OFF);
			break;
	}
}

void enable_seg(int num)
{
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, ENABLE_SEG);
			HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_2_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_3_Pin, DISABLE_SEG);
			break;
		case 1:
			HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, ENABLE_SEG);
			HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_2_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_3_Pin, DISABLE_SEG);
			break;
		case 2:
			HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_2_Pin, ENABLE_SEG);
			HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_3_Pin, DISABLE_SEG);
			break;
		case 3:
			HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_2_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_3_Pin, ENABLE_SEG);
			break;
		default:
			break;
	}
}
