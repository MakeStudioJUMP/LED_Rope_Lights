#include <FastLED.h>

#define NUM_LEDS 142

#define DATA_PIN 3

CRGB leds[NUM_LEDS];

void setup() { 
// associate fastLED array (leds) in memory to arduino board hardware
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); 
// not full bright to keep drain down, range 0 to 255
    FastLED.setBrightness(15);  
}


int offset = 0;
void loop() { 
  int i,j;
  for(i=0;i<NUM_LEDS;i++) {
    j = i + offset;
    j &= 255;
    leds[i] = CHSV(j,255,255);   // load array with new values
    
  }
  FastLED.show();  // blast array to physical LEDs
  delay(1);
  offset ++;  // shift rainbow by one pixel
  
}
