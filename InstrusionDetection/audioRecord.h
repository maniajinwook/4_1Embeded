#ifndef __AUDIORECORD_H__
#define __AUDIORECORD_H__

#include <wiringPi.h>
#include <stdio.h>

#define REC	11
#define PLAYE	9
#define PLAYL	10

int initRecord(void);
void playVoice(void);

#endif /* __AUDIORECORD_H__ */
