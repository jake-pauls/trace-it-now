#ifndef Material_hpp
#define Material_hpp

#include "../core/Ray.hpp"

struct HitData;

class Material
{
public:
    virtual bool Scatter(const Ray& rayIn, const HitData& hitData, Vec3& attenuation, Ray& scatteredRay) const = 0;
};

#endif /* Material_hpp */
