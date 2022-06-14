#ifndef Lambertian_hpp
#define Lambertian_hpp

#include "Material.hpp"

class Lambertian : public Material
{
public:
    Lambertian(const Vec3& albedo);

    bool Scatter(const Ray& rayIn, const HitData& hitData, Vec3& attenuation, Ray& scatteredRay) const override;

public:
    Vec3 Albedo;
};

#endif /* Lambertian_hpp */
