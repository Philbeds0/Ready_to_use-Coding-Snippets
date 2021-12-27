#define JOYSTICK_X A0
#define JOYSTICK_Y A1
#define JOYSTICK_BUTTON 7



void setup() {
  Serial.begin(9600);

  Serial.println("The device started, now you can pair it with bluetooth!");
  
  pinMode(JOYSTICK_BUTTON, INPUT_PULLUP);
  pinMode(JOYSTICK_X, INPUT);
  pinMode(JOYSTICK_Y, INPUT);
}

void loop() {

  delay(20);
  
  int x = analogRead(JOYSTICK_X);
  int y = analogRead(JOYSTICK_Y);
  int button = !digitalRead(JOYSTICK_BUTTON);

  Serial.print("X: horizontal" + String(x));
  Serial.print(" - Y: vertical" + String(y));
  Serial.println("  P: tap" + String(button));

  delay(500);
}
