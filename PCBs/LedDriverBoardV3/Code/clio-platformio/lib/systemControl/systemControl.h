//
// Created by emiel on 03/01/2024.
//

#ifndef CLIO_PLATFORMIO_SYSTEMCONTROL_HPP
#define CLIO_PLATFORMIO_SYSTEMCONTROL_HPP

#include "pinDefinitions.h"
#include "ledControl.h"

class SystemControl{
public:
    void heartBeatLed();
    void healthLed();
    void statusLed(int error);

private:
    int buttonStateIO3 = 0;

    int ledStateHB = LOW;
    unsigned long previousMilils = 0;
    const long interval = 1000;
};

#endif //CLIO_PLATFORMIO_SYSTEMCONTROL_HPP
