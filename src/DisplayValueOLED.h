#ifndef DisplayValueOLED_h
#define DisplayValueOLED_h

#include <U8x8lib.h>
#include <string.h>  // For string handling functions

const int LABEL_CHAR_WIDTH = 8;   // Example width in pixels
const int VALUE_CHAR_WIDTH = 10;  // Example width in pixels

class DisplayValueOLED {
private:
    U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8;
    char lastLabel[32];   // Fixed-size buffer for the label
    char lastValue[32];   // Fixed-size buffer for the value
    char suffix[8];       // Buffer for the suffix
    const uint8_t* labelFont = u8x8_font_chroma48medium8_r;  // Default font for labels
    const uint8_t* valueFont = u8x8_font_inb33_3x6_r;  // Default font for values

public:
    DisplayValueOLED();
    virtual ~DisplayValueOLED();
    void init();
    void clear();
    void setLabel(const char* value);
    void setLabel(const __FlashStringHelper* value);
    void setValue(const char* value);
    void setValue(int value);
    void setSuffix(const char* value);

    DisplayValueOLED& setLabelFont(const uint8_t* font);
    DisplayValueOLED& setValueFont(const uint8_t* font);

    int calculateCenterPosition(const char* text, const uint8_t* font);
    int getDisplayWidth();
};

#endif
