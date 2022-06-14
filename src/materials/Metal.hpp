#ifndef Metal_hpp
#define Metal_hpp

#include "Material.hpp"

class Metal : public Material
{
public:
    Metal(const Vec3& albedo);

    bool Scatter(const Ray& rayIn, const HitData& hitData, Vec3& attenuation, Ray& scatteredRay) const override;

public:
    Vec3 Albedo;
};

#endif /* Metal_hpp */
