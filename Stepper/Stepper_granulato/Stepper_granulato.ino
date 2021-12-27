
//Includi libreria per stepper corretta
#include <AccelStepper.h>
//Definisci costante indicante quanti step ha il motore
#define HALFSTEP 8

// Definisco i pin che manderanno impulso allo stepper
#define motorPin1  2     // IN4 on the ULN2003 driver 1
#define motorPin2  3    // IN3 on the ULN2003 driver 1
#define motorPin3  4     // IN2 on the ULN2003 driver 1
#define motorPin4  5     // IN1 on the ULN2003 driver 1

// Dichiaro lo stepper che chiamo granulato e assegno i pin IN1-IN3-IN2-IN4 al driver 28BYJ-48
AccelStepper granulato(HALFSTEP, motorPin1, motorPin2, motorPin3, motorPin4);

//variabile posizione 0
int casa = 0;
//variabile posizione dove inizia a cadere il granulato (30000 = 7 giri) max 32767 sullo stepper elegoo
int locversare=-5000;


void setup() {
  //Set della velocità massima
  granulato.setMaxSpeed(1000.0);
  //Set dell'accelerazione massima
  granulato.setAcceleration(1000.0);
  //Set della velocità che userò
  granulato.setSpeed(1000);
//Inizio comunicazione seriale
  Serial.begin(9600);
  
  }
  
void loop() 

{  
  //finché la posizione dello stepper non è in posizione di versamento
granulato.runSpeed();

    
 
        
}
