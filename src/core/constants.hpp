#ifndef Constants_hpp
#define Constants_hpp

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

#include "ray.hpp"
#include "vec3.hpp"
#include "../assert.hpp"

// Math Constants

#define _INFINITY_  std::numeric_limits<double>::infinity()
#define _PI_        3.1415926535897932385
#define _PI_2_      (PI / 2)

// Image Settings

#define ASPECT_RATIO  16.0 / 9.0
#define IMAGE_WIDTH   400
#define IMAGE_HEIGHT  static_cast<int>(IMAGE_WIDTH / (ASPECT_RATIO))

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