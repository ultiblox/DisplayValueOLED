#include "DisplayValueOLED.h"

DisplayValueOLED::DisplayValueOLED() : u8x8(U8X8_PIN_NONE) {}

DisplayValueOLED::~DisplayValueOLED() {}



void DisplayValueOLED::init() {
    u8x8.begin();
    clear();
}

void DisplayValueOLED::clear() {
    u8x8.clearDisplay();
}

DisplayValueOLED& DisplayValueOLED::setLabelFont(const uint8_t* font) {
    labelFont = font;
    return *this;
}

DisplayValueOLED& DisplayValueOLED::setValueFont(const uint8_t* font) {
    valueFont = font;
    return *this;
}

void DisplayValueOLED::setLabel(const String& label) {
    if (label != lastLabel) {
        lastLabel = label;
        u8x8.setFont(labelFont);
        int centerPos = calculateCenterPosition(label, labelFont);
        u8x8.drawString(centerPos, 0, label.c_str());  // Draw at calculated position
    }
}

void DisplayValueOLED::updateValue(const String& value) {
    if (value != lastValue) {
        lastValue = value;
        u8x8.setFont(valueFont);
        int centerPos = calculateCenterPosition(value, valueFont);
        u8x8.drawString(centerPos, 1, value.c_str());  // Ensure full string including '%' is passed
    }
}


int DisplayValueOLED::calculateCenterPosition(const String& text, const uint8_t* font) {
    int charWidth = (font == labelFont) ? LABEL_CHAR_WIDTH : VALUE_CHAR_WIDTH;
    int displayWidthPixels = getDisplayWidth(); // This should be the pixel width of the display
    int textWidthPixels = text.length() * charWidth;
    int startPosPixels = (displayWidthPixels - textWidthPixels) / 2;
    return max(startPosPixels / charWidth, 0); // Convert from pixels to character units if necessary
}


int DisplayValueOLED::getDisplayWidth() {
    // Assuming the display width in pixels, e.g., 128 pixels for a typical OLED display
    return 128;  // Pixel width of the display
}

//int DisplayValueOLED::getTextWidth(const String& text, const uint8_t* font) {
//    u8x8.setFont(font);  // Set the font to measure
//    return u8x8.getUTF8Width(text.c_str());  // Returns the pixel width of the text
//}


