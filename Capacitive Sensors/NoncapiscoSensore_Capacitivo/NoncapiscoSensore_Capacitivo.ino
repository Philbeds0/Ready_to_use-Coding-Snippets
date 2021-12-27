//Questo firmware rileva se viene toccata una lamina di alluminio collegata al pin 2
//quando rileva il tocco esegue i+1, se ritocco un'altra volta fa i (che è 1) +1 e quindi 2 e spegne il led

//int led = 12;           // the PWM pin the LED is attached to
//int brightness = 0;    // how bright the LED is
//int fadeAmount = 5;
#include <CapSense.h>
CapSense cs_32_37 = CapSense(32, 37);
CapSense cs_4_2 = CapSense(4, 2);
CapSense cs_51_47 = CapSense(51, 50);

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
//Dichiaro porte seriali dfplayermini
int serial1 = 10;// RX
int serial2 = 11;// TX

SoftwareSerial mySoftwareSerial(serial1, serial2); // RX, TX
DFRobotDFPlayerMini myDFPlayer;


int i = 0;

const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int totaltesta = 0;                  // the running total
int totalpancia = 0;       
int totalschiena = 0;       
int average = 0;                // the average

int inputPin = 0;

void setup()
{
  // pinMode(led, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);



  pinMode(serial1, INPUT);
  pinMode(serial2, OUTPUT);

  mySoftwareSerial.begin(9600);
  Serial.begin(115200);

  Serial.println(F("Initializing DFPlayer ..."));

  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
  }
  else
  {
    Serial.println(F("DFPlayer Mini online."));
  }

  myDFPlayer.volume(10);  //Set volume value. From 0 to 30

  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}
void loop()
{
  
arraytesta();
arrayschiena();
arraypancia();
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
  
  /*long valoretesta = cs_4_2.capSense(30);
  long valoreschiena = cs_32_37.capSense(30);
  long valorepancia = cs_51_47.capSense(30);
  delay(150);
  
  Serial.println(valoretesta);
  Serial.println(valoreschiena);
  Serial.println(valorepancia);
  */
  
  if (totaltesta > 90) {
    Serial.println("Accesotesta");

    myDFPlayer.play(2);  //Play the first mp3
    delay(3000);

  }
  if (totalschiena > 90)
  {
    i++;
    Serial.println("Accesoschiena");
  }
  if (totalpancia > 90)
  {
    i++;
    Serial.println("Accesopancia");
  }

}

void arraytesta(){

  int inputPin = 4;
  // subtract the last reading:
   totaltesta = totaltesta - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = cs_4_2.capSense(30);
  // add the reading to the total:
  totaltesta = totaltesta + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = totaltesta / numReadings;
  // send it to the computer as ASCII digits
  Serial.print("Mediatesta:");
  Serial.println(average);
  delay(1);        // delay in between reads for stability
  // initialize all the readings to 0:
  
  
}
  void arrayschiena(){
  inputPin = 32;
  // subtract the last reading:
  totalschiena = totalschiena - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = cs_32_37.capSense(30);
  // add the reading to the total:
  totalschiena = totalschiena + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = totalschiena / numReadings;
  // send it to the computer as ASCII digits
  Serial.print("Media_schiena:");
  Serial.println(average);
  delay(1);        // delay in between reads for stability
  // initialize all the readings to 0:
 
  
  }
  
  void arraypancia(){
    
  inputPin=51;
  // subtract the last reading:
  totalpancia = totalpancia - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = cs_51_47.capSense(30);
  // add the reading to the total:
  totalpancia = totalpancia + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = totalpancia / numReadings;
  // send it to the computer as ASCII digits
  Serial.print("Media_pancia:");
  Serial.println(average);
  delay(1);        // delay in between reads for stability
  // initialize all the readings to 0:
  
  
  }
