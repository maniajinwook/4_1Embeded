#include "intrusionDetection.h"
#include "motion.h"
#include "led.h"
#include "audioRecord.h"

int setupWiringPiGpio(void)
{
	if(wiringPiSetupGpio() == -1)
		return 1;
}

int getSensorData(void) 
{
	int detectionFlag;
	detectionFlag = controlPIR();

	return detectionFlag;
}

int controlLed(int motion)
{
	if (motion == HIGH) {
		LedOn(RED);
		delay(500);
		LedOff(RED);
		delay(500);
	}
	return 0;
}

int controlRecord(int motion) 
{
	if (motion == HIGH) {
		playVoice();
	}
	return 0;
}
