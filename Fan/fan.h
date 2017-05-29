#ifndef	__FAN_H__
#define	__FAN_H__

#include <wiringPi.h>
#include <stdio.h>

#define FAN_MT_P_PIN	4
#define FAN_MT_N_PIN	17

void initFan(void);
void FanOn(void);
void FanOff(void);

#endif	/* __FAN_H__ */