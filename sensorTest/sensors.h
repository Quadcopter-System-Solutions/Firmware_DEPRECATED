#ifndef SENSORS
#define SENSORS

#include "arduino.h"

extern u16 errorCode;

void initSensors(void);
void initAltimeter(void);
void initGyro(void);
float getTemperature(void);
float getPressure(void);
float getAltitude(void);
u32* getAccel(void);
u32* getGyro(void);

#endif
