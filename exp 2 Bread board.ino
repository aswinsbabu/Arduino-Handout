// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 11 as an output.
  pinMode(Pin number, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(Pin number, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(Pin number, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
