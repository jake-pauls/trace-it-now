#ifndef Hittable_hpp
#define Hittable_hpp

#include "core/Vec3.hpp"
#include "core/Ray.hpp"

struct HitData
{
    float t;
    Vec3 point;
    Vec3 normal;
    bool isFrontFace;

    // Calculate direction of normals at geometry time
    // Ensure normals always point against the incident ray
    inline void SetFaceNormal(const Ray& ray, const Vec3& outwardNormal)
    {
        isFrontFace = Dot(ray.Direction, outwardNormal) < 0;
        normal = isFrontFace ? outwardNormal : -outwardNormal;
    }
};

class Hittable 
{
public:
    virtual bool IsHit(const Ray& ray, float tMin, float tMax, HitData& hitData) const = 0;
};

#endif /* Hittable_hpp */
