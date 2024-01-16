//
// Created by emiel on 14-12-2023.
//
#include "pinDefinitions.h"
#include "ledControl.h"
#include "touchControl.h"
#include "../lib/systemControl/systemControl.h"
#include "C:\Users\emiel\OneDrive - HAN\HAN 2022-2026\leerjaar 2\S3 project\rgbBabay\design files\code\clio-platformio\.pio\libdeps\adafruit_feather_m0_express\FreeRTOS_SAMD21\src\FreeRTOSConfig.h"
#include "C:\Users\emiel\OneDrive - HAN\HAN 2022-2026\leerjaar 2\S3 project\rgbBabay\design files\code\clio-platformio\.pio\libdeps\adafruit_feather_m0_express\FreeRTOS_SAMD21\src\FreeRTOS.h"
#include "C:\Users\emiel\OneDrive - HAN\HAN 2022-2026\leerjaar 2\S3 project\rgbBabay\design files\code\clio-platformio\.pio\libdeps\adafruit_feather_m0_express\FreeRTOS_SAMD21\src\task.h"

/**
 * Namespaces
 */
PinDefinitions pinDefinitions;
TouchControl touchControl;
SystemControl systemControl;

TaskHandle_t Handle_aTask;
TaskHandle_t Handle_bTask;
TaskHandle_t Handle_monitorTask;

void myDelayUs(int us)
{
    vTaskDelay( us / portTICK_PERIOD_US );
}

void myDelayMs(int ms)
{
    vTaskDelay( (ms * 1000) / portTICK_PERIOD_US );
}

void myDelayMsUntil(TickType_t *previousWakeTime, int ms)
{
    vTaskDelayUntil( previousWakeTime, (ms * 1000) / portTICK_PERIOD_US );
}

void setup()
{
    /**
     * Start serial monitor
     */
    Serial.begin(115200);
    while (!Serial)
        continue;

    /**
     * Initialize capacitive touch sensor
     */
    touchControl.initAT42QT2120();

    /**
     * Initialize pins
     */
    pinDefinitions.initIO();

    /**
     * Enable analog correction if needed.
     * Uncomment line 18 in pinDefinitions.h
     */
#ifdef analogCorrection
    pinDefinitions.setAnalogCorrectionOffset(0);
    pinDefinitions.setAnalogCorrectionGain(1024);
#endif

    /**
     * Init ADC
     */
    pinDefinitions.initADC();
}

void loop()
{
    LedControl LedControl(1, "rainbowFade2White", 255,10, 10, 10, 1, 1);
    touchControl.sample();
    systemControl.heartBeatLed();
    systemControl.healthLed();
    systemControl.statusLed(0);
}