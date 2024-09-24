/*
 * exercise1.c
 *
 *  Created on: Sep 24, 2024
 *      Author: nguye
 */

#include "exercise1.h"

#define LED_ON 0
#define LED_OFF 1

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
