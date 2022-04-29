#ifndef Camera_hpp
#define Camera_hpp

#include "constants.hpp"

class Camera 
{
public:
    Camera();

    Ray GetRay(float u, float v) const;

public:
    vec3 Origin;
    vec3 LowerLeftCorner;
    vec3 Horizontal;
    vec3 Vertical;
};

#endif /* Camera_hpp */