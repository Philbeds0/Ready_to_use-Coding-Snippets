#include <LiquidCrystal_I2C.h>
#include <Stepper.h>
#include <Keypad.h>
#include <Wire.h>

const int FullCycle = 200;
const int A = 60;
const int B = 120;
const int C = 180;
const int D = 240;


const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
LiquidCrystal_I2C lcd(0x21, 16, 2);

void setup(){
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  }
 
void loop(){
  lcd.setCursor(0,0);
  Serial.println("Rotations:");
 
  char entry1 = customKeypad.getKey();
 
  if (entry1){
    Serial.println(entry1);
  }
   


  char entry2 = customKeypad.getKey();

  if(entry2==A){
    Serial.print("42-50cm");
  }

  if(entry2==B){
    Serial.print("32-40cm");
  }

  if(entry2==C){
    Serial.print("22-30cm");
  }

  if(entry2==D){
    Serial.print("8-20cm");
  }



  }

 

