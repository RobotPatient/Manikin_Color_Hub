//
// Created by emiel on 01/01/2024.
//

#include "ledControl.h"

Adafruit_NeoPixel stat(StatCount,  StatNeoPixel,   NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel zone1(Zone1Count, NeoPixelZone1, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel zone2(Zone2Count, NeoPixelZone2, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel zone3(Zone3Count, NeoPixelZone3, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel zone4(Zone4Count, NeoPixelZone4, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel zone5(Zone5Count, NeoPixelZone5, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel zone6(Zone6Count, NeoPixelZone6, NEO_GRBW + NEO_KHZ800);

LedControl::LedControl(int ledZone, String animation, uint32_t color, int waitTime, int speed, int length, int rLoops, int wLoops)
{
    switch (ledZone) {
        case 1:
            initNeoPixelZone1();
            if (animation == "colorWipe")
            {
                colorWipe1(color, waitTime);
            }
            else if (animation == "whiteOverRainbow")
            {
                whiteOverRainbow1(speed, length);
            }
            else if (animation == "pulseWhite")
            {
                pulseWhite1(waitTime);
            }
            else if (animation == "rainbowFade2White")
            {
                rainbowFade2White1(waitTime, rLoops, wLoops);
            }
            else
            {
                //do stuff
                puts("Error: no animation selected");
            }
            break;
        case 2:
            initNeoPixelZone2();
            if (animation == "colorWipe")
            {
                colorWipe2(color, waitTime);
            }
            else if (animation == "whiteOverRainbow")
            {
                whiteOverRainbow2(speed, length);
            }
            else if (animation == "pulseWhite")
            {
                pulseWhite2(waitTime);
            }
            else if (animation == "rainbowFade2White")
            {
                rainbowFade2White2(waitTime, rLoops, wLoops);
            }
            else
            {
                //do stuff
                puts("Error: no animation selected");
            }
            break;
        case 3:
            initNeoPixelZone3();
            if (animation == "colorWipe")
            {
                colorWipe3(color, waitTime);
            }
            else if (animation == "whiteOverRainbow")
            {
                whiteOverRainbow3(speed, length);
            }
            else if (animation == "pulseWhite")
            {
                pulseWhite3(waitTime);
            }
            else if (animation == "rainbowFade2White")
            {
                rainbowFade2White3(waitTime, rLoops, wLoops);
            }
            else
            {
                //do stuff
                puts("Error: no animation selected");
            }
            break;
        case 4:
            initNeoPixelZone4();
            if (animation == "colorWipe")
            {
                colorWipe4(color, waitTime);
            }
            else if (animation == "whiteOverRainbow")
            {
                whiteOverRainbow4(speed, length);
            }
            else if (animation == "pulseWhite")
            {
                pulseWhite4(waitTime);
            }
            else if (animation == "rainbowFade2White")
            {
                rainbowFade2White4(waitTime, rLoops, wLoops);
            }
            else
            {
                //do stuff
                puts("Error: no animation selected");
            }
            break;
        case 5:
            initNeoPixelZone5();
            if (animation == "colorWipe")
            {
                colorWipe5(color, waitTime);
            }
            else if (animation == "whiteOverRainbow")
            {
                whiteOverRainbow5(speed, length);
            }
            else if (animation == "pulseWhite")
            {
                pulseWhite5(waitTime);
            }
            else if (animation == "rainbowFade2White")
            {
                rainbowFade2White5(waitTime, rLoops, wLoops);
            }
            else
            {
                //do stuff
                puts("Error: no animation selected");
            }
            break;
        case 6:
            initNeoPixelZone6();
            if (animation == "colorWipe")
            {
                colorWipe6(color, waitTime);
            }
            else if (animation == "whiteOverRainbow")
            {
                whiteOverRainbow6(speed, length);
            }
            else if (animation == "pulseWhite")
            {
                pulseWhite6(waitTime);
            }
            else if (animation == "rainbowFade2White")
            {
                rainbowFade2White6(waitTime, rLoops, wLoops);
            }
            else
            {
                //do stuff
                puts("Error: no animation selected");
            }
            break;
        case 7:
            initStatNeoPixel();
            if (animation == "colorWipe")
            {
                colorWipeStat(color, waitTime);
            }
            else if (animation == "whiteOverRainbow")
            {
                whiteOverRainbowStat(speed, length);
            }
            else if (animation == "pulseWhite")
            {
                pulseWhiteStat(waitTime);
            }
            else if (animation == "rainbowFade2White")
            {
                rainbowFade2WhiteStat(waitTime, rLoops, wLoops);
            }
            else
            {
                //do stuff
                puts("Error: no animation selected");
            }
            break;
//        default:
//            //do stuff
    }
}

/**
 * Initializing functions for the NeoPixel leds
 */

void LedControl::initStatNeoPixel()
{
    stat.begin();
    stat.show();
    stat.setBrightness(StatBrightness);
}

void LedControl::initNeoPixelZone1()
{
    zone1.begin();
    zone1.show();
    zone1.setBrightness(NeoPixelZone1);
}

void LedControl::initNeoPixelZone2()
{
    zone2.begin();
    zone2.show();
    zone2.setBrightness(NeoPixelZone2);
}

void LedControl::initNeoPixelZone3()
{
    zone3.begin();
    zone3.show();
    zone3.setBrightness(NeoPixelZone3);
}

void LedControl::initNeoPixelZone4()
{
    zone4.begin();
    zone4.show();
    zone4.setBrightness(NeoPixelZone4);
}

void LedControl::initNeoPixelZone5()
{
    zone5.begin();
    zone5.show();
    zone5.setBrightness(NeoPixelZone5);
}

void LedControl::initNeoPixelZone6()
{
    zone6.begin();
    zone6.show();
    zone6.setBrightness(NeoPixelZone6);
}

/**
 * Led animations
 */

void LedControl::colorWipeStat(uint32_t color, int wait) {
    for(int i=0; i<stat.numPixels(); i++) { // For each pixel in strip...
        stat.setPixelColor(i, color);         //  Set pixel's color (in RAM)
        stat.show();                          //  Update strip to match
        delay(wait);                           //  Pause for a moment
    }
}

void LedControl::colorWipe1(uint32_t color, int wait) {
    for(int i=0; i<zone1.numPixels(); i++) { // For each pixel in strip...
        zone1.setPixelColor(i, color);         //  Set pixel's color (in RAM)
        zone1.show();                          //  Update strip to match
        delay(wait);                           //  Pause for a moment
    }
}

void LedControl::colorWipe2(uint32_t color, int wait) {
    for(int i=0; i<zone2.numPixels(); i++) { // For each pixel in strip...
        zone2.setPixelColor(i, color);         //  Set pixel's color (in RAM)
        zone2.show();                          //  Update strip to match
        delay(wait);                           //  Pause for a moment
    }
}

void LedControl::colorWipe3(uint32_t color, int wait) {
    for(int i=0; i<zone3.numPixels(); i++) { // For each pixel in strip...
        zone3.setPixelColor(i, color);         //  Set pixel's color (in RAM)
        zone3.show();                          //  Update strip to match
        delay(wait);                           //  Pause for a moment
    }
}

void LedControl::colorWipe4(uint32_t color, int wait) {
    for(int i=0; i<zone4.numPixels(); i++) { // For each pixel in strip...
        zone4.setPixelColor(i, color);         //  Set pixel's color (in RAM)
        zone4.show();                          //  Update strip to match
        delay(wait);                           //  Pause for a moment
    }
}

void LedControl::colorWipe5(uint32_t color, int wait) {
    for(int i=0; i<zone5.numPixels(); i++) { // For each pixel in strip...
        zone5.setPixelColor(i, color);         //  Set pixel's color (in RAM)
        zone5.show();                          //  Update strip to match
        delay(wait);                           //  Pause for a moment
    }
}

void LedControl::colorWipe6(uint32_t color, int wait) {
    for(int i=0; i<zone6.numPixels(); i++) { // For each pixel in strip...
        zone6.setPixelColor(i, color);         //  Set pixel's color (in RAM)
        zone6.show();                          //  Update strip to match
        delay(wait);                           //  Pause for a moment
    }
}




void LedControl::whiteOverRainbowStat(int whiteSpeed, int whiteLength) {

    if(whiteLength >= stat.numPixels()) whiteLength = stat.numPixels() - 1;

    int      head          = whiteLength - 1;
    int      tail          = 0;
    int      loops         = 3;
    int      loopNum       = 0;
    uint32_t lastTime      = millis();
    uint32_t firstPixelHue = 0;

    for(;;) { // Repeat forever (or until a 'break' or 'return')
        for(int i=0; i<stat.numPixels(); i++) {  // For each pixel in strip...
            if(((i >= tail) && (i <= head)) ||      //  If between head & tail...
               ((tail > head) && ((i >= tail) || (i <= head)))) {
                stat.setPixelColor(i, stat.Color(0, 0, 0, 255)); // Set white
            } else {                                             // else set rainbow
                int pixelHue = firstPixelHue + (i * 65536L / stat.numPixels());
                stat.setPixelColor(i, stat.gamma32(stat.ColorHSV(pixelHue)));
            }
        }

        stat.show(); // Update strip with new contents
        // There's no delay here, it just runs full-tilt until the timer and
        // counter combination below runs out.

        firstPixelHue += 40; // Advance just a little along the color wheel

        if((millis() - lastTime) > whiteSpeed) { // Time to update head/tail?
            if(++head >= stat.numPixels()) {      // Advance head, wrap around
                head = 0;
                if(++loopNum >= loops) return;
            }
            if(++tail >= stat.numPixels()) {      // Advance tail, wrap around
                tail = 0;
            }
            lastTime = millis();                   // Save time of last movement
        }
    }
}

void LedControl::whiteOverRainbow1(int whiteSpeed, int whiteLength) {

    if(whiteLength >= zone1.numPixels()) whiteLength = zone1.numPixels() - 1;

    int      head          = whiteLength - 1;
    int      tail          = 0;
    int      loops         = 3;
    int      loopNum       = 0;
    uint32_t lastTime      = millis();
    uint32_t firstPixelHue = 0;

    for(;;) { // Repeat forever (or until a 'break' or 'return')
        for(int i=0; i<zone1.numPixels(); i++) {  // For each pixel in strip...
            if(((i >= tail) && (i <= head)) ||      //  If between head & tail...
               ((tail > head) && ((i >= tail) || (i <= head)))) {
                zone1.setPixelColor(i, zone1.Color(0, 0, 0, 255)); // Set white
            } else {                                             // else set rainbow
                int pixelHue = firstPixelHue + (i * 65536L / zone1.numPixels());
                zone1.setPixelColor(i, zone1.gamma32(zone1.ColorHSV(pixelHue)));
            }
        }

        zone1.show(); // Update strip with new contents
        // There's no delay here, it just runs full-tilt until the timer and
        // counter combination below runs out.

        firstPixelHue += 40; // Advance just a little along the color wheel

        if((millis() - lastTime) > whiteSpeed) { // Time to update head/tail?
            if(++head >= zone1.numPixels()) {      // Advance head, wrap around
                head = 0;
                if(++loopNum >= loops) return;
            }
            if(++tail >= zone1.numPixels()) {      // Advance tail, wrap around
                tail = 0;
            }
            lastTime = millis();                   // Save time of last movement
        }
    }
}

void LedControl::whiteOverRainbow2(int whiteSpeed, int whiteLength) {

    if(whiteLength >= zone2.numPixels()) whiteLength = zone2.numPixels() - 1;

    int      head          = whiteLength - 1;
    int      tail          = 0;
    int      loops         = 3;
    int      loopNum       = 0;
    uint32_t lastTime      = millis();
    uint32_t firstPixelHue = 0;

    for(;;) { // Repeat forever (or until a 'break' or 'return')
        for(int i=0; i<zone2.numPixels(); i++) {  // For each pixel in strip...
            if(((i >= tail) && (i <= head)) ||      //  If between head & tail...
               ((tail > head) && ((i >= tail) || (i <= head)))) {
                zone2.setPixelColor(i, zone2.Color(0, 0, 0, 255)); // Set white
            } else {                                             // else set rainbow
                int pixelHue = firstPixelHue + (i * 65536L / zone2.numPixels());
                zone2.setPixelColor(i, zone2.gamma32(zone2.ColorHSV(pixelHue)));
            }
        }

        zone2.show(); // Update strip with new contents
        // There's no delay here, it just runs full-tilt until the timer and
        // counter combination below runs out.

        firstPixelHue += 40; // Advance just a little along the color wheel

        if((millis() - lastTime) > whiteSpeed) { // Time to update head/tail?
            if(++head >= zone2.numPixels()) {      // Advance head, wrap around
                head = 0;
                if(++loopNum >= loops) return;
            }
            if(++tail >= zone2.numPixels()) {      // Advance tail, wrap around
                tail = 0;
            }
            lastTime = millis();                   // Save time of last movement
        }
    }
}

void LedControl::whiteOverRainbow3(int whiteSpeed, int whiteLength) {

    if(whiteLength >= zone3.numPixels()) whiteLength = zone3.numPixels() - 1;

    int      head          = whiteLength - 1;
    int      tail          = 0;
    int      loops         = 3;
    int      loopNum       = 0;
    uint32_t lastTime      = millis();
    uint32_t firstPixelHue = 0;

    for(;;) { // Repeat forever (or until a 'break' or 'return')
        for(int i=0; i<zone3.numPixels(); i++) {  // For each pixel in strip...
            if(((i >= tail) && (i <= head)) ||      //  If between head & tail...
               ((tail > head) && ((i >= tail) || (i <= head)))) {
                zone3.setPixelColor(i, zone3.Color(0, 0, 0, 255)); // Set white
            } else {                                             // else set rainbow
                int pixelHue = firstPixelHue + (i * 65536L / zone3.numPixels());
                zone3.setPixelColor(i, zone3.gamma32(zone3.ColorHSV(pixelHue)));
            }
        }

        zone3.show(); // Update strip with new contents
        // There's no delay here, it just runs full-tilt until the timer and
        // counter combination below runs out.

        firstPixelHue += 40; // Advance just a little along the color wheel

        if((millis() - lastTime) > whiteSpeed) { // Time to update head/tail?
            if(++head >= zone3.numPixels()) {      // Advance head, wrap around
                head = 0;
                if(++loopNum >= loops) return;
            }
            if(++tail >= zone3.numPixels()) {      // Advance tail, wrap around
                tail = 0;
            }
            lastTime = millis();                   // Save time of last movement
        }
    }
}

void LedControl::whiteOverRainbow4(int whiteSpeed, int whiteLength) {

    if(whiteLength >= zone4.numPixels()) whiteLength = zone4.numPixels() - 1;

    int      head          = whiteLength - 1;
    int      tail          = 0;
    int      loops         = 3;
    int      loopNum       = 0;
    uint32_t lastTime      = millis();
    uint32_t firstPixelHue = 0;

    for(;;) { // Repeat forever (or until a 'break' or 'return')
        for(int i=0; i<zone4.numPixels(); i++) {  // For each pixel in strip...
            if(((i >= tail) && (i <= head)) ||      //  If between head & tail...
               ((tail > head) && ((i >= tail) || (i <= head)))) {
                zone4.setPixelColor(i, zone4.Color(0, 0, 0, 255)); // Set white
            } else {                                             // else set rainbow
                int pixelHue = firstPixelHue + (i * 65536L / zone4.numPixels());
                zone4.setPixelColor(i, zone4.gamma32(zone4.ColorHSV(pixelHue)));
            }
        }

        zone4.show(); // Update strip with new contents
        // There's no delay here, it just runs full-tilt until the timer and
        // counter combination below runs out.

        firstPixelHue += 40; // Advance just a little along the color wheel

        if((millis() - lastTime) > whiteSpeed) { // Time to update head/tail?
            if(++head >= zone4.numPixels()) {      // Advance head, wrap around
                head = 0;
                if(++loopNum >= loops) return;
            }
            if(++tail >= zone4.numPixels()) {      // Advance tail, wrap around
                tail = 0;
            }
            lastTime = millis();                   // Save time of last movement
        }
    }
}

void LedControl::whiteOverRainbow5(int whiteSpeed, int whiteLength) {

    if(whiteLength >= zone5.numPixels()) whiteLength = zone5.numPixels() - 1;

    int      head          = whiteLength - 1;
    int      tail          = 0;
    int      loops         = 3;
    int      loopNum       = 0;
    uint32_t lastTime      = millis();
    uint32_t firstPixelHue = 0;

    for(;;) { // Repeat forever (or until a 'break' or 'return')
        for(int i=0; i<zone5.numPixels(); i++) {  // For each pixel in strip...
            if(((i >= tail) && (i <= head)) ||      //  If between head & tail...
               ((tail > head) && ((i >= tail) || (i <= head)))) {
                zone5.setPixelColor(i, zone5.Color(0, 0, 0, 255)); // Set white
            } else {                                             // else set rainbow
                int pixelHue = firstPixelHue + (i * 65536L / zone5.numPixels());
                zone5.setPixelColor(i, zone5.gamma32(zone5.ColorHSV(pixelHue)));
            }
        }

        zone5.show(); // Update strip with new contents
        // There's no delay here, it just runs full-tilt until the timer and
        // counter combination below runs out.

        firstPixelHue += 40; // Advance just a little along the color wheel

        if((millis() - lastTime) > whiteSpeed) { // Time to update head/tail?
            if(++head >= zone5.numPixels()) {      // Advance head, wrap around
                head = 0;
                if(++loopNum >= loops) return;
            }
            if(++tail >= zone5.numPixels()) {      // Advance tail, wrap around
                tail = 0;
            }
            lastTime = millis();                   // Save time of last movement
        }
    }
}

void LedControl::whiteOverRainbow6(int whiteSpeed, int whiteLength) {

    if(whiteLength >= zone6.numPixels()) whiteLength = zone6.numPixels() - 1;

    int      head          = whiteLength - 1;
    int      tail          = 0;
    int      loops         = 3;
    int      loopNum       = 0;
    uint32_t lastTime      = millis();
    uint32_t firstPixelHue = 0;

    for(;;) { // Repeat forever (or until a 'break' or 'return')
        for(int i=0; i<zone6.numPixels(); i++) {  // For each pixel in strip...
            if(((i >= tail) && (i <= head)) ||      //  If between head & tail...
               ((tail > head) && ((i >= tail) || (i <= head)))) {
                zone6.setPixelColor(i, zone6.Color(0, 0, 0, 255)); // Set white
            } else {                                             // else set rainbow
                int pixelHue = firstPixelHue + (i * 65536L / zone6.numPixels());
                zone6.setPixelColor(i, zone6.gamma32(zone6.ColorHSV(pixelHue)));
            }
        }

        zone6.show(); // Update strip with new contents
        // There's no delay here, it just runs full-tilt until the timer and
        // counter combination below runs out.

        firstPixelHue += 40; // Advance just a little along the color wheel

        if((millis() - lastTime) > whiteSpeed) { // Time to update head/tail?
            if(++head >= zone6.numPixels()) {      // Advance head, wrap around
                head = 0;
                if(++loopNum >= loops) return;
            }
            if(++tail >= zone6.numPixels()) {      // Advance tail, wrap around
                tail = 0;
            }
            lastTime = millis();                   // Save time of last movement
        }
    }
}



void LedControl::pulseWhiteStat(uint8_t wait) {
    for(int j=0; j<256; j++) { // Ramp up from 0 to 255
        // Fill entire strip with white at gamma-corrected brightness level 'j':
        stat.fill(stat.Color(0, 0, 0, stat.gamma8(j)));
        stat.show();
        delay(wait);
    }

    for(int j=255; j>=0; j--) { // Ramp down from 255 to 0
        stat.fill(stat.Color(0, 0, 0, stat.gamma8(j)));
        stat.show();
        delay(wait);
    }
}

void LedControl::pulseWhite1(uint8_t wait) {
    for(int j=0; j<256; j++) { // Ramp up from 0 to 255
        // Fill entire strip with white at gamma-corrected brightness level 'j':
        zone1.fill(zone1.Color(0, 0, 0, zone1.gamma8(j)));
        zone1.show();
        delay(wait);
    }

    for(int j=255; j>=0; j--) { // Ramp down from 255 to 0
        zone1.fill(zone1.Color(0, 0, 0, zone1.gamma8(j)));
        zone1.show();
        delay(wait);
    }
}

void LedControl::pulseWhite2(uint8_t wait) {
    for(int j=0; j<256; j++) { // Ramp up from 0 to 255
        // Fill entire strip with white at gamma-corrected brightness level 'j':
        zone2.fill(zone2.Color(0, 0, 0, zone2.gamma8(j)));
        zone2.show();
        delay(wait);
    }

    for(int j=255; j>=0; j--) { // Ramp down from 255 to 0
        zone2.fill(zone2.Color(0, 0, 0, zone2.gamma8(j)));
        zone2.show();
        delay(wait);
    }
}

void LedControl::pulseWhite3(uint8_t wait) {
    for(int j=0; j<256; j++) { // Ramp up from 0 to 255
        // Fill entire strip with white at gamma-corrected brightness level 'j':
        zone3.fill(zone3.Color(0, 0, 0, zone3.gamma8(j)));
        zone3.show();
        delay(wait);
    }

    for(int j=255; j>=0; j--) { // Ramp down from 255 to 0
        zone3.fill(zone3.Color(0, 0, 0, zone3.gamma8(j)));
        zone3.show();
        delay(wait);
    }
}

void LedControl::pulseWhite4(uint8_t wait) {
    for(int j=0; j<256; j++) { // Ramp up from 0 to 255
        // Fill entire strip with white at gamma-corrected brightness level 'j':
        zone4.fill(zone4.Color(0, 0, 0, zone4.gamma8(j)));
        zone4.show();
        delay(wait);
    }

    for(int j=255; j>=0; j--) { // Ramp down from 255 to 0
        zone4.fill(zone4.Color(0, 0, 0, zone4.gamma8(j)));
        zone4.show();
        delay(wait);
    }
}

void LedControl::pulseWhite5(uint8_t wait) {
    for(int j=0; j<256; j++) { // Ramp up from 0 to 255
        // Fill entire strip with white at gamma-corrected brightness level 'j':
        zone5.fill(zone5.Color(0, 0, 0, zone5.gamma8(j)));
        zone5.show();
        delay(wait);
    }

    for(int j=255; j>=0; j--) { // Ramp down from 255 to 0
        zone5.fill(zone5.Color(0, 0, 0, zone5.gamma8(j)));
        zone5.show();
        delay(wait);
    }
}

void LedControl::pulseWhite6(uint8_t wait) {
    for(int j=0; j<256; j++) { // Ramp up from 0 to 255
        // Fill entire strip with white at gamma-corrected brightness level 'j':
        zone6.fill(zone6.Color(0, 0, 0, zone6.gamma8(j)));
        zone6.show();
        delay(wait);
    }

    for(int j=255; j>=0; j--) { // Ramp down from 255 to 0
        zone6.fill(zone6.Color(0, 0, 0, zone6.gamma8(j)));
        zone6.show();
        delay(wait);
    }
}



void LedControl::rainbowFade2WhiteStat(int wait, int rainbowLoops, int whiteLoops) {
    int fadeVal=0, fadeMax=100;

    // Hue of first pixel runs 'rainbowLoops' complete loops through the color
    // wheel. Color wheel has a range of 65536 but it's OK if we roll over, so
    // just count from 0 to rainbowLoops*65536, using steps of 256 so we
    // advance around the wheel at a decent clip.
    for(uint32_t firstPixelHue = 0; firstPixelHue < rainbowLoops*65536;
        firstPixelHue += 256) {

        for(int i=0; i<stat.numPixels(); i++) { // For each pixel in strip...

            // Offset pixel hue by an amount to make one full revolution of the
            // color wheel (range of 65536) along the length of the strip
            // (strip.numPixels() steps):
            uint32_t pixelHue = firstPixelHue + (i * 65536L / stat.numPixels());

            // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
            // optionally add saturation and value (brightness) (each 0 to 255).
            // Here we're using just the three-argument variant, though the
            // second value (saturation) is a constant 255.
            stat.setPixelColor(i, stat.gamma32(stat.ColorHSV(pixelHue, 255,
                                                                255 * fadeVal / fadeMax)));
        }

        stat.show();
        delay(wait);

        if(firstPixelHue < 65536) {                              // First loop,
            if(fadeVal < fadeMax) fadeVal++;                       // fade in
        } else if(firstPixelHue >= ((rainbowLoops-1) * 65536)) { // Last loop,
            if(fadeVal > 0) fadeVal--;                             // fade out
        } else {
            fadeVal = fadeMax; // Interim loop, make sure fade is at max
        }
    }

    for(int k=0; k<whiteLoops; k++) {
        for(int j=0; j<256; j++) { // Ramp up 0 to 255
            // Fill entire strip with white at gamma-corrected brightness level 'j':
            stat.fill(stat.Color(0, 0, 0, stat.gamma8(j)));
            stat.show();
        }
        delay(1000); // Pause 1 second
        for(int j=255; j>=0; j--) { // Ramp down 255 to 0
            stat.fill(stat.Color(0, 0, 0, stat.gamma8(j)));
            stat.show();
        }
    }

    //delay(500); // Pause 1/2 second
}

void LedControl::rainbowFade2White1(int wait, int rainbowLoops, int whiteLoops) {
    int fadeVal=0, fadeMax=100;

    // Hue of first pixel runs 'rainbowLoops' complete loops through the color
    // wheel. Color wheel has a range of 65536 but it's OK if we roll over, so
    // just count from 0 to rainbowLoops*65536, using steps of 256 so we
    // advance around the wheel at a decent clip.
    for(uint32_t firstPixelHue = 0; firstPixelHue < rainbowLoops*65536;
        firstPixelHue += 256) {

        for(int i=0; i<zone1.numPixels(); i++) { // For each pixel in strip...

            // Offset pixel hue by an amount to make one full revolution of the
            // color wheel (range of 65536) along the length of the strip
            // (strip.numPixels() steps):
            uint32_t pixelHue = firstPixelHue + (i * 65536L / zone1.numPixels());

            // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
            // optionally add saturation and value (brightness) (each 0 to 255).
            // Here we're using just the three-argument variant, though the
            // second value (saturation) is a constant 255.
            zone1.setPixelColor(i, zone1.gamma32(zone1.ColorHSV(pixelHue, 255,
                                                                   255 * fadeVal / fadeMax)));
        }

        zone1.show();
        delay(wait);

        if(firstPixelHue < 65536) {                              // First loop,
            if(fadeVal < fadeMax) fadeVal++;                       // fade in
        } else if(firstPixelHue >= ((rainbowLoops-1) * 65536)) { // Last loop,
            if(fadeVal > 0) fadeVal--;                             // fade out
        } else {
            fadeVal = fadeMax; // Interim loop, make sure fade is at max
        }
    }

    for(int k=0; k<whiteLoops; k++) {
        for(int j=0; j<256; j++) { // Ramp up 0 to 255
            // Fill entire strip with white at gamma-corrected brightness level 'j':
            zone1.fill(zone1.Color(0, 0, 0, zone1.gamma8(j)));
            zone1.show();
        }
        delay(1000); // Pause 1 second
        for(int j=255; j>=0; j--) { // Ramp down 255 to 0
            zone1.fill(zone1.Color(0, 0, 0, zone1.gamma8(j)));
            zone1.show();
        }
    }

    //delay(500); // Pause 1/2 second
}

void LedControl::rainbowFade2White2(int wait, int rainbowLoops, int whiteLoops) {
    int fadeVal=0, fadeMax=100;

    // Hue of first pixel runs 'rainbowLoops' complete loops through the color
    // wheel. Color wheel has a range of 65536 but it's OK if we roll over, so
    // just count from 0 to rainbowLoops*65536, using steps of 256 so we
    // advance around the wheel at a decent clip.
    for(uint32_t firstPixelHue = 0; firstPixelHue < rainbowLoops*65536;
        firstPixelHue += 256) {

        for(int i=0; i<zone2.numPixels(); i++) { // For each pixel in strip...

            // Offset pixel hue by an amount to make one full revolution of the
            // color wheel (range of 65536) along the length of the strip
            // (strip.numPixels() steps):
            uint32_t pixelHue = firstPixelHue + (i * 65536L / zone2.numPixels());

            // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
            // optionally add saturation and value (brightness) (each 0 to 255).
            // Here we're using just the three-argument variant, though the
            // second value (saturation) is a constant 255.
            zone2.setPixelColor(i, zone2.gamma32(zone2.ColorHSV(pixelHue, 255,
                                                                   255 * fadeVal / fadeMax)));
        }

        zone2.show();
        delay(wait);

        if(firstPixelHue < 65536) {                              // First loop,
            if(fadeVal < fadeMax) fadeVal++;                       // fade in
        } else if(firstPixelHue >= ((rainbowLoops-1) * 65536)) { // Last loop,
            if(fadeVal > 0) fadeVal--;                             // fade out
        } else {
            fadeVal = fadeMax; // Interim loop, make sure fade is at max
        }
    }

    for(int k=0; k<whiteLoops; k++) {
        for(int j=0; j<256; j++) { // Ramp up 0 to 255
            // Fill entire strip with white at gamma-corrected brightness level 'j':
            zone2.fill(zone2.Color(0, 0, 0, zone2.gamma8(j)));
            zone2.show();
        }
        delay(1000); // Pause 1 second
        for(int j=255; j>=0; j--) { // Ramp down 255 to 0
            zone2.fill(zone2.Color(0, 0, 0, zone2.gamma8(j)));
            zone2.show();
        }
    }

    //delay(500); // Pause 1/2 second
}

void LedControl::rainbowFade2White3(int wait, int rainbowLoops, int whiteLoops) {
    int fadeVal=0, fadeMax=100;

    // Hue of first pixel runs 'rainbowLoops' complete loops through the color
    // wheel. Color wheel has a range of 65536 but it's OK if we roll over, so
    // just count from 0 to rainbowLoops*65536, using steps of 256 so we
    // advance around the wheel at a decent clip.
    for(uint32_t firstPixelHue = 0; firstPixelHue < rainbowLoops*65536;
        firstPixelHue += 256) {

        for(int i=0; i<zone3.numPixels(); i++) { // For each pixel in strip...

            // Offset pixel hue by an amount to make one full revolution of the
            // color wheel (range of 65536) along the length of the strip
            // (strip.numPixels() steps):
            uint32_t pixelHue = firstPixelHue + (i * 65536L / zone3.numPixels());

            // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
            // optionally add saturation and value (brightness) (each 0 to 255).
            // Here we're using just the three-argument variant, though the
            // second value (saturation) is a constant 255.
            zone3.setPixelColor(i, zone3.gamma32(zone3.ColorHSV(pixelHue, 255,
                                                                   255 * fadeVal / fadeMax)));
        }

        zone3.show();
        delay(wait);

        if(firstPixelHue < 65536) {                              // First loop,
            if(fadeVal < fadeMax) fadeVal++;                       // fade in
        } else if(firstPixelHue >= ((rainbowLoops-1) * 65536)) { // Last loop,
            if(fadeVal > 0) fadeVal--;                             // fade out
        } else {
            fadeVal = fadeMax; // Interim loop, make sure fade is at max
        }
    }

    for(int k=0; k<whiteLoops; k++) {
        for(int j=0; j<256; j++) { // Ramp up 0 to 255
            // Fill entire strip with white at gamma-corrected brightness level 'j':
            zone3.fill(zone3.Color(0, 0, 0, zone3.gamma8(j)));
            zone3.show();
        }
        delay(1000); // Pause 1 second
        for(int j=255; j>=0; j--) { // Ramp down 255 to 0
            zone3.fill(zone3.Color(0, 0, 0, zone3.gamma8(j)));
            zone3.show();
        }
    }

    //delay(500); // Pause 1/2 second
}

void LedControl::rainbowFade2White4(int wait, int rainbowLoops, int whiteLoops) {
    int fadeVal=0, fadeMax=100;

    // Hue of first pixel runs 'rainbowLoops' complete loops through the color
    // wheel. Color wheel has a range of 65536 but it's OK if we roll over, so
    // just count from 0 to rainbowLoops*65536, using steps of 256 so we
    // advance around the wheel at a decent clip.
    for(uint32_t firstPixelHue = 0; firstPixelHue < rainbowLoops*65536;
        firstPixelHue += 256) {

        for(int i=0; i<zone4.numPixels(); i++) { // For each pixel in strip...

            // Offset pixel hue by an amount to make one full revolution of the
            // color wheel (range of 65536) along the length of the strip
            // (strip.numPixels() steps):
            uint32_t pixelHue = firstPixelHue + (i * 65536L / zone4.numPixels());

            // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
            // optionally add saturation and value (brightness) (each 0 to 255).
            // Here we're using just the three-argument variant, though the
            // second value (saturation) is a constant 255.
            zone4.setPixelColor(i, zone4.gamma32(zone4.ColorHSV(pixelHue, 255,
                                                                   255 * fadeVal / fadeMax)));
        }

        zone4.show();
        delay(wait);

        if(firstPixelHue < 65536) {                              // First loop,
            if(fadeVal < fadeMax) fadeVal++;                       // fade in
        } else if(firstPixelHue >= ((rainbowLoops-1) * 65536)) { // Last loop,
            if(fadeVal > 0) fadeVal--;                             // fade out
        } else {
            fadeVal = fadeMax; // Interim loop, make sure fade is at max
        }
    }

    for(int k=0; k<whiteLoops; k++) {
        for(int j=0; j<256; j++) { // Ramp up 0 to 255
            // Fill entire strip with white at gamma-corrected brightness level 'j':
            zone4.fill(zone4.Color(0, 0, 0, zone4.gamma8(j)));
            zone4.show();
        }
        delay(1000); // Pause 1 second
        for(int j=255; j>=0; j--) { // Ramp down 255 to 0
            zone4.fill(zone4.Color(0, 0, 0, zone4.gamma8(j)));
            zone4.show();
        }
    }

    //delay(500); // Pause 1/2 second
}

void LedControl::rainbowFade2White5(int wait, int rainbowLoops, int whiteLoops) {
    int fadeVal = 0, fadeMax = 100;

    // Hue of first pixel runs 'rainbowLoops' complete loops through the color
    // wheel. Color wheel has a range of 65536 but it's OK if we roll over, so
    // just count from 0 to rainbowLoops*65536, using steps of 256 so we
    // advance around the wheel at a decent clip.
    for (uint32_t firstPixelHue = 0; firstPixelHue < rainbowLoops * 65536;
         firstPixelHue += 256) {

        for (int i = 0; i < zone5.numPixels(); i++) { // For each pixel in strip...

            // Offset pixel hue by an amount to make one full revolution of the
            // color wheel (range of 65536) along the length of the strip
            // (strip.numPixels() steps):
            uint32_t pixelHue = firstPixelHue + (i * 65536L / zone5.numPixels());

            // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
            // optionally add saturation and value (brightness) (each 0 to 255).
            // Here we're using just the three-argument variant, though the
            // second value (saturation) is a constant 255.
            zone5.setPixelColor(i, zone5.gamma32(zone5.ColorHSV(pixelHue, 255,
                                                                255 * fadeVal / fadeMax)));
        }

        zone5.show();
        delay(wait);

        if (firstPixelHue < 65536) {                              // First loop,
            if (fadeVal < fadeMax) fadeVal++;                       // fade in
        } else if (firstPixelHue >= ((rainbowLoops - 1) * 65536)) { // Last loop,
            if (fadeVal > 0) fadeVal--;                             // fade out
        } else {
            fadeVal = fadeMax; // Interim loop, make sure fade is at max
        }
    }

    for (int k = 0; k < whiteLoops; k++) {
        for (int j = 0; j < 256; j++) { // Ramp up 0 to 255
            // Fill entire strip with white at gamma-corrected brightness level 'j':
            zone5.fill(zone5.Color(0, 0, 0, zone5.gamma8(j)));
            zone5.show();
        }
        delay(1000); // Pause 1 second
        for (int j = 255; j >= 0; j--) { // Ramp down 255 to 0
            zone5.fill(zone5.Color(0, 0, 0, zone5.gamma8(j)));
            zone5.show();
        }
    }

    //delay(500); // Pause 1/2 second
}

void LedControl::rainbowFade2White6(int wait, int rainbowLoops, int whiteLoops) {
    int fadeVal = 0, fadeMax = 100;

    // Hue of first pixel runs 'rainbowLoops' complete loops through the color
    // wheel. Color wheel has a range of 65536 but it's OK if we roll over, so
    // just count from 0 to rainbowLoops*65536, using steps of 256 so we
    // advance around the wheel at a decent clip.
    for (uint32_t firstPixelHue = 0; firstPixelHue < rainbowLoops * 65536;
         firstPixelHue += 256) {

        for (int i = 0; i < zone6.numPixels(); i++) { // For each pixel in strip...

            // Offset pixel hue by an amount to make one full revolution of the
            // color wheel (range of 65536) along the length of the strip
            // (strip.numPixels() steps):
            uint32_t pixelHue = firstPixelHue + (i * 65536L / zone6.numPixels());

            // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
            // optionally add saturation and value (brightness) (each 0 to 255).
            // Here we're using just the three-argument variant, though the
            // second value (saturation) is a constant 255.
            zone6.setPixelColor(i, zone6.gamma32(zone6.ColorHSV(pixelHue, 255,
                                                                255 * fadeVal / fadeMax)));
        }

        zone6.show();
        delay(wait);

        if (firstPixelHue < 65536) {                              // First loop,
            if (fadeVal < fadeMax) fadeVal++;                       // fade in
        } else if (firstPixelHue >= ((rainbowLoops - 1) * 65536)) { // Last loop,
            if (fadeVal > 0) fadeVal--;                             // fade out
        } else {
            fadeVal = fadeMax; // Interim loop, make sure fade is at max
        }
    }

    for (int k = 0; k < whiteLoops; k++) {
        for (int j = 0; j < 256; j++) { // Ramp up 0 to 255
            // Fill entire strip with white at gamma-corrected brightness level 'j':
            zone6.fill(zone6.Color(0, 0, 0, zone6.gamma8(j)));
            zone6.show();
        }
        delay(1000); // Pause 1 second
        for (int j = 255; j >= 0; j--) { // Ramp down 255 to 0
            zone6.fill(zone6.Color(0, 0, 0, zone6.gamma8(j)));
            zone6.show();
        }
    }

    //delay(500); // Pause 1/2 second
}


LedControl::~LedControl() {
    // Destructor implementation, if needed
    // Clean up resources, if any
}