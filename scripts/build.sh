#!/bin/sh
# Simple build script to make project and output/read image file
# Execute in the root directory of the project

mkdir -p build && cd build

cmake ..
make

# Send pixel data output to .ppm file
./trace-it-now > render.ppm

# Open image file (comment or modify this line for your image viewer)
feh render.ppm

# Update repository README image
cp build/render.ppm images/