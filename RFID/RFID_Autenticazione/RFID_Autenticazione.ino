
//ACCENSIONE LED CON RFID 

//includo libreria per la comunicazione con device SPI 
#include <SPI.h>
//includo libreria per la comunicazione RFID
#include <RFID.h>


//Pin 53 per 
#define SS_PIN 53
//Pin 5 al reset della scheda RFID
#define RST_PIN 5

// Codice della chiave master
#define masnum0 55
#define masnum1 241
#define masnum2 222
#define masnum3 121
#define masnum4 97


#define ledGreen 36  // Pin su cui colleghiamo il LED Verde
#define ledRed 12  // Pin su cui colleghiamo il LED Rosso

//Assegno schedarfid come RFID aventi pin 53 per ss e reset 7
RFID schedarfid(SS_PIN, RST_PIN); 



    
int sernum0;
int sernum1;
int sernum2;
int sernum3;
int sernum4;

void setup()
{ 
  Serial.begin(9600);   //Apro la comunicazione con il monitor seriale
  SPI.begin(); //Apro la comunicazione SPI
  schedarfid.init();//inizializzo scheda rfid
  
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);

  digitalWrite(ledGreen, LOW);
  Serial.println("Accensione led con RFID Pronto");
}

void loop() {
 

  
  // Rileva un tag...
  if (schedarfid.isCard()) {
      // Legge il seriale...
      if (schedarfid.readCardSerial()) {
        sernum0 = schedarfid.serNum[0];
        sernum1 = schedarfid.serNum[1];
        sernum2 = schedarfid.serNum[2];
        sernum3 = schedarfid.serNum[3];
        sernum4 = schedarfid.serNum[4];
              
                // Se il seriale letto è uguale al seriale master

               if (sernum0 == masnum0 && sernum1 == masnum1 && sernum2 == masnum2 && sernum3 == masnum3 && sernum4 == masnum4)
                         {
                              //controlla se il led è spento e poi stampa il messaggio e accendi la luce verde, aspetta 3000 ms e poi spegnila
                             
                            Serial.println("CHIAVE VALIDA LED ACCESO");
                             digitalWrite(ledGreen, HIGH);
                             delay(3000);
                    digitalWrite(ledGreen, LOW);
            
                } 
                               else {
              
                    Serial.println("Chiave non valida, accendo led rosso");
                    digitalWrite(ledRed, HIGH);
                    delay(3000);
                    digitalWrite(ledRed, LOW);
                    standby();
                                        
                }
                }
                }

}
void standby() {
Serial.println("Accensione led con RFID Pronto"); 
}
