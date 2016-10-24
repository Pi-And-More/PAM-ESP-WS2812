#include <Adafruit_NeoPixel.h>

#define CIRCLEPIN 2
#define PIXELCOUNT 12

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(PIXELCOUNT,CIRCLEPIN,
  NEO_GRB+NEO_KHZ800);

byte maxLed = 1;
int direction = 1;

void setup() {
  pixels.begin();
  for(byte i=0;i<PIXELCOUNT;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  }
  pixels.show();
}

void loop() {
  for(byte i=0;i<maxLed;i++){
    pixels.setPixelColor(i, pixels.Color(55,42,0));
  }
  for(byte i=maxLed;i<PIXELCOUNT;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  }
  pixels.show();
  delay(100);
  maxLed = maxLed+direction;
  if (maxLed<1 || maxLed>PIXELCOUNT) {
    direction = -direction;
    maxLed = maxLed+direction;
  }
}

