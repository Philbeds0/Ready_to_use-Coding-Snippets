#include <CapacitiveSensor.h>
CapacitiveSensor sensore = CapacitiveSensor(4, 2);
 
 const int led = 7;

//int lucentezza = 0; // definisce la variabile “lucentezza” con valore iniziale 0
//int incremento = 5; // definisce la variabile “incremento” con valore 5
 
void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT); // definisce la porta 7 come porta di output
}
 
void loop()
{

  //analogWrite (6, lucentezza); // invia alla porta 9 una tensione pari a (5/255) * lucentezza
  //lucentezza = lucentezza + incremento; // modifica il valore di lucentezza


  long valore = sensore.capacitiveSensor(30);
  Serial.println(valore);
  if (valore > 50)
  
  {digitalWrite(led, HIGH);

  }

 
 else{
 digitalWrite(led, LOW);
  delay(10);
 }
}
