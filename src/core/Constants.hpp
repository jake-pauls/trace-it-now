#ifndef Constants_hpp
#define Constants_hpp

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

#include "Ray.hpp"
#include "Vec3.hpp"
#include "../Assert.hpp"

// Math

const double _INFINITY_ = std::numeric_limits<double>::infinity();
const double _PI_       = 3.1415926535897932385;
const double _PI_2_     = (_PI_ / 2);

// Image Settings

const float ASPECT_RATIO  = 16.0f / 9.0f;
const int   IMAGE_WIDTH   = 400;
const int   IMAGE_HEIGHT  = static_cast<int>(IMAGE_WIDTH / (ASPECT_RATIO));

// Utility Functions

inline float degToRad(float deg) { return deg * _PI_ / 180.0f; }

inline float randomFloat() { return rand() / (RAND_MAX + 1.0); }

inline float randomRange(float min, float max) { return min + (max - min) * randomFloat(); }

inline float clamp(float x, float min, float max)
{
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

#endif /* Constants_hpp */
