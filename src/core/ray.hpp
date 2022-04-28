#ifndef ray_hpp
#define ray_hpp

#include "vec3.hpp"

class Ray
{
public:
    Ray() {}
    Ray(const vec3& origin, const vec3& direction)
        : Origin(origin), Direction(direction)
    {}

    // Imagine a linear relation
    // P(t) = A + tb
    vec3 At(float t) const { return Origin + (t * Direction); }

public:
    vec3 Origin;
    vec3 Direction;
};

#endif /* ray_hpp */