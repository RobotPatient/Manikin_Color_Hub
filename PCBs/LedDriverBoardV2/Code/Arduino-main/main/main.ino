#include "board_definitions.h"
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(STAT_CNT,  LED_STAT,   NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel strip1(STRIP1_CNT, LEDSTRIP_1, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel strip2(STRIP2_CNT, LEDSTRIP_2, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel strip3(STRIP3_CNT, LEDSTRIP_3, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel strip4(STRIP4_CNT, LEDSTRIP_4, NEO_GRBW + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  initPins();

  strip.begin();
  strip.show();
  strip.setBrightness(STAT_BRT);

//  strip1.begin();
//  strip1.show();
//  strip1.setBrightness(STAT_BRT);
//
//  strip2.begin();
//  strip2.show();
//  strip2.setBrightness(STRIP2_BRT);
//  
//  strip3.begin();
//  strip3.show();
//  strip3.setBrightness(STRIP3_BRT);
//
//  strip4.begin();
//  strip4.show();
//  strip4.setBrightness(STRIP4_BRT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //colorWipe(0,0);
  rainbowFade2WhiteStat(5, 5, 0);
  //rainbowFade2White1(5, 5, 0);
//  rainbowFade2White2(5, 5, 0);
//  rainbowFade2White3(5, 5, 0);
//  rainbowFade2White4(5, 5, 0); 
//  digitalWrite(LED_HB, HIGH);
//  digitalWrite(LED_SN, HIGH);
//  digitalWrite(LED_TX, HIGH);
//  digitalWrite(LED_RX, HIGH);
//  delay(500);
//  digitalWrite(LED_HB, LOW);
//  digitalWrite(LED_SN, LOW);
//  digitalWrite(LED_TX, LOW);
//  digitalWrite(LED_RX, LOW);
//  delay(500);
}
