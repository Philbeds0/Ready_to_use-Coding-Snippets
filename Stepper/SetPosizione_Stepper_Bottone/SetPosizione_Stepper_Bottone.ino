#include <AccelStepper.h>
#define HALFSTEP 8

// Motor pin definitions
#define motorPin1  3     // IN1 on the ULN2003 driver 1
#define motorPin2  4     // IN2 on the ULN2003 driver 1
#define motorPin3  2     // IN3 on the ULN2003 driver 1
#define motorPin4  6     // IN4 on the ULN2003 driver 1

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper granulato(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
int bottonepremuto=0;
int locversare = 500;

void setup() {
  granulato.setMaxSpeed(1000.0);
  granulato.setAcceleration(1000.0);
  granulato.setSpeed(200);
  pinMode(11, INPUT);

  
  }
  
void loop() {

  bottonepremuto = digitalRead(11);
while (bottonepremuto == 1){
  granulato.move(locversare);
  granulato.run();
  bottonepremuto = digitalRead(11);
}

}
