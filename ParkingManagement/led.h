#ifndef __LED_H__
#define __LED_H__

#include <wiringPi.h>
#include <stdio.h>

#define LED_RED_PIN	6
#define LED_GREEN_PIN	11

#define RED	1
#define GREEN	0

int initLed(void);
void LedOn(int color);
void LedOff(int color);

#endif /* __LED_H__ */
