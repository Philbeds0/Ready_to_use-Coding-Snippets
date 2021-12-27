

// creo costanti per i valori dei pin
const int pinpulsante = 2; // the number of the switch pin
const int pinmotore =  9; // the number of the motor pin

int cambiostato = 0;  // variabile per leggere il cambiostato

void setup() {
  Serial.begin(9600);
  // pinmotore come output
  pinMode(pinmotore, OUTPUT);
  // pinpulsante come input
  pinMode(pinpulsante, INPUT);
  pinMode(12,OUTPUT);
}

void loop() {
  // leggi se il pulsante è premuto e assegnalo alla variabile cambiostato
  cambiostato = digitalRead(pinpulsante);

  // se il pulsante è premuto 
  if (cambiostato == HIGH) {
    Serial.println("il pulsante è premuto");
    // accendi pompa
    digitalWrite(pinmotore, HIGH);
    digitalWrite(12,HIGH);
  } else {
    // spegni pompa
    digitalWrite(12,LOW);
    digitalWrite(pinmotore, LOW);
  }
}
