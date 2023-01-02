#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 32 
#define OLED_RESET     -1 
#define SCREEN_ADDRESS 0x3C 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 
#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

char states[] = {
  "OXOOXOXOXOXOXO"
};


void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();

  // Clear the buffer
  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  // Collumm 1
  display.print(states[0]);
  display.print(" | ");
  display.print(states[1]);
  display.print(" | ");
  display.println(states[2]);

  // draws the line between the collums
  display.writeLine(0, 8, 53, 8, SSD1306_WHITE);

  // Collumm 2
  display.print(states[3]);
  display.print(" | ");
  display.print(states[4]);
  display.print(" | ");
  display.println(states[5]);

  // draws the line between the collums
  display.writeLine(0, 8, 53, 8, SSD1306_WHITE);

  // Collumm 3
  display.print(states[6]);
  display.print(" | ");
  display.print(states[7]);
  display.print(" | ");
  display.println(states[8]);



  display.display();
  delay(2000);
  // display.display() is NOT necessary after every single drawing command,
  // unless that's what you want...rather, you can batch up a bunch of
  // drawing operations and then update the screen all at once by calling
  // display.display(). These examples demonstrate both approaches...
}

void loop() {
}
