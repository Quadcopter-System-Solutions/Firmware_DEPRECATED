/*
  QS Solutions voltageRead.cpp

  Designed to read the voltage of each cell in a 3 cell LiPo battery using an Arduino Nano's Analog Inputs.

  May 5, 2020
  Miguel Manguerra
*/
#include "voltageRead.h"
#include "arduino.h"

float getCellOne(void){
  float sensorValue = analogRead(A0);
  return sensorValue * ADCconversion * cellOneRatio;
}

float getCellTwo(void){
  float sensorValue = analogRead(A1);
  return sensorValue * ADCconversion * cellTwoRatio;
}


float getCellThree(void){
  float sensorValue = analogRead(A2);
  return sensorValue * ADCconversion * cellThreeRatio;
}


bool batteryCheck(void){
  float cellOneVoltage = getCellOne();
  float cellTwoVoltage = getCellTwo();
  float cellThreeVoltage = getCellThree();
  if( (cellOneVoltage || cellTwoVoltage || cellThreeVoltage) <= 3.8){
    return 0;
  }
  return 1;
}
