#include "doorlock.h"
#include "keypad.h"
#include "motor.h"
#include "buzzer.h"

#define PASSWARD_NUM	4

int nCounter = 0;
char g_cInputPasswardbuf[4];
char g_cPassward[] = "1278";
int g_nVerify;
int g_nDoorState;
int g_nPreDoorState;

const int OpenDoorBeepTable[4] = {MI, DO_L, SOL, DO_H };
const int ErrorBeepTable[2] = { MI, MI };

int setupWiringPiGpio(void)
{
	if (wiringPiSetupGpio() == -1)
		return 1;
}

void ErrorBeep(void)
{
	int i;
	for (i = 0; i < 2; i++) {
		Change_FREQ (ErrorBeepTable[i]);
		delay(500);
		STOP_FREQ();
	}
}

void OpenDoorBeep(void)
{
	int i;
	for (i=0; i < 4; i++) {
		Change_FREQ (OpenDoorBeepTable[i]);
		delay(500);
		STOP_FREQ();
	}
}

int PasswardVerify(void)
{
	int i, nError;
	for (i = 0; i < 4; i++) {
		if(g_cInputPasswardbuf[i] != g_cPassward[i]) {
			nError += 1;
		}
		else {
			nError += 0;
		}
	}
	return nError;
}

void ErrorPassward(void)
{
	g_nDoorState = 0;
	printf("ERROR PASSWD\n");
	ErrorBeep();
}

void PasswardVerifySuccess(void)
{
	g_nDoorState = 1;
}

int openDoor(void)
{
	g_nDoorState = 1;
	printf("\nOPEN DOOR\n");
	OpenDoorBeep();

	MotorControl(30, RIGHT_ROTATE);
	delay(1000);
	MotorStop();

	return g_nDoorState;
}

int closeDoor(void)
{
	g_nDoorState = 0;
	printf ("CLOSE DOOR\n");

	MotorControl(30, LEFT_ROTATE);
	delay(1000);
	MotorStop();

	return g_nDoorState;
}

void ButtonDetect(void)
{
	int nkeyValue, temp;

	temp = readKeypad();

	int i;
	for (i = 0; i < MAX_KEY_BT_NUM; i++) {
		if (temp & (1<<i)) {
			nkeyValue = i+1;
		}
	}
	if (nCounter >= PASSWARD_NUM) {
		printf("\n");
		nCounter = 0;
		if (PasswardVerify()) {
			ErrorPassward();
		}
		else {
			PasswardVerifySuccess();
		}
		printf("ENTER PASSWD: ");
		fflush(stdout);
	}
	switch(nkeyValue)
	{
		case 1:
			printf("1");
			fflush(stdout);
			g_cInputPasswardbuf[nCounter] = '1';
			nCounter++;
			break;
		case 2:
			printf("2");
			fflush(stdout);
			g_cInputPasswardbuf[nCounter] = '2';
			nCounter++;
			break;
		case 3:
			printf("3");
			fflush(stdout);
			g_cInputPasswardbuf[nCounter] = '3';
			nCounter++;
			break;
		case 4:
			printf("4");
			fflush(stdout);
			g_cInputPasswardbuf[nCounter] = '4';
			nCounter++;
			break;
		case 5:
			printf("5");
			fflush(stdout);
			g_cInputPasswardbuf[nCounter] = '5';
			nCounter++;
			break;
		case 6:
			printf("6");
			fflush(stdout);
			g_cInputPasswardbuf[nCounter] = '6';
			nCounter++;
			break;
		case 7:
			printf("7");
			fflush(stdout);
			g_cInputPasswardbuf[nCounter] = '7';
			nCounter++;
			break;
		case 8:
			printf("8");
			fflush(stdout);
			g_cInputPasswardbuf[nCounter] = '8';
			nCounter++;
			break;
		case 9:
			printf("9");
			fflush(stdout);
			g_cInputPasswardbuf[nCounter] = '9';
			nCounter++;
			break;
		case 10:
			printf("0");
			fflush(stdout);
			g_cInputPasswardbuf[nCounter] = '0';
			nCounter++;
			break;
		default:
			break;
	}
}

int controlDoorlock(int doorStatus)
{
	if(doorStatus == 1 && g_nPreDoorState == 0) {
		openDoor();
		g_nPreDoorState = doorStatus;
	}
	else if (doorStatus == 0 && g_nPreDoorState == 1) {
		closeDoor();
		g_nPreDoorState = doorStatus;
	}
	else {
		g_nPreDoorState = doorStatus;
	}

	ButtonDetect();

	return 0;
}
int getSensorData(void)
{
	return g_nDoorState;
}