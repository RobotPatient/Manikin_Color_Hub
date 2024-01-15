//
// Created by emiel on 01/01/2024.
//

#ifndef CLIO_PLATFORMIO_PINDEFINITIONS_HPP
#define CLIO_PLATFORMIO_PINDEFINITIONS_HPP

/**
 * Libraries
 */
#include <stdint.h>
#include "Arduino.h"
#include <SAMD_AnalogCorrection.h>

/**
 * Enable ADC correction
 */
//#define analogCorrection

/**
 * Pin macros with physical pinnumbers.
 */
#define LedSNPin 15 //PA15
#define LedHBPin 2  //PA2
#define LedTXPin 27 //PA27
#define LedRXPin 3  //PB3

#define IO1 10 //PA10
#define IO2 11 //PA11
#define IO3 2  //PB2
#define IO4 10 //PB10
#define IO5 11 //PB11
#define IO6 22 //PB22
#define IO7 23 //PB23

#define StatNeoPixel 6   //PA6
#define NeoPixelZone1 19 //PA19
#define NeoPixelZone2 18 //PA18
#define NeoPixelZone3 21 //PA21
#define NeoPixelZone4 20 //PA20
#define NeoPixelZone5 8  //PB8
#define NeoPixelZone6 9  //PB9

#define StatCount 1
#define Zone1Count 5
#define Zone2Count 5
#define Zone3Count 5
#define Zone4Count 5
#define Zone5Count 5
#define Zone6Count 5

#define StatBrightness 50
#define Zone1Brightness 50
#define Zone2Brightness 50
#define Zone3Brightness 50
#define Zone4Brightness 50
#define Zone5Brightness 50
#define Zone6Brightness 50

#define IO_SDA 12 //PA12
#define IO_SCL 13 //PA13

#define MAIN_SDA 22 //PA22
#define MAIN_SCL 23 //PA23
#define MAIN_INT4 4 //PA4
#define MAIN_INT5 5 //PA5

#define AUX_SDA 16 //PA16
#define AUX_SCL 17 //PA17


/**
 * Pin macros with physical pinnumbers. For internal use only.
 */
#define FLASH_CLK  9  //PA9
#define FLASH_MISO 14 //PA14
#define FLASH_MOSI 8  //PA8
#define FLASH_CS   7  //PA7

#define USB_DM 24 //PA24
#define USB_DP 25 //PA25
#define USBHOST_EN 28 //PA28

#define PA0_XTAL 0 //PA0
#define PA1_XTAL 1 //PA1

#define AREF 3 //PA3

#define SWCLK 30 //PA30
#define SWDIO 31 //PA31
//#define RESET NULL //No pin number

class PinDefinitions {
public:
    void initIO();
    void initADC();

#ifdef analogCorrection
    void setAnalogCorrectionOffset(int offset);
    void setAnalogCorrectionGain(uint16_t gain);
#endif

private:
#ifdef analogCorrection
    int analogCorrectionOffset;
    uint16_t analogCorrectionGain;
#endif
};


#endif //CLIO_PLATFORMIO_PINDEFINITIONS_HPP
