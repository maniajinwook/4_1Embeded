#ifndef __HCSR04_H__
#define __HCSR04_H__

#include <stdio.h>
#include <wiringPi.h>

#define TP	4
#define EP	17

float TpInit(void);
int initSR04(void);
float controlSR04(void);

#endif /* __HCSR04_H__ */
