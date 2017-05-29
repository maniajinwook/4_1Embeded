#include "led.h"

int initLed(void) {
	printf("LED Initialization \n");

	pinMode(LED_RED_PIN, OUTPUT);
	pinMode(LED_GREEN_PIN, OUTPUT);

	digitalWrite(LED_RED_PIN,LOW);
	digitalWrite(LED_GREEN_PIN, LOW);
	return 0;
}

void LedOn(int color) {
	if (color == 1) {
		digitalWrite(LED_RED_PIN, HIGH);
	}
	else  {
		digitalWrite(LED_GREEN_PIN, HIGH);
	}
}

void LedOff(int color) {
	if (color == 1) {
		digitalWrite (LED_RED_PIN, LOW);
	}
	else {
		digitalWrite(LED_GREEN_PIN, LOW);
	}
}
