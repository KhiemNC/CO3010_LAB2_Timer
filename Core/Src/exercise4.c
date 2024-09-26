/*
 * exercise4.c
 *
 *  Created on: Sep 26, 2024
 *      Author: nguye
 */

#include "exercise4.h"
#include "exercise3.h" // use update7SEG()
#include "exercise2.h" // use exercise2_init()

#define TIMER_USE 3
#define TIME 250

#define DOT_TIMER 4
#define DOT_TIME 1000

extern const int MAX_LED;
extern int index_led;
extern int led_buffer[4];

void exercise4_init()
{
	exercise2_init();

	setTimer(TIMER_USE, TIME);
	setTimer(DOT_TIMER, DOT_TIME);
}

void exercise4_run()
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
