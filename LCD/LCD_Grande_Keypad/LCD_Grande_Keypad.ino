/*Board  I2C / TWI pins
Uno, Ethernet A4 (SDA), A5 (SCL)
Mega2560  20 (SDA), 21 (SCL)
Leonardo  2 (SDA), 3 (SCL)
Due 20 (SDA), 21 (SCL), SDA1, SCL1
*/





#include <Wire.h> 
#include <LiquidCrystal_I2C.h>



// Set the LCD address to 0x27 for a 20 chars and 4 line display
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup()
{
   Serial.begin(9600);
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("ciao mondo");
}

void loop()
{



}
