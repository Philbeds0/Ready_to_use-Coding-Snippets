/*
  Arduino Starter Kit example
  Project 5 - Servo Mood Indicator

  This sketch is written to accompany Project 5 in the Arduino Starter Kit

  Parts required:
  - servo motor
  - one 100 uF electrolytic capacitors between positive and negative

  created 13 Sep 2012
  by Scott Fitzgerald

  http://www.arduino.cc/starterKit

  This example code is part of the public domain.
*/

// include the Servo library
#include <Servo.h>

Servo myServo;  // create a servo object


int angle;   // variable to hold the angle for the servo motor

void setup() {
  myServo.attach(9); // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // open a serial connection to your computer
}

void loop() {

  // scale the numbers from the pot
  angle = 0; //Indica l'angolo che vuoi e il servo gira a quell'angolo

  // print out the angle for the servo motor
  Serial.print(", angle: ");
  Serial.println(angle);

  // set the servo position
  myServo.write(angle);

  // wait for the servo to get there
  delay(20000);
}
