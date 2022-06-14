#include <iostream>

#include "core/Vec3.hpp"
#include "core/Ray.hpp"
#include "core/Camera.hpp"
#include "core/Constants.hpp"
#include "objects/Sphere.hpp"
#include "materials/Material.hpp"
#include "materials/Lambertian.hpp"
#include "materials/Metal.hpp"

#include "HittableList.hpp"

Vec3 getRayColor(const Ray& ray, const Hittable& world, int depth)
{
    HitData rayHitData;
    Vec3 white(1.0f, 1.0f, 1.0f);
    Vec3 blue(0.5f, 0.7f, 1.0f);

    // Base Case: If the ray bounce limit has been exceeded, no more light is returned
    if (depth <= 0)
        return Vec3(0.0f, 0.0f, 0.0f);

    // Account for shadow acne and ignore rays that reflect very close to 0
    // ie: rays that reflect at -0.000001 or 0.000001 instead of 0.0
    if (world.IsHit(ray, 0.001, _INFINITY_, rayHitData))
    {
        Ray scatteredRay;
        Vec3 attenuation;

        if (rayHitData.Mat->Scatter(ray, rayHitData, attenuation, scatteredRay))
            return attenuation * getRayColor(scatteredRay, world, depth - 1);

        return Vec3(0.0f, 0.0f, 0.0f);
    }

    // Use y value of ray to render background
    Vec3 unitDirection = Normalize(ray.Direction);
    auto t = 0.5 * (unitDirection.y() + 1.0f);

    // Lerp => blendedValue = (1 - t) * startValue + (t * endValue)
    return (1.0 - t) * white + (t * blue);
}

int main()
{
    Camera camera;
    const int samplesPerPixel = 100;
    const int maxDepth = 50;

    // Setup world objects
    HittableList worldObjects;

    // Lambertian & Metal Spheres
    auto materialGround = std::make_shared<Lambertian>(Vec3(0.8f, 0.8f, 0.0f));
    auto materialCenter = std::make_shared<Lambertian>(Vec3(0.7f, 0.3f, 0.3f));
    auto materialLeft = std::make_shared<Metal>(Vec3(0.8f, 0.8f, 0.8f));
    auto materialRight = std::make_shared<Metal>(Vec3(0.8f, 0.6f, 0.2f));

    worldObjects.Add(std::make_shared<Sphere>(Vec3(0.0f, -100.5f, -1.0f), 100.0f, materialGround));
    worldObjects.Add(std::make_shared<Sphere>(Vec3(0.0f, 0.0f, -1.0f), 0.5f, materialCenter));
    worldObjects.Add(std::make_shared<Sphere>(Vec3(-1.0f, 0.0f, -1.0f), 0.5f, materialLeft));
    worldObjects.Add(std::make_shared<Sphere>(Vec3(1.0f, 0.0f, -1.0f), 0.5f, materialRight));

    // Create a .ppm file for rendering
    // Refer to https://en.wikipedia.org/wiki/Netpbm for a breakdown on portable image formats
    std::cout << "P3\n" << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n255\n";

    for (int j = IMAGE_HEIGHT - 1; j >= 0; --j)
    {
        ELOG("Remaining lines: " << j << " ");

        for (int i = 0; i < IMAGE_WIDTH; ++i)
        {
            Vec3 pixelColor(0.0f, 0.0f, 0.0f);

            for (int s = 0; s < samplesPerPixel; ++s)
            {
                float u = (i + RandomFloat()) / (IMAGE_WIDTH - 1);
                float v = (j + RandomFloat()) / (IMAGE_HEIGHT - 1);

                Ray ray = camera.GetRay(u, v);

                // Increment the color for each sample
                pixelColor += getRayColor(ray, worldObjects, maxDepth);
            }

            // PixelColor is averaged during the write for antialiasing
            WriteVecToStream(std::cout, pixelColor, samplesPerPixel);
        }
    }

    ELOG("Successfully generated image data");

    return 0;
}
