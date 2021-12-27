/*
  matrix_1.ino
  Lo sketch mostra in sequenza delle lettere in modo da mostrare la scritta
  "ADRIROBOT"

per generare gli Sprite da visualizzare sulla matrice è possibile utilizzare https://robojax.com/learn/arduino/8x8LED/
  Sono utilizzati i seguenti pin
  Pin +5V           -> Alimentazione modulo
  Pin GND           -> GND
  Pin Digitale D10  -> connesso al pin Din
  Pin Digitale D11  -> connesso al pin CLK
  Pin Digitale D12  -> connesso al pin CS

  Creato il 26/12/2017 da Adriano Gandolfo
  Sito web http://www.adrirobot.it
  Blog http://it.emcelettronica.com/author/adrirobot
  Pagina Facebook https://www.facebook.com/Adrirobot-318949048122955
  Istagram https://www.instagram.com/adrirobot/
  This example code is in the public domain.
*/


#include "LedControl.h"

LedControl lc = LedControl(12, 11, 10, 1);


/* aspettiamo sempre un po' tra gli aggiornamenti del display */
unsigned long delaytime = 1000;

void setup() {
  /*
    Il MAX72XX è in modalità di risparmio energetico all'avvio,
         dobbiamo fare una chiamata di sveglia
  */
  lc.shutdown(0, false);
  /* Imposta la luminosità su valori medi */
  lc.setIntensity(0, 8);
  /* e cancella il display */
  lc.clearDisplay(0);
}

/*
  Questo metodo mostrerà i caratteri per il
  parola "ADRIROBOT" uno dopo l'altro sulla matrice.
  (si utilizza una matrice di 5x7 led per rappresentare i caratteri)
*/
void writeparolaOnMatrix() {
  /* ecco i dati per i caratteri */
  byte spriteSorriso[] = { B00000000, B00000000, B00000000, B10000001, B01000010, B00111100, B00000000, B00000000};
  byte spriteTriste[] = { B00000000, B00000000, B00111100, B01000010, B10000001, B00000000, B00000000, B00000000};
  byte spriteSorpreso[] = { B00000000, B00000000, B00111100, B01000010, B01000010, B01000010, B00111100, B00000000};

  /* ora li mostra uno ad uno con un piccolo ritardo*/
  lc.setRow(0, 0, spriteSorriso[0]);
  lc.setRow(0, 1, spriteSorriso[1]);
  lc.setRow(0, 2, spriteSorriso[2]);
  lc.setRow(0, 3, spriteSorriso[3]);
  lc.setRow(0, 4, spriteSorriso[4]);
  lc.setRow(0, 5, spriteSorriso[5]);
  lc.setRow(0, 6, spriteSorriso[6]);
  lc.setRow(0, 7, spriteSorriso[7]);
  lc.setRow(0, 8, spriteSorriso[8]);
  delay(delaytime);
  lc.setRow(0, 0, spriteTriste[0]);
  lc.setRow(0, 1, spriteTriste[1]);
  lc.setRow(0, 2, spriteTriste[2]);
  lc.setRow(0, 3, spriteTriste[3]);
  lc.setRow(0, 4, spriteTriste[4]);
  lc.setRow(0, 5, spriteTriste[5]);
  lc.setRow(0, 6, spriteTriste[6]);
  lc.setRow(0, 7, spriteTriste[7]);
  lc.setRow(0, 8, spriteTriste[8]);
  delay(delaytime);
  lc.setRow(0, 0, spriteSorpreso[0]);
  lc.setRow(0, 1, spriteSorpreso[1]);
  lc.setRow(0, 2, spriteSorpreso[2]);
  lc.setRow(0, 3, spriteSorpreso[3]);
  lc.setRow(0, 4, spriteSorpreso[4]);
  lc.setRow(0, 5, spriteSorpreso[5]);
  lc.setRow(0, 6, spriteSorpreso[6]);
  lc.setRow(0, 7, spriteSorpreso[7]);
  lc.setRow(0, 8, spriteSorpreso[8]);

  delay(delaytime);


}

void loop() {
  writeparolaOnMatrix();
}
