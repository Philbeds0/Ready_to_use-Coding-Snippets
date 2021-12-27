#define trigPin 4
#define echoPin 3
#define ledrosso 5
#define ledverde 2

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledrosso, OUTPUT);
  pinMode(ledverde, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 4) {  // This is where the LED On/Off happens     
    digitalWrite(ledrosso,HIGH); // When the Red condition is met, the Green LED should turn off   
    digitalWrite(ledverde,LOW); 
    digitalWrite(9, HIGH); 
    delay(13000);
    digitalWrite(9,LOW);} 
    
    else {     
      digitalWrite(ledrosso,LOW);     
      digitalWrite(ledverde,HIGH);   }  
      if (distance >= 200 || distance <= 0){
    Serial.print("Out of range:");
    Serial.println(distance);
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
