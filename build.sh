#!/bin/bash

# Set the board type (change this if you're using a different board)
BOARD_TYPE="arduino:avr:uno"

# Get the absolute path of the current working directory
BASE_DIR=$(pwd)

# Directory paths
EXAMPLES_PATH="$BASE_DIR/examples"
OLED_LIBRARY_PATH="$BASE_DIR"

# Check if arduino-cli is installed
if ! command -v arduino-cli &> /dev/null
then
    echo "arduino-cli not found. Please install it from https://arduino.github.io/arduino-cli/installation/"
    exit 1
fi

# Compile each example
for example in "$EXAMPLES_PATH"/*; do
    if [ -d "$example" ]; then
        echo "Compiling example: $example"
        arduino-cli compile --fqbn $BOARD_TYPE --libraries "$OLED_LIBRARY_PATH" "$example"
        
        if [ $? -ne 0 ]; then
            echo "Error: Compilation failed for $example"
            exit 1
        else
            echo "Compilation successful for $example"
        fi
    fi
    
done


echo "All examples compiled successfully."
