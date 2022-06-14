#include "Lambertian.hpp"

#include "../Hittable.hpp"

Lambertian::Lambertian(const Vec3& albedo)
    : Albedo(albedo)
{ }

bool Lambertian::Scatter(const Ray &rayIn, const HitData &hitData, Vec3 &attenuation, Ray& scatteredRay) const
{
    Vec3 scatterDirection = hitData.Normal + Vec3::RandomUnitVector();

    // Prevent scatter direction from being a Vec3.Zero
    if (scatterDirection.IsNearZero())
        scatterDirection = hitData.Normal;

    scatteredRay = Ray(hitData.Point, scatterDirection);
    attenuation = Albedo;

    return true;
}

