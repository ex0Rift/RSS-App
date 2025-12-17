#!/bin/bash
clear
echo "Compiling..."
g++ src/main.cpp src/callbacks.cpp -Iinclude -o app $(pkg-config --cflags --libs gtkmm-4.0)
if [ $? -ne 0 ]; then
    echo "Compile failed! exiting..."
    exit 1
fi
./app