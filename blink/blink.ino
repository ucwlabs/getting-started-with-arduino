
//Declare global variables
int led = 13; // the pin the LED is connected to

void setup() {
  // the setup function runs once when you press reset or power the board
  pinMode(led, OUTPUT) // Declare the LED as an output
}

void loop() {
  // the loop function runs over and over again forever
  digitalWrite(led, HIGH)   // Turn the LED on
  delay(1000);              // wait for a second
  digitalWrite(led, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
