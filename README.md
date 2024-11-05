# UltiBlox DisplayValueOLED Library
*Easily display labels and values on an OLED screen with custom fonts and formatting.*

[UltiBlox on GitHub](https://github.com/UltiBlox/DisplayValueOLED) | [UltiBlox Home](https://ultiblox.org)

## Overview
The `DisplayValueOLED` library simplifies displaying text and values on OLED screens, making it ideal for embedded projects needing dynamic information display. It provides options for setting fonts, centering text, and adding suffixes (e.g., units) to values.

## Features
- Display custom labels and values with optional suffixes.
- Set separate fonts for labels and values.
- Automatically center text on the display.
- Clear lines to update display content without residual artifacts.

## Compatibility
The `DisplayValueOLED` library is compatible with [`DisplayValueLCD`](https://github.com/ultiblox/DisplayValueLCD) for LCD displays. Both libraries share the same function signatures, allowing you to switch between OLED and LCD displays by simply changing the library declaration in your code.

## Installation

### Option 1: Arduino Library Manager Installation (Recommended)
1. Open the **Arduino IDE**.
2. Go to **Tools > Manage Libraries**.
3. Search for **UltiBlox DisplayValueOLED** and click **Install**.
4. Access example sketches under **File > Examples > UltiBlox DisplayValueOLED**.

### Option 2: Manual Installation (for Development and Customization)
1. **Clone the Repository**:
   ```bash
   git clone git@github.com:UltiBlox/DisplayValueOLED.git ~/workspace/DisplayValueOLED
   cd ~/workspace/DisplayValueOLED
   ```

2. **Prepare the Environment**:
   Run the `prepare.sh` script to set up dependencies:
   ```bash
   bash prepare.sh
   ```

3. **Install the Library**:
   - **Copy Installation**:
     ```bash
     bash install.sh
     ```
   - **Symlink Installation** (for active development):
     ```bash
     bash install-symlink.sh
     ```

4. **Build Examples**:
   Compile example sketches with:
   ```bash
   bash build.sh
   ```

## Dependencies
- **U8x8lib**: Required for OLED display communication.
- **Arduino Core Library**

## Usage Example
Refer to the [HelloWorld.ino](examples/HelloWorld/HelloWorld.ino) file for a complete usage example demonstrating basic display setup and usage.

## Methods

### Initialize the Display
```cpp
init()
```
Initializes the OLED display and clears any previous content.

### Clear the Display
```cpp
clear()
```
Clears the entire display content.

### Set the Label Text
```cpp
setLabel(const char* value)
```
Sets and centers a label text at the top of the display.

### Set the Value
```cpp
setValue(int value)
```
Displays the specified integer value on the display, centered and using the value font.

### Set a Suffix for the Value
```cpp
setSuffix(const char* value)
```
Sets a suffix, such as a unit symbol, to be displayed next to the value.

### Set Fonts for Labels and Values
```cpp
setLabelFont(const uint8_t* font)
```
```cpp
setValueFont(const uint8_t* font)
```
Sets custom fonts for the label and value. The library includes default fonts, but these can be customized for distinct visual styles.

## Examples Directory
- **[HelloWorld.ino](examples/HelloWorld/HelloWorld.ino)**: Displays a label with a static value and unit suffix, demonstrating basic setup for the display.

## License
[This project is licensed under the UltiBlox License.](https://ultiblox.org/license)
