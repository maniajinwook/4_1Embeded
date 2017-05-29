#include "audioRecord.h"

int initRecord(void)
{
	printf("Audio Record Initialization\n");
	pinMode(REC, OUTPUT);
	pinMode(PLAYE, OUTPUT);
	pinMode(PLAYL, OUTPUT);
}

void playVoice(void)
{
	printf("play Voice\n");
	digitalWrite(PLAYE, 1);
	delay(3000);
	digitalWrite(PLAYE, 0);
}
