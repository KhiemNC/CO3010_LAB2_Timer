/*
 * exercise1.h
 *
 *  Created on: Sep 24, 2024
 *      Author: nguye
 */

#ifndef INC_EXERCISE1_H_
#define INC_EXERCISE1_H_

#include "main.h"
#include "software_timer.h"

typedef enum
{
	INIT,
	LED1,
	LED2
} Exercise1_State;

void exercise1_init();
void exercise1_run();

void display7SEG(int num);
void enable_seg(int num);


#endif /* INC_EXERCISE1_H_ */
