#include "motion.h"

int initPIR(void)
{
	printf("PIR Initialization\n");
	pinMode(PIR_OUT, INPUT);

	return 0;
}

int g_nPirState = LOW;
int g_nPirValue = 0;
int controlPIR(void)
{
	g_nPirValue = digitalRead(PIR_OUT);

	if (g_nPirValue == LOW) {
		if (g_nPirState == LOW) {
			printf("MOtion detected\n");
			g_nPirState = HIGH;
		}
	}
	else {
		if (g_nPirState == HIGH) {
			printf("Motion ended.\n");
			g_nPirState = LOW;
		}
	}
	return g_nPirState;
}
