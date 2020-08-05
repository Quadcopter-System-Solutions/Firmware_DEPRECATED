#include "boardInit.h"
#include "communications.h"
#include "timer.h"
#include "sensors.h"
#include "flight.h"
#include "log.h"
#include "faultHandling.h"
#include "voltageRead.h"

u16 errorCode = 0x0000;
extern float pressure;
extern float currentAltitude;
extern float temperature;
extern float initialAltitude;
extern u32* gyroReadings;
extern u32* accelReadings;
extern float cellOne;
extern float cellTwo;
extern float cellThree;

#define stepperPhase1 0
#define stepperPhase2 1
#define stepperPhase3 2
#define stepperPhase4 4

#define battCell1 A0
#define battCell2 A1
#define battCell3 A2

#define blue A3

#define M1 3
#define M2 5
#define M3 6
#define M4 9

#define voltageRegulatorEnable 7
#define rfChipSelect 10

void updateGlobalVariables(){
  cellOne = getCellOne();
  cellTwo = getCellTwo();
  cellThree = getCellThree();
  accelReadings = getAccel();
  gyroReadings = getGyro();
  temperature = getTemperature();
  pressure = getPressure();
  currentAltitude = getAltitude();
}

void setup() {
  pinMode(battCell1, INPUT);
  pinMode(battCell2, INPUT);
  pinMode(battCell3, INPUT);

  pinMode(blue, OUTPUT);

  pinMode(stepperPhase1, OUTPUT);
  pinMode(stepperPhase2, OUTPUT);
  pinMode(stepperPhase3, OUTPUT);
  pinMode(stepperPhase4, OUTPUT);

  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);

  pinMode(voltageRegulatorEnable, OUTPUT);
  pinMode(rfChipSelect, OUTPUT);
  
  initBoard();
  initComms();
  initTimer();
  initSensors();
  initMotors();
  initLog();

}

void loop() {

if(goingToCrash())
{
  dont();
}
  
}
