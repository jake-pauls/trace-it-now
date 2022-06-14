#ifndef Vec3_hpp
#define Vec3_hpp

#include <cmath>
#include <iostream>

#include "Constants.hpp"

class Vec3
{
public:
    Vec3();
    Vec3(float f0, float f1, float f2);

    // Points
    float x() const { return f[0]; }
    float y() const { return f[1]; }
    float z() const { return f[2]; }

    // Colors
    float r() const { return f[0]; }
    float g() const { return f[1]; }
    float b() const { return f[2]; }

    // Operator Overloads
    Vec3 operator-() const;
    float operator[](int i) const;
    float& operator[](int i);

    Vec3& operator+=(const Vec3 &v);
    Vec3& operator*=(const float c);
    Vec3& operator/=(const float c);

    // Utility Methods
    float Length() const;
    float LengthSquared() const;
    bool IsNearZero() const;

    inline static Vec3 Random()
    {
        return Vec3(RandomFloat(), RandomFloat(), RandomFloat());
    }

    inline static Vec3 Random(float min, float max)
    {
        return Vec3(RandomFloat(min, max), RandomFloat(min, max), RandomFloat(min, max));
    }

    // Diffuse by UnitSphere
    inline static Vec3 RandomInUnitSphere()
    {
        while (true)
        {
            auto point = Vec3::Random(-1, 1);

            // Reject point if outside sphere
            if (point.LengthSquared() >= 1)
                continue;

            return point;
        }
    }

    // Diffuse by UnitHemisphere
    inline static Vec3 RandomInUnitHemisphere(const Vec3& normal)
    {
        Vec3 inUnitSphere = RandomInUnitSphere();

        // Point is in the same hemisphere as the normal
        if (Dot(inUnitSphere, normal) >= 0.0)
            return inUnitSphere;

        return -inUnitSphere;
    }

    // Diffuse by UnitVector within UnitSphere (Lambertian Reflection)
    inline static Vec3 RandomUnitVector()
    {
        return Normalize(RandomInUnitSphere());
    }

public:
    float f[3];

    // Additional Vec3 Utilities
    friend std::ostream& operator<<(std::ostream &out, const Vec3 &v);
    friend Vec3 operator+(const Vec3 &u, const Vec3 &v);
    friend Vec3 operator-(const Vec3 &u, const Vec3 &v);
    friend Vec3 operator*(const Vec3 &u, const Vec3 &v);
    friend Vec3 operator*(float c, const Vec3 &v);
    friend Vec3 operator*(const Vec3 &v, float c);
    friend Vec3 operator/(Vec3 v, float c);

    friend float Dot(const Vec3 &u, const Vec3 &v);
    friend Vec3 Cross(const Vec3 &u, const Vec3 &v);
    friend Vec3 Normalize(Vec3 v);
    friend Vec3 Reflect(const Vec3& v, const Vec3& n);

    friend void WriteVecToStream(std::ostream &out, Vec3 pixelColor, int samplesPerPixel);
};

#endif /* Vec3_hpp */
