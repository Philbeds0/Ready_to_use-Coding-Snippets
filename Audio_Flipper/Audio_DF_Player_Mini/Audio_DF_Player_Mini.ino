/*Codice per Audio, "myDFPlayer.play()" è il comando che fa partire la traccia, e tra le parentesi ci va il
 numero di traccia desiderata. In questo caso il comando è nel setup, e quindi verrà riprodotto una volta sola*/

#include <Arduino.h>
#include <SoftwareSerial.h>

#include <DFPlayerMini_Fast.h>
SoftwareSerial mySerial(11, 10); // A9, A8 sono i pin di collegamento con arduino
DFPlayerMini_Fast myDFPlayer;


void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  myDFPlayer.begin(mySerial);
  myDFPlayer.volume(20); //settaggio del volume, compreso tra 1 e 30
    myDFPlayer.play(1); //riproduci la traccia 1 (chiare le tracce nella SD: 0001, 0002, 003..., 000n)
}

void loop() {
  // put your main code here, to run repeatedly:

}
