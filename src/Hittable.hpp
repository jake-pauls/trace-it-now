#ifndef Hittable_hpp
#define Hittable_hpp

#include "core/Vec3.hpp"
#include "core/Ray.hpp"

class Material;

struct HitData
{
    float t;
    Vec3 Point;
    Vec3 Normal;
    bool IsFrontFace;
    std::shared_ptr<Material> Mat;

    // Calculate direction of normals at geometry time
    // Ensure normals always point against the incident ray
    inline void SetFaceNormal(const Ray& ray, const Vec3& outwardNormal)
    {
        IsFrontFace = Dot(ray.Direction, outwardNormal) < 0;
        Normal = IsFrontFace ? outwardNormal : -outwardNormal;
    }
};

class Hittable
{
public:
    virtual bool IsHit(const Ray& ray, float tMin, float tMax, HitData& hitData) const = 0;
};

#endif /* Hittable_hpp */
