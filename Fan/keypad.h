#ifndef	__KEYPAD_H__
#define	__KEYPAD_H__

#include <wiringPi.h>
#include <stdio.h>

#define KEYPAD_PB1		6
#define KEYPAD_PB2		12
#define KEYPAD_PB3		13
#define KEYPAD_PB4		16
#define KEYPAD_PB5		19
#define KEYPAD_PB6		20
#define KEYPAD_PB7		26
#define KEYPAD_PB8		21

#define MAX_KEY_BT_NUM	8

int initKeypad(void);
int KeypadRead(void);

#endif	/* __KEYPAD_H__ */
