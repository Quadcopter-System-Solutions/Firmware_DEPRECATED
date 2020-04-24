/*
    QS Solutions voltageRead.ino

    Designed to read the voltage of each cell in a 3 cell LiPo battery using an Arduino Nano's Analog Inputs.

    Miguel Manguerra, Carter Cooper, and Ilya Sharikov
*/

//Global variables to use
int cellOne = A0; // input pin for cell 1
int cellTwo = A1; // input pin for cell 2
int cellThree = A2; // input pin for cell 3

int sensorValue = 0;  // variable to store the ADC value coming from the sensor

float voltageOne = 0;  // variable to store the voltage at cell 1
float voltageTwo = 0; // variable to store the voltage at cell 2
float voltageThree = 0; // variable to store the voltage at cell 3

float cellOneRatio = 1; // voltage divider ratio of cell one to convert the voltage read to the actual cell voltage
float cellTwoRatio = 1030.0/470.0; // voltage divider ratio of cell two to convert the voltage read to the actual cell voltage
float cellThreeRatio = 890.0/330.0; // voltage divider ratio of cell three to convert the voltage read to the actual cell voltage

float referenceVoltage = 4.68; //this value is dependent on the Arduino Nano's internal reference voltage and can be measured with a multimeter between ground and the Arduino's 5V output (the default reference voltage)
float ADCconversion = referenceVoltage/1023.0; //

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(cellOne, INPUT);
  pinMode(cellTwo, INPUT);
  pinMode(cellThree, INPUT);
  Serial.begin(9600);
  Serial.print("Begin Sketch: \n");
}

void loop() {
  // read the value from the sensor:
  delay(1000);
  
  sensorValue = analogRead(cellOne);
  voltageOne =  sensorValue * ADCconversion * cellOneRatio;
  
  delay(500);
  
  sensorValue = analogRead(cellTwo);
  voltageTwo = sensorValue * ADCconversion * cellTwoRatio;
  
  delay(500);
  
  sensorValue = analogRead(cellThree);
  voltageThree = sensorValue * ADCconversion * cellThreeRatio;
  
  delay(500);
  
  Serial.print("The voltage in Cell 1 is ");
  Serial.println(voltageOne);
  Serial.print("\n");

  Serial.print("The voltage in Cell 2 is ");
  Serial.println(voltageTwo);
  Serial.print("\n");
  
  Serial.print("The voltage in Cells 3 is ");
  Serial.println(voltageThree);
  Serial.print("\n");
  
  delay(1000);
}
