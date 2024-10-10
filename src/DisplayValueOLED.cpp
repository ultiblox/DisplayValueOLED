#include "DisplayValueOLED.h"

DisplayValueOLED::DisplayValueOLED() : u8x8(U8X8_PIN_NONE) {
    lastLabel[0] = '\0';  // Initialize strings to empty
    lastValue[0] = '\0';
    suffix[0] = '\0';
}

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

void DisplayValueOLED::setLabel(const char* value) {
    if (value == nullptr) return;  // Check for null input

    if (strcmp(lastLabel, value) != 0) {  // Only update if the label has changed
        // Clear the line first
        u8x8.clearLine(0);

        // Copy the new label
        strncpy(lastLabel, value, sizeof(lastLabel) - 1);
        lastLabel[sizeof(lastLabel) - 1] = '\0';  // Ensure null termination

        // Set the font and print the label centered
        u8x8.setFont(labelFont);
        int centerPos = calculateCenterPosition(lastLabel, labelFont);
        u8x8.drawString(centerPos, 0, lastLabel);
    }
}

void DisplayValueOLED::setLabel(const __FlashStringHelper* value) {
    if (value == nullptr) return;
    char buffer[32];  // Adjust size as needed
    strncpy_P(buffer, (PGM_P)value, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';  // Ensure null termination
    setLabel(buffer);
}

void DisplayValueOLED::setValue(const char* value) {
    if (value == nullptr) return;

    char fullValue[40];
    snprintf(fullValue, sizeof(fullValue), "%s%s", value, suffix);

    // Debugging: Print value, suffix, and fullValue
    Serial.print("Value: ");
    Serial.println(value);
    Serial.print("Suffix: ");
    Serial.println(suffix);
    Serial.print("Full Value: ");
    Serial.println(fullValue);

    if (strcmp(lastValue, fullValue) != 0) {
        // Clear the entire line to avoid leftover characters from a longer previous value
        u8x8.clearLine(1);
        
        // Optionally fill with spaces to ensure complete overwrite of the previous value
        u8x8.drawString(0, 1, "                ");  // Fill with spaces to fully clear

        // Store the new value
        strncpy(lastValue, fullValue, sizeof(lastValue) - 1);
        lastValue[sizeof(lastValue) - 1] = '\0';

        // Set the font and print the new value
        u8x8.setFont(valueFont);
        int centerPos = calculateCenterPosition(fullValue, valueFont);
        u8x8.drawString(centerPos, 1, fullValue);
    }
}


void DisplayValueOLED::setValue(int value) {
    char valueStr[16];  // Adjust buffer size as needed
    snprintf(valueStr, sizeof(valueStr), "%d", value);
    setValue(valueStr);  // Use the char* version
}

void DisplayValueOLED::setSuffix(const char* value) {
    if (value == nullptr) return;
    strncpy(suffix, value, sizeof(suffix) - 1);
    suffix[sizeof(suffix) - 1] = '\0';

    // Debugging: Print the suffix to Serial Monitor
    Serial.print("Suffix set to: ");
    Serial.println(suffix);
}

int DisplayValueOLED::calculateCenterPosition(const char* text, const uint8_t* font) {
    int charWidth = (font == labelFont) ? LABEL_CHAR_WIDTH : VALUE_CHAR_WIDTH;
    int displayWidthPixels = getDisplayWidth();  // Width of the display in pixels
    int textLength = strlen(text);
    int textWidthPixels = textLength * charWidth;
    int startPosPixels = (displayWidthPixels - textWidthPixels) / 2;
    int charPosition = startPosPixels / charWidth;
    return charPosition >= 0 ? charPosition : 0;  // Ensure position is non-negative
}

int DisplayValueOLED::getDisplayWidth() {
    // Assuming 128 pixels width for a typical 128x64 OLED display
    return 128;
}

