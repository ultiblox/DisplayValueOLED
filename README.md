# DisplayValueOLED Library

## Overview
The `DisplayValueOLED` library provides an easy-to-use interface for controlling an OLED display via I2C using the `U8x8lib`. It supports setting labels, updating values, and adjusting fonts for a more customized display experience.

## Features
- Supports 128x64 OLED displays.
- Customizable fonts for labels and values.
- Centers text on the display for better alignment.
- Simple methods for clearing and updating the display.

## Usage
### Initialization
```cpp
#include "DisplayValueOLED.h"
DisplayValueOLED display;
display.setLabelFont(u8x8_font_chroma48medium8_r).setValueFont(u8x8_font_inb33_3x6_n).init();
```
### Set Label and Update Value
```cpp
display.setLabel("Sensor Reading");
display.updateValue("25%");
```
### Example
Refer to `examples/hello-world/hello-world.ino` for a full usage example.

## Dependencies
- U8x8lib
- Arduino Core Library

## License
[This project is licensed under the UltiBlox License.](https://ultiblox.org/license)