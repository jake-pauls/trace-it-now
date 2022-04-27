#include <iostream>

#include "Assert.hpp"

#define IMAGE_WIDTH  256
#define IMAGE_HEIGHT 256

int main()
{
    // Create a .ppm file for rendering
    // Refer to https://en.wikipedia.org/wiki/Netpbm for a breakdown on portable image formats

    std::cout << "P3\n" << IMAGE_WIDTH << ' ' << IMAGE_HEIGHT << "\n255\n";

    for (int i = IMAGE_HEIGHT - 1; i >= 0; --i)
    {
        for (int j = 0; j < IMAGE_WIDTH; ++j)
        {
            auto r = double(j) / (IMAGE_WIDTH - 1);
            auto g = double(i) / (IMAGE_HEIGHT - 1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    return 0;
}
