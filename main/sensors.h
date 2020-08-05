#ifndef SENSORS
#define SENSORS

#include "arduino.h"

extern u16 errorCode;

void initSensors(void);
void initAltimeter(void);
void initGyro(void);
u32* getAccel(void);
u32* getGyro(void);
float getPressure();
float getAltitude();
float getTemperature();

#endif
