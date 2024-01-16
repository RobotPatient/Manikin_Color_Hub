//
// Created by emiel on 02/01/2024.
//

#ifndef CLIO_PLATFORMIO_TOUCHCONTROL_H
#define CLIO_PLATFORMIO_TOUCHCONTROL_H

#include "AT42QT2120.h"

class TouchControl{
public:
    void initAT42QT2120();
    void printKeyStatus(AT42QT2120::Status status, uint8_t key_count);
    void sample();

private:
    const int RESET_DELAY = 2000;
    const int CALIBRATION_LOOP_DELAY = 50;

    const int LOOP_DELAY = 500;

    unsigned long loop_counter;
};

#endif //CLIO_PLATFORMIO_TOUCHCONTROL_H
