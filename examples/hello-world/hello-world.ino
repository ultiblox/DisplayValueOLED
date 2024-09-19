#include "DisplayValueOLED.h"

DisplayValueOLED display;

void setup() {
  display.setLabelFont(u8x8_font_chroma48medium8_r)
           .setValueFont(u8x8_font_inb33_3x6_n)
           .init();

  display.setLabel("Sensor Reading"); 
}

void loop() {
    display.updateValue("25%");
    delay(1000);
}
