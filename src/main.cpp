#include <iostream>

#include "core/camera.hpp"
#include "core/constants.hpp"
#include "objects/sphere.hpp"

#include "hittable_list.hpp"

vec3 getRayColor(const Ray& ray, const Hittable& world)
{
    HitData rayHitData;
    vec3 white(1.0f, 1.0f, 1.0f);
    vec3 blue(0.5f, 0.7f, 1.0f);

    if (world.IsHit(ray, 0, _INFINITY_, rayHitData)) {
        return 0.5 * (rayHitData.normal + white);
    }

    // Use y value of ray to render background
    vec3 unitDirection = Normalize(ray.Direction);
    auto t = 0.5 * (unitDirection.y() + 1.0f);

    // Lerp => blendedValue = (1 - t) * startValue + (t * endValue)
    return (1.0 - t) * white + (t * blue);
}

int main()
{
    Camera camera;
    const int samplesPerPixel = 100;

    // Setup world objects 
    HittableList worldObjects;

    // Center sphere
    worldObjects.Add(std::make_shared<Sphere>(vec3(0.0f, 0.0f, -1.0f), 0.5f));

    // Ground sphere
    worldObjects.Add(std::make_shared<Sphere>(vec3(0.0f, -100.5f, -1.0f), 100.0f));

    // Create a .ppm file for rendering
    // Refer to https://en.wikipedia.org/wiki/Netpbm for a breakdown on portable image formats
    std::cout << "P3\n" << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n255\n";

    for (int j = IMAGE_HEIGHT - 1; j >= 0; --j) {
        ELOG("Remaining lines: " << j << " ");

        for (int i = 0; i < IMAGE_WIDTH; ++i) {
            vec3 pixelColor(0.0f, 0.0f, 0.0f);

            for (int s = 0; s < samplesPerPixel; ++s) {
                auto u = (i + randomFloat()) / (IMAGE_WIDTH - 1);
                auto v = (j + randomFloat()) / (IMAGE_HEIGHT - 1);

                Ray ray = camera.GetRay(u, v);

                // Increment the color for each sample 
                pixelColor += getRayColor(ray, worldObjects);
            }

            // PixelColor is averaged during the write for antialiasing 
            WriteVecToStream(std::cout, pixelColor, samplesPerPixel);
        }
    }

    ELOG("Successfully generated image data");

    return 0;
}
