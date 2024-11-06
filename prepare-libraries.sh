#!/bin/bash

# Function to clone libraries if not already present
install_library() {
  local LIBRARY_NAME="$1"
  local LIBRARY_PATH="$HOME/Arduino/libraries/$LIBRARY_NAME"
  local GIT_URL="$2"

  if [ ! -d "$LIBRARY_PATH" ]; then
    echo "Cloning $LIBRARY_NAME into Arduino libraries folder..."
    git clone "$GIT_URL" "$LIBRARY_PATH"
  else
    echo "$LIBRARY_NAME already exists, skipping clone."
  fi
}

# Install necessary libraries for DisplayValueOLED
arduino-cli lib install "U8g2"  # U8x8lib.h is part of the U8g2 library

# Finish
echo "Library preparation complete."
