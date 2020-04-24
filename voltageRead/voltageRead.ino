/*
    QS Solutions voltageRead.c

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

float referenceVoltage = 4.68; //this value is dependent on the Arduino Nano's internal reference voltage and can be measured with a multimeter between ground and the Arduino's 5V output (the default reference voltage)

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(cellTwo, INPUT);
  Serial.begin(9600);
  Serial.print("Begin: \n");
}

void loop() {
  // read the value from the sensor:
  delay(500);
  sensorValue = analogRead(cellTwo);
  voltageTwo =  sensorValue * (referenceVoltage /1023.0);
  Serial.print("The voltage is:");
  Serial.println(voltageTwo);
  delay(500);
}
