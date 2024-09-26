/*
 * exercise5.c
 *
 *  Created on: Sep 26, 2024
 *      Author: nguye
 */


#include "exercise5.h"
#include "exercise3.h" // use update7SEG()
#include "exercise2.h" // use exercise2_init()

#define TIMER_USE 5
#define TIME 250

#define DOT_TIMER 6
#define DOT_TIME 1000

extern const int MAX_LED;
extern int index_led;
extern int led_buffer[4];

int hour = 15, minute = 58, second = 50;

void exercise5_init()
{
	exercise2_init();

	updateClockBuffer();
	setTimer(TIMER_USE, TIME);
	setTimer(DOT_TIMER, DOT_TIME);
}

void exercise5_run()
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
		++second;
		if (second >= 60)
		{
			second = 0;
			++minute;
		}
		if (minute >= 60)
		{
			minute = 0;
			++hour;
		}
		if (hour >= 24)
		{
			hour = 0;
		}
		updateClockBuffer();

		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		setTimer(DOT_TIMER, DOT_TIME);
	}
}

void updateClockBuffer()
{
	led_buffer[0] = (hour / 10) % 10;
	led_buffer[1] = hour % 10;
	led_buffer[2] = (minute / 10) % 10;
	led_buffer[3] = minute % 10;
}
