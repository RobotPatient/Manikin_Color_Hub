//
// Created by emiel on 02/01/2024.
//
#include "pinDefinitions.h"

#ifdef analogCorrection
void PinDefinitions::setAnalogCorrectionOffset(int offset) {
    analogCorrectionOffset = offset;
}
void PinDefinitions::setAnalogCorrectionGain(uint16_t gain) {
    analogCorrectionGain = gain;
}
#endif

void PinDefinitions::initIO()
{
    pinMode(LedSNPin, OUTPUT);
    pinMode(LedHBPin, OUTPUT);
    pinMode(LedTXPin, OUTPUT);
    pinMode(LedRXPin, OUTPUT);

    pinMode(IO3, INPUT_PULLUP); // Button

    pinMode(StatNeoPixel, OUTPUT);
    pinMode(NeoPixelZone1, OUTPUT);
    pinMode(NeoPixelZone2, OUTPUT);
    pinMode(NeoPixelZone3, OUTPUT);
    pinMode(NeoPixelZone4, OUTPUT);
    pinMode(NeoPixelZone5, OUTPUT);
    pinMode(NeoPixelZone6, OUTPUT);

    pinMode(MAIN_INT4, INPUT_PULLUP);
    pinMode(MAIN_INT5, INPUT_PULLUP);
}

void PinDefinitions::initADC()
{
    pinMode(AREF, INPUT);
}