//
// Created by emiel on 01/01/2024.
//

#ifndef CLIO_PLATFORMIO_LEDCONTROL_HPP
#define CLIO_PLATFORMIO_LEDCONTROL_HPP

#include <Arduino.h>
#include "pinDefinitions.h"
#include <Adafruit_NeoPixel.h>

class LedControl{
public:
    LedControl(int ledZone, String animation, uint32_t color, int waitTime, int speed, int length, int rLoops, int wLoops);
    ~LedControl();

private:
    void initStatNeoPixel();
    void initNeoPixelZone1();
    void initNeoPixelZone2();
    void initNeoPixelZone3();
    void initNeoPixelZone4();
    void initNeoPixelZone5();
    void initNeoPixelZone6();

    void colorWipeStat(uint32_t color, int wait);
    void colorWipe1(uint32_t color, int wait);
    void colorWipe2(uint32_t color, int wait);
    void colorWipe3(uint32_t color, int wait);
    void colorWipe4(uint32_t color, int wait);
    void colorWipe5(uint32_t color, int wait);
    void colorWipe6(uint32_t color, int wait);

    void whiteOverRainbowStat(int whiteSpeed, int whiteLength);
    void whiteOverRainbow1(int whiteSpeed, int whiteLength);
    void whiteOverRainbow2(int whiteSpeed, int whiteLength);
    void whiteOverRainbow3(int whiteSpeed, int whiteLength);
    void whiteOverRainbow4(int whiteSpeed, int whiteLength);
    void whiteOverRainbow5(int whiteSpeed, int whiteLength);
    void whiteOverRainbow6(int whiteSpeed, int whiteLength);

    void pulseWhiteStat(uint8_t wait);
    void pulseWhite1(uint8_t wait);
    void pulseWhite2(uint8_t wait);
    void pulseWhite3(uint8_t wait);
    void pulseWhite4(uint8_t wait);
    void pulseWhite5(uint8_t wait);
    void pulseWhite6(uint8_t wait);

    void rainbowFade2WhiteStat(int wait, int rainbowLoops, int whiteLoops);
    void rainbowFade2White1(int wait, int rainbowLoops, int whiteLoops);
    void rainbowFade2White2(int wait, int rainbowLoops, int whiteLoops);
    void rainbowFade2White3(int wait, int rainbowLoops, int whiteLoops);
    void rainbowFade2White4(int wait, int rainbowLoops, int whiteLoops);
    void rainbowFade2White5(int wait, int rainbowLoops, int whiteLoops);
    void rainbowFade2White6(int wait, int rainbowLoops, int whiteLoops);
};

#endif //CLIO_PLATFORMIO_LEDCONTROL_HPP
