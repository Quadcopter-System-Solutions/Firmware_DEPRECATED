#include "sensors.h"

float pressure;
float currentAltitude;
float temperature;
u32* gyro;
u32* accel;

void setup() {
  // put your setup code here, to run once:
  initSensors();
  Serial.begin(9600);
  Serial.println("Begin");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  pressure = getPressure();
  currentAltitude = getAltitude();
  temperature = getTemperature();

  Serial.println("BMP280 Sensor Test");
  Serial.print(F("Temperature = "));
  Serial.print(temperature);
  Serial.println(" *C");

  Serial.print(F("Pressure = "));
  Serial.print(pressure);
  Serial.println(" hPa");

  Serial.print(F("Altitude = "));
  Serial.print(currentAltitude);
  Serial.println(" m");

  delay(1000);

  gyro = getGyro();
  accel = getAccel();
  
  Serial.print(F("Gyro = "));
  Serial.print(gyro);
  Serial.println(" units???");

  Serial.print(F("Altitude = "));
  Serial.print(accel);
  Serial.println(" units???");

  delay(1000);
  
}
