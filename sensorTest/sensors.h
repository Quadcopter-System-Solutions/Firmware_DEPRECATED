#ifndef SENSORS
#define SENSORS

#include "arduino.h"

struct sensorReading
{
  u32 x;
  u32 y;
  u32 z;
};

extern u16 errorCode;

void initSensors(void);
void initAltimeter(void);
void initGyro(void);
float getTemperature(void);
float getPressure(void);
float getAltitude(void);
struct sensorReading getAccel(void);
struct sensorReading getGyro(void);

#endif
