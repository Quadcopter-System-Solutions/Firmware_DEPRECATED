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
