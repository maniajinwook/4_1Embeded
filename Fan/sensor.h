#ifndef	__SENSOR_H__
#define	__SENSOR_H__

int setupWiringPiGpio(void);
int getSensorData(void);
void controlFan(int temp);

int setInterrupt (int pin, int edge, void(*function)(void));
void PB1_Interrupt(void);
void PB2_Interrupt(void);
void upTemp(void);
void downTemp(void);

#endif	/* __SENSOR_H__ */
