#ifndef BOARD_DEFINITIONS_H
#define BOARD_DEFINITIONS_H

#define LED_STAT 34 //PA6
#define STAT_CNT 1  // one neoPixel for status led
#define STAT_BRT 10 // Brightness of status neoPixel

#define LED_SN 26 // PA2
#define LED_HB 13 // PA15
#define LED_TX 17 // PB3
#define LED_RX 15  // PA27

#define LEDSTRIP_1 45 // PB16
#define LEDSTRIP_2 41 // PA19 
#define LEDSTRIP_3 47 // PB17
#define LEDSTRIP_4 8  // PA20

#define STRIP1_CNT 5  // Amount of neoPixels for ledstrip 1
#define STRIP2_CNT 5  // Amount of neoPixels for ledstrip 2
#define STRIP3_CNT 5  // Amount of neoPixels for ledstrip 3
#define STRIP4_CNT 5  // Amount of neoPixels for ledstrip 4

#define STRIP1_BRT 10 // Brightness of neoPixels for ledstrip 1
#define STRIP2_BRT 10 // Brightness of neoPixels for ledstrip 2
#define STRIP3_BRT 10 // Brightness of neoPixels for ledstrip 3
#define STRIP4_BRT 10 // Brightness of neoPixels for ledstrip 4

#define BTN1 21  // PB31 //!
#define BTN2 22  // PB0
#define BTN3 23  // PB1

#define MAIN_SDA 29  // PA22
#define MAIN_SDO 28  // PA23
#define MAIN_INT4 35 // PA4
#define MAIN_INT5 37 // PA5

#define IOMUX_SDA 40 // PA16
#define IOMUX_SDO 42 // PA17

#define AUX_SDA 20 // PA12
#define AUX_SDO 21 // PA13

#define LED_SIN 31   // PB10
#define LED_CLK 30   // PB11
#define LED_LAT 18   // PB12
#define LED_GCLK 19  // PB13
#define LED_BLANK 10 // PB14

#define FLASH_CLK 32  // PA9
#define FLASH_MISO 51 // PA14
#define FLASH_MOSI 33 // PA8
#define FLASH_CS 36   // PA7

#define USB_DP 24 // PA24
#define USB_DM 25 // PA25

void initPins()
{
  pinMode(LED_STAT, OUTPUT);

  pinMode(LED_HB, OUTPUT);
  pinMode(LED_SN, OUTPUT);
  pinMode(LED_TX, OUTPUT);
  pinMode(LED_RX, OUTPUT);

  pinMode(LEDSTRIP_1, OUTPUT);
  pinMode(LEDSTRIP_2, OUTPUT);
  pinMode(LEDSTRIP_3, OUTPUT);
  pinMode(LEDSTRIP_4, OUTPUT);

  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(BTN3, INPUT_PULLUP);
}

#endif //BOARD_DEFINITIONS_H
