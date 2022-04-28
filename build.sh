#!/bin/sh
# Simple build script to make project and output/read image file
mkdir -p build && cd build

cmake ..
make

# Send pixel data output to .ppm file
./trace-it-now > image.ppm

# Open image file (comment or modify this line for your image viewer)
feh image.ppm