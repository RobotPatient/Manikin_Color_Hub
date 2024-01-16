//
// Created by emiel on 16-11-2023.
//
#include "NeoPixelDMA.h"
#include <cstring>
#include <cctype>

/*!
  @brief   "Empty" NeoPixel constructor when length, pin and/or pixel type
           are not known at compile-time, and must be initialized later with
           updateType(), updateLength() and setPin().
  @return  Adafruit_NeoPixel object. Call the begin() function before use.
  @note    This function is deprecated, here only for old projects that
           may still be calling it. New projects should instead use the
           'new' keyword with the first constructor syntax (length, pin,
           type).
*/
NeoPixelDMA::NeoPixelDMA() : begun(false), numLEDs(0), numBytes(0), pin(GPIO_PIN_PA6), brightness(0),
                             pixels(NULL), rOffset(1), gOffset(0), bOffset(2), wOffset(1) {
    //updateType(t);
    //updateLength(n);
    //setPin(p);
}

/*!
  @brief   Configure NeoPixel pin for output.
*/
void NeoPixelDMA::init(void) {
    if (pin >= 0) {
        gpio_set_pin_mode(pin, GPIO_MODE_OUTPUT);
        gpio_set_pin_lvl(pin, GPIO_LOW);
    }
    begun = true;
}

/*!
  @brief   Set/change the NeoPixel output pin number. Previous pin,
           if any, is set to INPUT and the new pin is set to OUTPUT.
  @param   p  Arduino pin number (-1 = no pin).
*/

void NeoPixelDMA::setNeoPixelPin(uint16_t p) {
    if (begun && (pin >= 0))
        gpio_set_pin_mode(pin, GPIO_MODE_INPUT);
    pin = p;
    if (begun) {
        gpio_set_pin_mode(pin, GPIO_MODE_OUTPUT);
        gpio_set_pin_lvl(pin, GPIO_LOW);
    }
}

void NeoPixelDMA::setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b) {
    if (n < numLEDs) {
        if (brightness) { // See notes in setBrightness()
            r = (r * brightness) >> 8;
            g = (g * brightness) >> 8;
            b = (b * brightness) >> 8;
        }
        uint8_t *p;
        if (wOffset == rOffset) { // Is an RGB-type strip
            p = &pixels[n * 3];     // 3 bytes per pixel
        } else {// Is a WRGB-type strip
            p = &pixels[n * 4];     // 4 bytes per pixel
            p[wOffset] = 0;         // But only R,G,B passed -- set W to 0
        }
        p[rOffset] = r; // R,G,B always stored
        p[gOffset] = g;
        p[bOffset] = b;
    }
}

/*!
  @brief   Set a pixel's color using separate red, green, blue and white
           components (for RGBW NeoPixels only).
  @param   n  Pixel index, starting from 0.
  @param   r  Red brightness, 0 = minimum (off), 255 = maximum.
  @param   g  Green brightness, 0 = minimum (off), 255 = maximum.
  @param   b  Blue brightness, 0 = minimum (off), 255 = maximum.
  @param   w  White brightness, 0 = minimum (off), 255 = maximum, ignored
              if using RGB pixels.
*/
void NeoPixelDMA::setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
    if (n < numLEDs) {
        if (brightness) { // See notes in setBrightness()
            r = (r * brightness) >> 8;
            g = (g * brightness) >> 8;
            b = (b * brightness) >> 8;
            w = (w * brightness) >> 8;
        }
        uint8_t *p;
        if (wOffset == rOffset) { // Is an RGB-type strip
            p = &pixels[n * 3];     // 3 bytes per pixel (ignore W)
        } else {// Is a WRGB-type strip
            p = &pixels[n * 4];     // 4 bytes per pixel
            p[wOffset] = w;         // Store W
        }
        p[rOffset] = r; // Store R,G,B
        p[gOffset] = g;
        p[bOffset] = b;
    }
}

/*!
  @brief   Set a pixel's color using a 32-bit 'packed' RGB or RGBW value.
  @param   n  Pixel index, starting from 0.
  @param   c  32-bit color value. Most significant byte is white (for RGBW
              pixels) or ignored (for RGB pixels), next is red, then green,
              and least significant byte is blue.
*/
void NeoPixelDMA::setPixelColor(uint16_t n, uint32_t c) {
    if (n < numLEDs) {
        uint8_t *p, r = (uint8_t) (c >> 16), g = (uint8_t) (c >> 8), b = (uint8_t) c;
        if (brightness) { // See notes in setBrightness()
            r = (r * brightness) >> 8;
            g = (g * brightness) >> 8;
            b = (b * brightness) >> 8;
        }
        if (wOffset == rOffset) {
            p = &pixels[n * 3];
        } else {
            p = &pixels[n * 4];
            uint8_t w = (uint8_t) (c >> 24);
            p[wOffset] = brightness ? ((w * brightness) >> 8) : w;
        }
        p[rOffset] = r;
        p[gOffset] = g;
        p[bOffset] = b;
    }
}

/*!
  @brief   Fill all or part of the NeoPixel strip with a color.
  @param   c      32-bit color value. Most significant byte is white (for
                  RGBW pixels) or ignored (for RGB pixels), next is red,
                  then green, and least significant byte is blue. If all
                  arguments are unspecified, this will be 0 (off).
  @param   first  Index of first pixel to fill, starting from 0. Must be
                  in-bounds, no clipping is performed. 0 if unspecified.
  @param   count  Number of pixels to fill, as a positive value. Passing
                  0 or leaving unspecified will fill to end of strip.
*/
void NeoPixelDMA::fill(uint32_t c, uint16_t first, uint16_t count) {
    uint16_t i, end;

    if (first >= numLEDs) {
        return; // If first LED is past end of strip, nothing to do
    }

    // Calculate the index ONE AFTER the last pixel to fill
    if (count == 0) {
        // Fill to end of strip
        end = numLEDs;
    } else {
        // Ensure that the loop won't go past the last pixel
        end = first + count;
        if (end > numLEDs)
            end = numLEDs;
    }

    for (i = first; i < end; i++) {
        this->setPixelColor(i, c);
    }
}

/*!
  @brief   Adjust output brightness. Does not immediately affect what's
           currently displayed on the LEDs. The next call to show() will
           refresh the LEDs at this level.
  @param   b  Brightness setting, 0=minimum (off), 255=brightest.
  @note    This was intended for one-time use in one's setup() function,
           not as an animation effect in itself. Because of the way this
           library "pre-multiplies" LED colors in RAM, changing the
           brightness is often a "lossy" operation -- what you write to
           pixels isn't necessary the same as what you'll read back.
           Repeated brightness changes using this function exacerbate the
           problem. Smart programs therefore treat the strip as a
           write-only resource, maintaining their own state to render each
           frame of an animation, not relying on read-modify-write.
*/
void NeoPixelDMA::setBrightness(uint8_t b) {
    // Stored brightness value is different than what's passed.
    // This simplifies the actual scaling math later, allowing a fast
    // 8x8-bit multiply and taking the MSB. 'brightness' is a uint8_t,
    // adding 1 here may (intentionally) roll over...so 0 = max brightness
    // (color values are interpreted literally; no scaling), 1 = min
    // brightness (off), 255 = just below max brightness.
    uint8_t newBrightness = b + 1;
    if (newBrightness != brightness) { // Compare against prior value
        // Brightness has changed -- re-scale existing data in RAM,
        // This process is potentially "lossy," especially when increasing
        // brightness. The tight timing in the WS2811/WS2812 code means there
        // aren't enough free cycles to perform this scaling on the fly as data
        // is issued. So we make a pass through the existing color data in RAM
        // and scale it (subsequent graphics commands also work at this
        // brightness level). If there's a significant step up in brightness,
        // the limited number of steps (quantization) in the old data will be
        // quite visible in the re-scaled version. For a non-destructive
        // change, you'll need to re-render the full strip data. C'est la vie.
        uint8_t c, *ptr = pixels,
                oldBrightness = brightness - 1; // De-wrap old brightness value
        uint16_t scale;
        if (oldBrightness == 0)
            scale = 0; // Avoid /0
        else if (b == 255)
            scale = 65535 / oldBrightness;
        else
            scale = (((uint16_t) newBrightness << 8) - 1) / oldBrightness;
        for (uint16_t i = 0; i < numBytes; i++) {
            c = *ptr;
            *ptr++ = (c * scale) >> 8;
        }
        brightness = newBrightness;
    }
}

/*!
@brief   Fill the whole NeoPixel strip with 0 / black / off.
*/
void NeoPixelDMA::clear(void) {
    memset(pixels, 0, numBytes);
}

