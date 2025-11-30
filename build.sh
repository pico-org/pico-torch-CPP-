#!/bin/bash

# Simple build script for Pico-Torch-CPP
export PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games"

# Clean function
clean() {
    echo "Cleaning build artifacts..."
    rm -rf bin/
    rm -rf build/
    rm -rf obj/*.o 2>/dev/null
    echo "Clean complete!"
}

# Check if clean argument is passed
if [ "$1" = "clean" ]; then
    clean
    exit 0
fi

echo "Building Pico-Torch-CPP..."
mkdir -p bin

# Find and compile all .cpp files (root + src/)
MAIN_SOURCES=$(find . -maxdepth 1 -name "*.cpp" -type f)
SRC_SOURCES=$(find src/ -name "*.cpp" -type f 2>/dev/null || true)
ALL_SOURCES="$MAIN_SOURCES $SRC_SOURCES"
EXECUTABLE_NAME=$(basename "$(echo $MAIN_SOURCES | cut -d' ' -f1)" .cpp)

g++ -std=c++17 -Wall -Wextra -I./include -o bin/$EXECUTABLE_NAME $ALL_SOURCES

if [ $? -eq 0 ]; then
    echo "Build successful! Run: ./bin/$EXECUTABLE_NAME"
else
    echo "Build failed!"
    exit 1
fi
