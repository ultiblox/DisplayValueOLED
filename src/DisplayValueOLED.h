#ifndef DisplayValueOLED_h
#define DisplayValueOLED_h

#include "DisplayValueCommon.h"
#include <U8x8lib.h>
const int LABEL_CHAR_WIDTH = 8;  // Example: Average width for u8x8_font_chroma48medium8_r
const int VALUE_CHAR_WIDTH = 10; // Example: Average width for u8x8_font_inb33_3x6_n, assuming this is a larger font


class DisplayValueOLED : public DisplayValueCommon {
private:
    U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8;
    String lastLabel = "";
    String lastValue = "";
    const uint8_t* labelFont = u8x8_font_chroma48medium8_r;  // Default font for labels
    const uint8_t* valueFont = u8x8_font_chroma48medium8_r;  // Default font for values

public:
    DisplayValueOLED();
    virtual ~DisplayValueOLED();
    void init() override;
    void clear() override;
    void setLabel(const String& label) override;
    void updateValue(const String& value) override;

    DisplayValueOLED& setLabelFont(const uint8_t* font);
    DisplayValueOLED& setValueFont(const uint8_t* font);

    int getTextWidth(const String& text, const uint8_t* font);  // Calculate pixel width of the text
    int calculateCenterPosition(const String& text, const uint8_t* font);  // Updated to use text and font
    int getDisplayWidth();  // Returns the pixel width of the display

};

#endif

