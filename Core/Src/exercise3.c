/*
 * exercise3.c
 *
 *  Created on: Sep 26, 2024
 *      Author: nguye
 */

#include "exercise3.h"
#include "exercise2.h" // use exercise2_init()
#include "exercise1.h" // use display7SEG() and enable_seg()

#define LED_ON 0
#define LED_OFF 1

#define ENABLE_SEG 0
#define DISABLE_SEG 1

#define TIMER_USE 3
#define TIME 10

#define DOT_TIMER 4
#define DOT_TIME 1000

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {6, 7, 8, 9};

void exercise3_init()
{
	exercise2_init();

	setTimer(TIMER_USE, TIME);
	setTimer(DOT_TIMER, DOT_TIME);
}

void exercise3_run()
{
	if (isFlag(TIMER_USE))
	{
		update7SEG(index_led);
		++index_led;
		if (index_led >= 4)
		{
			index_led = 0;
		}

		setTimer(TIMER_USE, TIME);
	}

	if (isFlag(DOT_TIMER))
	{
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		setTimer(DOT_TIMER, DOT_TIME);
	}
}

void update7SEG(int idx)
{
	switch (idx) {
		case 0:
			display7SEG(led_buffer[0]);
			enable_seg(0);
			break;
		case 1:
			display7SEG(led_buffer[1]);
			enable_seg(1);
			break;
		case 2:
			display7SEG(led_buffer[2]);
			enable_seg(2);
			break;
		case 3:
			display7SEG(led_buffer[3]);
			enable_seg(3);
			break;
		default:
			break;
	}
}
