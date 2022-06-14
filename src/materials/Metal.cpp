#include "Metal.hpp"

#include "../Hittable.hpp"

Metal::Metal(const Vec3& albedo)
    : Albedo(albedo)
{ }

bool Metal::Scatter(const Ray &rayIn, const HitData &hitData, Vec3 &attenuation, Ray& scatteredRay) const
{
    Vec3 reflectedRay = Reflect(Normalize(rayIn.Direction), hitData.Normal);

    scatteredRay = Ray(hitData.Point, reflectedRay);
    attenuation = Albedo;

    return Dot(scatteredRay.Direction, hitData.Normal) > 0;
}

