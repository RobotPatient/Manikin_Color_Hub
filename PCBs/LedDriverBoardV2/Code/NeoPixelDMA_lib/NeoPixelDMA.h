//
// Created by emiel on 16-11-2023.
//

#ifndef NEOPIXELDMA_H
#define NEOPIXELDMA_H

#include "hal_gpio.h"

class NeoPixelDMA {
public:
    NeoPixelDMA();
    ~NeoPixelDMA();

    void init(void);
    void show(void);
    void setNeoPixelPin(uint16_t p);
    void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b);
    void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint8_t w);
    void setPixelColor(uint16_t n, uint32_t c);
    void fill(uint32_t c = 0, uint16_t first = 0, uint16_t count = 0);
    void setBrightness(uint8_t);
    void clear(void);
    /*!
     * updateLength and updateType functions might not be necessary
     * for our application.
     */
//    void updateLength(uint16_t n);
//    void updateType(neoPixelType);
private:

protected:
    bool begun;         ///< true if begin() previously called
    uint16_t numLEDs;   ///< Number of RGB LEDs in strip
    uint16_t numBytes;  ///< Size of 'pixels' buffer below
    int16_t pin;        ///< Output pin number (-1 if not yet set)
    uint8_t brightness; ///< Strip brightness 0-255 (stored as +1)
    uint8_t *pixels;    ///< Holds LED color values (3 or 4 bytes each)
    uint8_t rOffset;    ///< Red index within each 3- or 4-byte pixel
    uint8_t gOffset;    ///< Index of green byte
    uint8_t bOffset;    ///< Index of blue byte
    uint8_t wOffset;    ///< Index of white (==rOffset if no white)
};


#endif //NEOPIXELDMA_H
