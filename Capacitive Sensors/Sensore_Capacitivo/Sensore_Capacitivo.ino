//Questo firmware rileva se viene toccata una lamina di alluminio collegata al pin 2
//quando rileva il tocco esegue i+1, se ritocco un'altra volta fa i (che è 1) +1 e quindi 2 e spegne il led

//int led = 12;           // the PWM pin the LED is attached to
//int brightness = 0;    // how bright the LED is
//int fadeAmount = 5; 
#include <CapSense.h>
CapSense cs_32_37 = CapSense(32, 37);
CapSense cs_4_2 = CapSense(4, 2);
CapSense cs_51_47 = CapSense(51, 50);

int i = 0;
void setup()
{
 // pinMode(led, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);


  Serial.begin(9600);
}
void loop()
{
  /*analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 150) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);*/
  
  long valoretesta = cs_4_2.capSense(30);
  long valoreschiena = cs_32_37.capSense(30);
  long valorepancia = cs_51_47.capSense(30);
  delay(150);
  Serial.println(valoretesta);
    Serial.println(valoreschiena);
      Serial.println(valorepancia);
  if (valoretesta > 60)
  {
    i++;
    Serial.println("Accesotesta");
  }
  if (valoreschiena > 60)
  {
    i++;
    Serial.println("Accesoschiena");
  }
  if (valorepancia > 60)
  {
    i++;
    Serial.println("Accesopancia");
  }
  
}
