#ifndef Camera_hpp
#define Camera_hpp

#include "Constants.hpp"

class Camera 
{
public:
    Camera();

    Ray GetRay(float u, float v) const;

public:
    Vec3 Origin;
    Vec3 LowerLeftCorner;
    Vec3 Horizontal;
    Vec3 Vertical;
};

#endif /* Camera_hpp */