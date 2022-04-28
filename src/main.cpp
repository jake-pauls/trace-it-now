#include <cmath>
#include <iostream>

#include "assert.hpp"
#include "core/vec3.hpp"
#include "core/ray.hpp"

// Image Settings
#define ASPECT_RATIO  16.0 / 9.0
#define IMAGE_WIDTH   400 
#define IMAGE_HEIGHT  static_cast<int>(IMAGE_WIDTH / (ASPECT_RATIO))

float hitSphere(const vec3& center, float radius, const Ray& ray)
{
    vec3 offset = ray.Origin - center;

    float a = ray.Direction.MagnitudeSquared();
    float halfB = Dot(offset, ray.Direction);
    float c = offset.MagnitudeSquared() - (radius * radius);

    /** 
     * As the equation for detecting a sphere is quadratic (even in a simplified form)
     * the discriminant determines the number of roots (which directly ties to geometry)
     *
     * If the ray misses the sphere       ->  0 Roots
     * If the ray intersects with an edge ->  1 Root
     * If the ray goes through the sphere ->  2 Roots 
     */ 
    float discriminant = (halfB * halfB) - (a * c);

    // Check if ray missed geometry in the scene
    if (discriminant < 0) {
        return -1.0f;
    }

    return (-halfB - std::sqrt(discriminant)) / a;
}

vec3 getRayColor(const Ray& ray)
{
    vec3 white(1.0f, 1.0f, 1.0f);
    vec3 blue(0.5f, 0.7f, 1.0f);

    float t = hitSphere(vec3(0.0f, 0.0f, -1.0f), 0.5f, ray);

    if (t > 0.0f) {
        // Shade the sphere normals based on distance from the origin 
        vec3 N = Normalize(ray.At(t) - vec3(0.0f, 0.0f, -1.0f));
        return 0.5 * vec3(N.x() + 1, N.y() + 1, N.z() + 1);
    }

    // Use y value of ray to render background
    vec3 unitDirection = Normalize(ray.Direction);
    t = 0.5 * (unitDirection.y() + 1.0f);

    // Lerp => blendedValue = (1 - t) * startValue + (t * endValue)
    return (1.0 - t) * white + (t * blue);
}

int main()
{
    // Configure camera parameters 
    float viewportHeight = 2.0f;
    float viewportWidth = ASPECT_RATIO * viewportHeight;
    float focalLength = 1.0f;

    vec3 origin(0.0f, 0.0f, 0.0f);
    vec3 horizontal(viewportWidth, 0.0f, 0.0f);
    vec3 vertical(0.0f, viewportHeight, 0.0f);
    vec3 lowerLeftCorner = origin - (horizontal / 2) - (vertical / 2) - vec3(0.0f, 0.0f, focalLength);

    // Create a .ppm file for rendering
    // Refer to https://en.wikipedia.org/wiki/Netpbm for a breakdown on portable image formats
    std::cout << "P3\n" << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n255\n";

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
