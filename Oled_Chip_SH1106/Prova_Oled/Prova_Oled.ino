#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define SSD1306_128_64
void setup()   {    
          
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);  //Impostare l'indirizzo i2c annotato in precedenza
  display.clearDisplay();  //Pulisce il buffer da inviare al display
  display.setTextSize(1);  //Imposta la grandezza del testo
  display.setTextColor(WHITE); //Imposta il colore del testo (Solo bianco)
  display.setCursor(0,0); //Imposta la posizione del cursore (Larghezza,Altezza)
  display.println("LORENZOCASABURO.IT"); //Stringa da visualizzare
  display.display(); //Invia il buffer da visualizzare al display
}
void loop() {
 
}
