#include "keypad.h"

const int KeypadTable[8]= {
	KEYPAD_PB1, KEYPAD_PB2, KEYPAD_PB3, KEYPAD_PB4,
	KEYPAD_PB5, KEYPAD_PB6, KEYPAD_PB7, KEYPAD_PB8,
};

int KeypadRead(void)
{
	int i,nKeypadstate;
        nKeypadstate = 0;
	for(i =0; i<MAX_KEY_BT_NUM; i++) {
		if(!digitalRead(KeypadTable[i])) {
			nKeypadstate |= (1<<i);
		}
	}
    	return nKeypadstate;
}


int initKeypad(void)
{
	if (wiringPiSetupGpio()<0)
		return 1;
	int i;
	for(i =0; i<MAX_KEY_BT_NUM; i++) {
		pinMode(KeypadTable[i],INPUT);
	}
	printf("Keypad Initialize\n");
	return 0;
}


