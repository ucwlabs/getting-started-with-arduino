/*
  ReadAnalogVoltage

  Reads an analog input on pin A0,the ADC pin. This pin has a maximum value of 1.0V. 
  A voltage divider (R1 and R2) is required to scale the voltage from 3.3V to 1.0V
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +3.3V and ground.
 
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(A0, INPUT); // set pin A0 as input
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 3.3V):
  float voltage = sensorValue * (3.3 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);

  delay(5000);  //delay for 5seconds
}
