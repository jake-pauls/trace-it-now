#include <iostream>

#include "assert.hpp"
#include "utils/vec3.hpp"
#include "utils/ray.hpp"

// Image Settings
#define ASPECT_RATIO  16.0 / 9.0
#define IMAGE_WIDTH   400 
#define IMAGE_HEIGHT  static_cast<int>(IMAGE_WIDTH / (ASPECT_RATIO))

vec3 getRayColor(const Ray& r)
{
    vec3 unitDirection = Normalize(r.Direction);
    float t = 0.5 * (unitDirection.y() + 1.0);

    vec3 white(1.0f, 1.0f, 1.0f);
    vec3 blue(0.5f, 0.7f, 1.0f);

    // Lerp => blendedValue = (1 - t) * startValue + (t * endValue)
    return (1.0 - t) * white + (t * blue);
}

int main()
{
    // Camera
    float viewportHeight = 2.0f;
    float viewportWidth = ASPECT_RATIO * viewportHeight;
    float focalLength = 1.0f;

    vec3 origin(0.0f, 0.0f, 0.0f);
    vec3 horizontal(viewportWidth, 0.0f, 0.0f);
    vec3 vertical(0.0f, viewportHeight, 0.0f);
    vec3 lowerLeftCorner = origin - (horizontal / 2) - (vertical / 2) - vec3(0.0f, 0.0f, focalLength);

    // Renderer
    std::cout << "P3\n" << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n255\n";

    // Create a .ppm file for rendering
    // Refer to https://en.wikipedia.org/wiki/Netpbm for a breakdown on portable image formats
    for (int j = IMAGE_HEIGHT - 1; j >= 0; --j)
    {
        ELOG("Remaining lines: " << j << " ");

        for (int i = 0; i < IMAGE_WIDTH; ++i)
        {
            float u = float(i) / (IMAGE_WIDTH - 1);
            float v = float(j) / (IMAGE_HEIGHT - 1);

            Ray r(origin, lowerLeftCorner + (u * horizontal) + (v * vertical - origin));
            vec3 pixelColor = getRayColor(r);            

            WriteVecToStream(std::cout, pixelColor);
        }
    }

    ELOG("Successfully generated image data");

    return 0;
}
