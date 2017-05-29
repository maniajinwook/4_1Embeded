#ifndef __INTRUSIONDETECTION_H__
#define __INTRUSIONDETECTION_H__

int setupWiringPiGpio(void);
int getSensorData(void);
int controlLed(int motion);
int controlRecord(int motion);;

#endif /* _INTRUSIONDETECTION_H_ */
