#include "fan.h"

void initFan(void)
{
	printf("Fan Initialize.\n");	
	pinMode(FAN_MT_P_PIN, OUTPUT);
	pinMode(FAN_MT_N_PIN, OUTPUT);
	FanOff();
}

void FanOn(void)
{
	digitalWrite(FAN_MT_P_PIN, HIGH);
	digitalWrite(FAN_MT_N_PIN, LOW);
}

void FanOff(void)
{
	digitalWrite(FAN_MT_P_PIN, LOW);
	digitalWrite(FAN_MT_N_PIN, LOW);
}

