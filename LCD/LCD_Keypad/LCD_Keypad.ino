

/* Pilotare un LCD 16x2 con Arduino
Collegamenti dell'LCD per funzionamento a 4 bit:
VSS -> GND
VDD -> +5v
V0 -> al potenziometro
RS -> Arduino D12
R/W -> GND
E -> Arduino D11
D0 -> N/C
D1 -> N/C
D2 -> N/C
D3 -> N/C
D4 -> Arduino D2
D5 -> Arduino D3
D6 -> Arduino D4
D7 -> Arduino D5
A -> Arduino A0
K -> GND
*/

 
// includiamo la libreria
#include <LiquidCrystal.h>
#include <Keypad.h>


 
// Creiamo l'oggetto "lcd" inizializzandolo come richiesto dalla libreria, ovvero:
// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

const byte ROWS = 4; 
const byte COLS = 4; 



char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {23, 25, 27, 29}; 
byte colPins[COLS] = {31, 33, 35, 37}; 
char key= NO_KEY;
Keypad tastierino = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
 
 
void setup() {
 Serial.begin(9600);
// impostiamo ad output l'uscita per la retroilluminazione
pinMode(A0, OUTPUT);

 
//impostiamo numero di colonne e righe dell'lcd a (colonne, righe)
lcd.begin(16, 2);
 
// Visualizziamo un messaggio sul display
//lcd.setCursor(0, 1);
//lcd.print("errore scansione"); //inserire il codice"); 
//lcd.setCursor(0, 1);
//lcd.print("inserire codice");
 
}
 
void loop() {
 
// posizioniamo il cursore a (colonna, riga)
// nota: (0, 1) significa prima colonna e seconda riga, poichè il conteggio parte da 0
//lcd.setCursor(0, 1);
//lcd.setCursor(1,1);
 
// Visualizziamo il conteggio dei secondi
// lcd.print(millis()/1000);
 
// Accendiamo la retroilluminazione
digitalWrite(A0, HIGH);


lcd.print("Premere ok per");
  lcd.setCursor(0, 1);
  lcd.print("iniziare");
  Serial.println("ziocan");

  while(key==NO_KEY)
{
  key = tastierino.getKey();

  }

  
  lcd.clear();

  if (key != NO_KEY){
 lcd.clear();
    lcd.print(key);
    lcd.print(".");
     Serial.println("sonoinloop");
   switch (key)
    {
         case '2':
        lcd.print("viti 5 mm");
        delay(5000); 
        
        key = tastierino.getKey();
        
        while(key==NO_KEY){
        lcd.setCursor(0, 1);
        lcd.print("quante ne vuoi?");
        }
        lcd.print(key);
        int numerodaerogare= key;
        stepper= muoviti x numerodaerogare;
         break;
         
Serial.println("sonoinloop");
        }

    
  }

}
