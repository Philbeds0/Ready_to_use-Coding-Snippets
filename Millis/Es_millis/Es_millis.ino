int ledrosso = 3;
int ledgiallo = 4;
int ledverde = 5;
int ledblu = 6;
int tempodapassare = 4000;
int tempodapassare2 = 500;
int tempo_ora2;

unsigned long tempo_ora;

void setup() {

  Serial.begin (9600);
  pinMode(ledrosso, OUTPUT);
  pinMode(ledgiallo, OUTPUT);
  pinMode(ledverde, OUTPUT);
  pinMode(ledblu, OUTPUT);

}

void loop() {


  Serial.println("Inizia il firmware");
  Serial.println("Accendo il semaforo");
  digitalWrite(ledverde, HIGH);

  tempo_ora = millis();
  
  while (millis() < tempo_ora + tempodapassare) {
    if (millis() >= tempo_ora2 + tempodapassare2) {
      tempo_ora2 += tempodapassare2;
      Serial.print(".");
    }
  }
  
  Serial.println("");
  Serial.print("Accendo il giallo");
  Serial.println("");
  
  digitalWrite(ledverde, LOW);
  digitalWrite(ledgiallo, HIGH);
  
  tempo_ora = millis();

  while (millis() < tempo_ora + tempodapassare) {
    if (millis() >= tempo_ora2 + tempodapassare2) {
      tempo_ora2 += tempodapassare2;
      Serial.print(".");
    }
  }

  digitalWrite(ledgiallo, LOW);
  
  Serial.println("");
  Serial.print("Accendo il rosso");
  Serial.println("");
  
  digitalWrite(ledrosso, HIGH);

  tempo_ora = millis();
  
  while (millis() < tempo_ora + tempodapassare) {
    if (millis() >= tempo_ora2 + tempodapassare2) {
      tempo_ora2 += tempodapassare2;
      Serial.print(".");
    }
  }

  digitalWrite(ledrosso, LOW);
  
  Serial.println("");

  Serial.println("Aspetto prima di iniziare di nuovo");
  tempo_ora = millis();
  
  while (millis() < tempo_ora + tempodapassare2) {
    if (millis() >= tempo_ora2 + tempodapassare2) {
      tempo_ora2 += tempodapassare2;
      Serial.print(".");
    }
  }
  Serial.println("");

}
