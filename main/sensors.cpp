/*
  QS Solutions sensors.cpp

  Designed to read the data coming from the BMP280 altimeter and the LSM6DSM gyroscope

  May 30, 2020
  Miguel Manguerra & Carter Cooper
*/

#include "sensors.h"
#include "Adafruit_BMP280.h"
#include "Adafruit_L3GD20_U.h"

Adafruit_L3GD20 gyro;

void initSensors(void){
    
}

void initGyro(void){
  if (!gyro.begin())
  {
    errorCode |= 0x0002;
    return;
  }
}

void initAltimeter(void){

  //initial declarations of variables to store important information
  float pressure;
  float currentAltitude;
  float temperature;
  float initialAltitude;
  float seaLevelBarometricPressure = 1013.25; // in hPa which is mean sea level pressure (might have to change depending on where we are

  //initial declaration of altimeter object
  Adafruit_BMP280 altimeter;
  Adafruit_Sensor *altimeterTemperature = altimeter.getTemperatureSensor();
  Adafruit_Sensor *altimeterPressure = altimeter.getPressureSensor();

  //check to see if altimeter is connected
  if(!altimeter.begin()){
    errorCode = 0x0001;
  }

  //initializing specific altimeter settings
  altimeter.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                        Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                        Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                        Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                        Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  //initial altitude reading to determine ground level
  initialAltitude = altimeter.readAltitude(1013.25);

  //loop to continuously get pressure and temperature
  while(1){
  sensors_event_t temperatureEvent, pressureEvent;
  altimeterTemperature->getEvent(&temperatureEvent);
  altimeterPressure->getEvent(&pressureEvent);

  pressure = pressureEvent.pressure;
  temperature = temperatureEvent.temperature;
  
  currentAltitude = altimeter.readAltitude(1013.25);
  }
  
                        
}
