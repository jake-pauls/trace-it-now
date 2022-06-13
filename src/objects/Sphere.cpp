#include <cmath>

#include "Sphere.hpp"

Sphere::Sphere()
{ }

Sphere::Sphere(Vec3 center, float radius)
    : Center(center), Radius(radius)
{ }

bool Sphere::IsHit(const Ray &ray, float tMin, float tMax, HitData &hitData) const
{
    Vec3 offset = ray.Origin - Center;

    // Construct quadratic
    float a = ray.Direction.LengthSquared();
    float halfB = Dot(offset, ray.Direction);
    float c = offset.LengthSquared() - (Radius * Radius);

    /**
     * As the equation for detecting a sphere is quadratic (even in a simplified form)
     * the discriminant determines the number of roots (which directly ties to geometry)
     *
     * If the ray misses the sphere       ->  0 Roots
     * If the ray intersects with an edge ->  1 Root
     * If the ray goes through the sphere ->  2 Roots
     */
    float discriminant = (halfB * halfB) - (a * c);

    // If discriminant is less than zero than quadratic returned no valid roots
    if (discriminant < 0) return false;

    float sqrtDiscriminant = std::sqrt(discriminant);

    // Detect the nearest root that lies in an acceptable range (of t)
    float root = (-halfB - sqrtDiscriminant) / a;
    if (root < tMin || tMax < root) {
        root = (-halfB + sqrtDiscriminant) / a;

        if (root < tMin || tMax < root)
            return false;
    }

    // Construct hit data with applicable root information
    hitData.t = root;
    hitData.point = ray.At(hitData.t);

    Vec3 outwardNormal = (hitData.point - Center) / Radius;
    hitData.SetFaceNormal(ray, outwardNormal);

    return true;
}
