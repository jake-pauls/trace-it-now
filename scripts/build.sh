#!/bin/sh
# Simple build script to make project and output/read image file
# Execute in the root directory of the project

premake5 gmake2 --file="scripts/premake5.lua"
make

# Send pixel data output to .ppm file
./build/Debug/trace-it-now > render.ppm

# Optional: Open image file with image viewer
feh render.ppm

# Optional: Update repository README image (netpbm)
pnmtopng render.ppm > ./images/render.png

# Clean .ppm file
rm render.ppm
