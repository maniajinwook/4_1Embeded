#include <stdio.h>
#include <string.h>
#include <error.h>

#include <wiringPi.h>

#define INPUT_PIN	22

int nVal = 0;
int SensingFlag = 0;

int getSensorData(void)
{
	if(wiringPiSetupGpio() == -1)	return 1;

	pinMode(INPUT_PIN, INPUT);

	nVal = digitalRead(INPUT_PIN);
	if (nVal == LOW) {
		printf("Sensor Detected\n");
		SensingFlag = 1;
	}
	else {
		SensingFlag = 0;
	}
	return SensingFlag;
}
