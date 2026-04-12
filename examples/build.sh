#!/bin/bash

# Create build directory if it doesn't exist
BUILD_DIR="build"
mkdir -p "$BUILD_DIR"

# Search for C file in the examples directory
C_FILE=$(find . -type f -name "*.c" | head -n 1)

if [ -z "$C_FILE" ]; then
    echo "No C file found in the examples directory."
    exit 1
fi

# Extract the file name without the directory and extension
FILE_NAME=$(basename "$C_FILE" .c)

# Compile the C file and link it to glitc.h
OUTPUT_FILE="$BUILD_DIR/$FILE_NAME"
echo "Compiling $C_FILE to $OUTPUT_FILE..."
gcc "$C_FILE" -o "$OUTPUT_FILE" -I .

if [ $? -eq 0 ]; then
    echo "Build successful: $OUTPUT_FILE"
else
    echo "Build failed."
    exit 1
fi

