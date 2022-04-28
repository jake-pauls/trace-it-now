#include <iostream>

#include "assert.hpp"
#include "utils/vec3.hpp"
#include "utils/color.hpp"

#define IMAGE_WIDTH  256
#define IMAGE_HEIGHT 256

int main()
{
    // Create a .ppm file for rendering
    // Refer to https://en.wikipedia.org/wiki/Netpbm for a breakdown on portable image formats

    color pixelColor;
    std::cout << "P3\n" << IMAGE_WIDTH << ' ' << IMAGE_HEIGHT << "\n255\n";

    for (int i = IMAGE_HEIGHT - 1; i >= 0; --i)
    {
        ELOG("Remaining lines: " << i << " ");

        for (int j = 0; j < IMAGE_WIDTH; ++j)
        {
            pixelColor = color(
                float(j) / (IMAGE_WIDTH  - 1), 
                float(i) / (IMAGE_HEIGHT - 1), 
                0.25
            );

            WriteColorToStream(std::cout, pixelColor);
        }
    }

    ELOG("Successfully generated image data");

    return 0;
}
