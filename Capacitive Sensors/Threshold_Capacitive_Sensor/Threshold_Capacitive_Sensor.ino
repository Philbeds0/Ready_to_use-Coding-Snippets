#include <CapacitiveSensor.h>
CapacitiveSensor cs_4_2 = CapacitiveSensor(4,2); //10M Resistor between pins 7 and 8, you may also connect an antenna on pin 8
unsigned long csSum;

void setup() {
    Serial.begin(9600);
}

void loop() {
    CSread();
}

void CSread() {
    long cs = cs_4_2.capacitiveSensor(80); //a: Sensor resolution is set to 80
  if (cs > 100) { //b: Arbitrary number
    csSum += cs;
    Serial.println(cs); 
    if (csSum >= 200) //c: This value is the threshold, a High value means it takes longer to trigger
    {
      Serial.print("Trigger: ");
      Serial.println(csSum);
      if (csSum > 0) { csSum = 0; } //Reset
      cs_4_2.reset_CS_AutoCal(); //Stops readings
    }
  } else {
    csSum = 0; //Timeout caused by bad readings
  }
}
