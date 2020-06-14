/*
  QS Solutions sensors.cpp

  Designed to read the data coming from the BMP280 altimeter and the LSM6DSM gyroscope

  May 30, 2020
  Miguel Manguerra & Carter Cooper
*/

#include "sensors.h"
#include "Adafruit_BMP280.h"
#include "LSM6DSLSensor.h"


//global variables to store important data used in other files
float pressure;
float currentAltitude;
float temperature;
float initialAltitude;

//initial declaration of sensor objects
Adafruit_BMP280 altimeter;
Adafruit_Sensor *altimeterTemperature = altimeter.getTemperatureSensor();
Adafruit_Sensor *altimeterPressure = altimeter.getPressureSensor();

LSM6DSLSensor *gyro;
TwoWire *gyroi2c;

void initSensors(void){
  initGyro();
  initAltimeter();
}

void initGyro(void){
  gyroi2c = new TwoWire();
  gyroi2c->begin();

  gyro = new LSM6DSLSensor(gyroi2c, LSM6DSL_ACC_GYRO_I2C_ADDRESS_LOW);
  gyro->Enable_X();
  gyro->Enable_G();
}

struct sensorReading getGyro(void){
  u32 reading[3];
  gyro->Get_G_Axes(reading);

  struct sensorReading result = {reading[0], reading[1], reading[2]};
  
  return result;
}

struct sensorReading getAccel(void){
  u32 reading[3];
  gyro->Get_X_Axes(reading);

  struct sensorReading result = {reading[0], reading[1], reading[2]};
   
  return result;
}

void initAltimeter(void){

  //initial declarations of variables to store important information
  float seaLevelBarometricPressure = 1013.25; // in hPa which is mean sea level pressure (might have to change depending on where we are

  //check to see if altimeter is connected
  if(!altimeter.begin()){
    //add line here to flag an error if no altimeter is connected
  }

  //initializing specific altimeter settings
  altimeter.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                        Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                        Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                        Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                        Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  //initial altitude reading to determine ground level
  initialAltitude = altimeter.readAltitude(seaLevelBarometricPressure);
}

float getPressure(){
  sensors_event_t pressureEvent;
  altimeterPressure->getEvent(&pressureEvent);
  pressure = pressureEvent.pressure;
  return pressure;
}

float getTemperature(){
  sensors_event_t temperatureEvent;
  altimeterTemperature->getEvent(&temperatureEvent);
  temperature = temperatureEvent.temperature;   
  return temperature;
}

float getAltitude(){
    currentAltitude = altimeter.readAltitude(1013.25);   
    return currentAltitude;
}
