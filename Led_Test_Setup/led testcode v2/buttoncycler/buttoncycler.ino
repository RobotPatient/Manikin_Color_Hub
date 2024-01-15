// Simple demonstration on using an input device to trigger changes on your
// NeoPixels. Wire a momentary push button to connect from ground to a
// digital IO pin. When the button is pressed it will change to a new pixel
// animation. Initial state has all pixels off -- press the button once to
// start the first animation. As written, the button does not interrupt an
// animation in-progress, it works only when idle.

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Digital IO pin connected to the button. This will be driven with a
// pull-up resistor so the switch pulls the pin to ground momentarily.
// On a high -> low transition the button press logic will execute.
#define BUTTON_PIN   5

#define PIXEL_PIN    6  // Digital IO pin connected to the NeoPixels.

#define PIXEL_COUNT 1  // Number of NeoPixels

#define brightness A0
auto colorVal = 0;

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

boolean oldState = HIGH;

//holde the current change state
int mode = 0;

// rgb values for the led
int r, g, b = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(brightness, INPUT);
  strip.begin(); // Initialize NeoPixel strip object (REQUIRED)
  strip.show();  // Initialize all pixels to 'off'
}

void loop() {

  // Get current button state and pot value.
  boolean newState = digitalRead(BUTTON_PIN);
  colorVal = map(analogRead(brightness), 0, 1023, 0, 255);

  // based on the button, change the correct state
  if((newState == LOW) && (oldState == HIGH)) {
    // debounce delay
    delay(20);
    newState = digitalRead(BUTTON_PIN);
    if(newState == LOW) {
      delay(1000);
      newState = digitalRead(BUTTON_PIN);
      if(newState == LOW) {
        // lets the user see that the values can be changed;
        colorWipe(strip.Color(  0,   255,   0), 255);
        delay(100);
        colorWipe(strip.Color(  r,   g,   b), 255);
        while(newState == LOW) {
          switch(mode) {
            case 0:
            r = colorVal;
            break;
            case 1:
            g = colorVal;
            break;
            case 2:
            b = colorVal;
            break;
            default:
            r = colorVal;
            break;
          }
          
          newState = digitalRead(BUTTON_PIN);
          colorVal = map(analogRead(brightness), 0, 1023, 0, 255);

          colorWipe(strip.Color(  r,   g,   b), 255);
          Serial.write("hallo");
        }
      } else {
        if (mode == 2) {
          mode = 0;          
        } else {
          mode++;
        }

        colorWipe(strip.Color(  255,   0,   0), 255);
        delay(100);
        colorWipe(strip.Color(  r,   g,   b), 255);
      }
    }
  }
  oldState = newState;
}

// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}
