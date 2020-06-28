#include "sensors.h"

extern float pressure;
extern float currentAltitude;
extern float temperature;

#define RED A3
#define GREEN A6
#define BLUE A7


void setup() {
  // put your setup code here, to run once:
  initSensors();
  Serial.begin(9600);
  Serial.println("Begin");
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  
  analogWrite(RED, 255);
  analogWrite(GREEN, 255);
  analogWrite(BLUE, 255);
  
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

struct sensorReading gyro = getGyro();
struct sensorReading accel = getAccel();
  
  Serial.print(F("Gyro: "));
  Serial.print("X: ");
  Serial.print(gyro.x);
  Serial.print("Y: ");
  Serial.print(gyro.y);
  Serial.print("Z: ");
  Serial.print(gyro.z);
  Serial.println(" units???");

  Serial.print(F("Accelerometer: "));
  Serial.print("X: ");
  Serial.print(accel.x);
  Serial.print("Y: ");
  Serial.print(accel.y);
  Serial.print("Z: ");
  Serial.print(accel.z);
  Serial.println(" units???");


  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);
  delay(1000);
  
}
