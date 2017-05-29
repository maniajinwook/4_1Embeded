#ifndef __PARKING_H__
#define __PARKING_H__

int setupWiringPiGpio(void);
int getSensorData(void);
int controlLed(int distance);

#endif /* __PARKING_H__ */
