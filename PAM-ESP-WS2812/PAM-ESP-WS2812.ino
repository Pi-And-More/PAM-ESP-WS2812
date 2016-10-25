////////////////////////////////////////////////////////////////////////////////////
//
//                               PI and more
//                   ESP8266 & WS2812 using Arduino IDE
//
// https://piandmore.wordpress.com/2016/10/07/esp8266-ws2812/
//
////////////////////////////////////////////////////////////////////////////////////
//
// The library from Adafruit which enables the use of the WS2812
// or NeoPixel
//
#include <Adafruit_NeoPixel.h>

//
// The pin the circle of WS2812 leds is connected to
//
#define CIRCLEPIN 2
//
// The number of leds in our circle
//
#define PIXELCOUNT 12

//
// Initialize the Adafruit library
//
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(PIXELCOUNT,CIRCLEPIN,
  NEO_GRB+NEO_KHZ800);

//
// The number of leds lit
//
byte maxLed = 1;
//
// Is the number of leds increasing or decreasing
//
int direction = 1;

void setup() {
  //
  // Start the led string and turn them all off
  //
  pixels.begin();
  for(byte i=0;i<PIXELCOUNT;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  }
  pixels.show();
}

void loop() {
  //
  // Turn the first 'maxLed' leds yellow
  //
  for(byte i=0;i<maxLed;i++){
    pixels.setPixelColor(i, pixels.Color(55,42,0));
  }
  //
  // Set the remaining leds black
  //
  for(byte i=maxLed;i<PIXELCOUNT;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  }
  //
  // Don't forget to call the pixels.show();
  //
  pixels.show();
  delay(100);
  //
  // Determine the next step in number of leds to show
  //
  maxLed = maxLed+direction;
  if (maxLed<1 || maxLed>PIXELCOUNT) {
    direction = -direction;
    maxLed = maxLed+direction;
  }
}

