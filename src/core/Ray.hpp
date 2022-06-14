#ifndef Ray_hpp
#define Ray_hpp

#include "Vec3.hpp"

class Ray
{
public:
    Ray() {}
    Ray(const Vec3& origin, const Vec3& direction)
        : Origin(origin), Direction(direction)
    {}

    // Imagine a linear relation
    // P(t) = A + tb
    Vec3 At(float t) const { return Origin + (t * Direction); }

public:
    Vec3 Origin;
    Vec3 Direction;
};

#endif /* Ray_hpp */
