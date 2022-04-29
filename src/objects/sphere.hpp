#ifndef Sphere_hpp
#define Sphere_hpp

#include "../hittable.hpp"
#include "../core/vec3.hpp"

class Sphere : public Hittable
{
public:
    Sphere();
    Sphere(vec3 center, float radius);

    virtual bool IsHit(const Ray& ray, float tMin, float tMax, HitData& hitData) const override;

public:
    vec3 Center;
    float Radius;
};

#endif /* Sphere_hpp */
