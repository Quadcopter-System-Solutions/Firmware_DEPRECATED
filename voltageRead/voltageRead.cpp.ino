#include "voltageRead.h"

float getCellOne(void){
  float sensorValue = analogRead(cellOne);
  return sensorValue * ADCconversion * cellOneRatio;
}

float getCellTwo(void){
  float sensorValue = analogRead(cellTwo);
  return sensorValue * ADCconversion * cellTwoRatio;
}


float getCellThree(void){
  float sensorValue = analogRead(cellThree);
  return sensorValue * ADCconversion * cellThreeRatio;
}


byte batteryCheck(void){
  float cellOneVoltage = getCellOne();
  float cellTwoVoltage = getCellTwo();
  float cellThreeVoltage = getCellThree();
  if( (cellOneVoltage || cellTwoVoltage || cellThreeVoltage) < = 3.8){
    return 0;
  }
  return 1;
}
