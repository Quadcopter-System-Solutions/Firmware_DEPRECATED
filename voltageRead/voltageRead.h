#ifndef voltageRead.h

#define cellOneRatio 1
#define cellTwoRatio 1030/470
#define cellThreeRatio 890/330

#define referenceVoltage 4.68 //this value is dependent on the Arduino Nano's internal reference voltage and can be measured with a multimeter between ground and the Arduino's 5V output (the default reference voltage)

#define ADCconversion 5/1023

bool batteryCheck(void);
float getCellOne(void);
float getCellTwo(void);
float getCellThree(void);

#endif