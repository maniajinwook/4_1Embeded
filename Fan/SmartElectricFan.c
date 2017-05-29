#include "temp.h"

volatile float temp;
volatile float humi;


int setupWiringPiGpio(void)
{
	if (wiringPiSetupGpio() == -1)
		return 1;
}


int getSensorData(void)
{
	Transmission_start();
	temp = get_SHT11_data (TEMP);	// Sensing Temp
	delay(100);

	Transmission_start();
	humi = get_SHT11_data (HUMI); 	// Sensing Humi
	delay(100);

	printf("Temp = %2.2f [C], Humi = %2.2f [%]\n", temp, humi);

	return temp;
}

int g_nFanOnValue = 25;
int controlFan(int temp)
{
	if(temp >= g_nFanOnValue) {
		FanOn();	//Fan On
		printf("Fan On\n");
	}
	else {
		FanOff();	//Fan Off
		printf("Fan Off\n");
	}
}

int setInterrupt (int pin, int edge, void(*function)(void))
{
	if(wiringPiISR(pin, edge, function)<0)
		return 1;
}

void upTemp(void)
{
	g_nFanOnValue++;
}

void downTemp(void)
{
	g_nFanOnValue--;
}

void PB1_Interrupt(void)
{
	upTemp();
	printf("Fan On Value : %d\n", g_nFanOnValue);
}

void PB2_Interrupt(void)
{
	downTemp();
	printf("Fan On Value : %d\n", g_nFanOnValue);
}

/*
#if 0
int controlKeypad(void)
{
	int nKeypadState;
	nKeypadState = KeypadRead();

	int i;
	for(i=0; i<MAX_KEY_BT_NUM;i++) {
		if((nKeypadState&(1<<i))) {
			upTemp();
		}
		else {
			downTemp();
		}
	}
}
#endif

*/
