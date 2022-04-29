#!/bin/sh
# Simple build script to make project and output/read image file
# Execute in the root directory of the project

mkdir -p build && cd build

cmake ..
make

# Send pixel data output to .ppm file
./trace-it-now > render.ppm

# Optional: Open image file with image viewer
feh render.ppm

# Optional: Update repository README image (imagemagick)
pnmtopng render.ppm > ../images/render.png