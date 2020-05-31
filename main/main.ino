#include "boardInit.h"
#include "communications.h"
#include "timer.h"
#include "sensors.h"
#include "flight.h"
#include "log.h"
#include "faultHandling.h"
#include "voltageRead.h"

u16 errorCode = 0x0000;

void setup() {

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
