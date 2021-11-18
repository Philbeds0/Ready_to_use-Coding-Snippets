#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 2

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 8


// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
Serial.begin(115200);
  	  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}
void loop() { 
  // Turn the LED on, then pause
  leds[0] = CRGB(139, 0, 0);
  FastLED.show();
  Serial.println("Switch cheeks on");
  delay(1500);
  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
    Serial.println("Switch cheeks Off");
  FastLED.show();
  delay(1500);
}
