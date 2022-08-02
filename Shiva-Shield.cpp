/*****************************************************
 * Date: 9 july 2018
 * Written by: Usman Ali Butt
 * Property off: microcontroller-project.com
 * ***************************************************/
#include <ESP8266WiFi.h>
// Include the AccelStepper Library
#include <AccelStepper.h>
 
const char* ssid = "Angel";
const char* password = "12345678";
int Step = 0; //GPIO0---D3 of Nodemcu--Step of stepper motor driver
int Dir  = 2; //GPIO2---D4 of Nodemcu--Direction of stepper motor driver
// Define motor interface type
#define motorInterfaceType 1
// Creates an instance
AccelStepper myStepper(motorInterfaceType, Step, Dir);
void setup() {
  // set the maximum speed, acceleration factor,
  // initial speed and the target position
  myStepper.setMaxSpeed(1000);
  myStepper.setAcceleration(50);
  myStepper.setSpeed(600);
  myStepper.moveTo(200);
}
void loop() {
  // Change direction once the motor reaches target position
  if (myStepper.distanceToGo() == 0) 
    myStepper.moveTo(-myStepper.currentPosition());
  // Move the motor one step
  myStepper.run();
}