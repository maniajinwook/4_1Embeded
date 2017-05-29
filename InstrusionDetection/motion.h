#ifndef __MOTION_H__
#define __MOTION_H__

#include <stdio.h>
#include <wiringPi.h>

#define PIR_OUT	22

int controlPRI(void);
int initPRI(void);

#endif /* __MOTION_H__ */
