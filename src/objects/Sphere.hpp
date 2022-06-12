#ifndef Sphere_hpp
#define Sphere_hpp

#include "../Hittable.hpp"
#include "../core/Vec3.hpp"

class Sphere : public Hittable
{
public:
    Sphere();
    Sphere(Vec3 center, float radius);

    virtual bool IsHit(const Ray& ray, float tMin, float tMax, HitData& hitData) const override;

public:
    Vec3 Center;
    float Radius;
};

#endif /* Sphere_hpp */
