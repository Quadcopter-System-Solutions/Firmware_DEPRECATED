/*
    QS Solutions voltageRead.ino

    Designed to read the voltage of each cell in a 3 cell LiPo battery using an Arduino Nano's Analog Inputs.

    Miguel Manguerra, Carter Cooper, and Ilya Sharikov
*/
#include "voltageRead.h"

//Global variables to use

int sensorValue = 0;  // variable to store the ADC value coming from the sensor

float voltageOne = 0;  // variable to store the voltage at cell 1
float voltageTwo = 0; // variable to store the voltage at cell 2
float voltageThree = 0; // variable to store the voltage at cell 3


void setup() {
  // declaring Analog Pins 0,1,2 as input pins
  Serial.begin(9600);
  Serial.print("Begin");
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}

void loop() {
  // read the value from the sensor:
  delay(1000);
  
  voltageOne = getCellOne();
  Serial.print(voltageOne);
  Serial.print("\n");
  
  delay(1000);
  
  voltageTwo = getCellTwo();
  Serial.print(voltageTwo);
  Serial.print("\n");
  
  delay(1000);
  
  voltageThree = getCellThree();
  Serial.print(voltageThree);
  Serial.print("\n");

  delay(1000);

}
