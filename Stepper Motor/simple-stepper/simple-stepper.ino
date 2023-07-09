#include <AccelStepper.h>

// Define stepper motor connections and motor interface type. 
#define dirPin 22
#define stepperPin 23
#define motorInterfaceType 1

// create an instance of the stepper class, specifying the number of steps of the motor and the pins it's attached to
AccelStepper stepper = AccelStepper(motorInterfaceType, stepperPin, dirPin);

int stepsPerRevolution = 3200; // Adjust for 16 microsteps (200 steps * 16 microsteps = 3200)
int speed = 1562; // Calculated speed in full steps per second. Adjust as needed.
int rotationAngle = 360; // rotation angle in degrees. Adjust as needed.

void setup() {
  // Set the maximum speed and acceleration:
  stepper.setMaxSpeed(speed);
  stepper.setAcceleration(speed); // set acceleration to be the same as speed for immediate reach to full speed
}

void loop() {
  // calculate steps based on desired rotation angle
  int steps = (rotationAngle / 360.0) * stepsPerRevolution;

  // Move stepper forward full speed:
  stepper.move(steps);
  while (stepper.distanceToGo() != 0){
    stepper.run();
  }

  // Pause for 3 seconds
  delay(3000);
  
  // Move stepper backward to home position:
  stepper.move(-steps);
  while (stepper.distanceToGo() != 0){
    stepper.run();
  }

  // Pause for 3 seconds
  delay(3000);
}
