

// defines pins numbers
const int stepPin = 23; 
const int dirPin = 22; 
int delayMS = 40; 
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}
void loop() {
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4500; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(delayMS); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(delayMS); 
  }
  delay(3000); // One second delay
  
  digitalWrite(dirPin,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 4500; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(delayMS);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(delayMS);
  }
  delay(3000);
}
