//
// Created by emiel on 03/01/2024.
//

#include "systemControl.h"

void SystemControl::heartBeatLed()
{
    unsigned long currentMillis = millis();
    if (currentMillis - previousMilils >= interval)
    {
        previousMilils = currentMillis;
        if (ledStateHB == LOW)
        {
            ledStateHB == HIGH;
        }
        else
        {
            ledStateHB == LOW;
        }
        digitalWrite(LedHBPin, ledStateHB);
    }
}

void SystemControl::healthLed()
{
    buttonStateIO3 = digitalRead(IO3);
    if (buttonStateIO3 == HIGH)
    {
        digitalWrite(LedSNPin, HIGH);
    }
    else
    {
        digitalWrite(LedSNPin, LOW);
    }
}

void SystemControl::statusLed(int error)
{
    if (error == 0) // System operating as expected, status led set to green.
    {
        LedControl LedControl(7, "rainbowFade2White", 255,10, 10, 10, 1, 1);
    }
    else if (error == 1) //Hardfault has occured, status led set to white.
    {
        LedControl LedControl(7, "rainbowFade2White", 255,10, 10, 10, 1, 1);
    }
    else if (error == 2) //Connection on mainbus lost, status led set to red.
    {
        LedControl LedControl(7, "rainbowFade2White", 255,10, 10, 10, 1, 1);
    }
    else if (error == 3) //PCB is in testmode, status led set to blue.
    {
        LedControl LedControl(7, "rainbowFade2White", 255,10, 10, 10, 1, 1);
    }
    else //Init has not been run yet, status led set to off.
    {
        LedControl LedControl(1, "rainbowFade2White", 0,10, 10, 10, 1, 1);
    }
}