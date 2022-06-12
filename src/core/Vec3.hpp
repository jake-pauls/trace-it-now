#ifndef Vec3_hpp
#define Vec3_hpp

#include <cmath>
#include <iostream>

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
    float Magnitude() const;
    float MagnitudeSquared() const;


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

friend void WriteVecToStream(std::ostream &out, Vec3 pixelColor, int samplesPerPixel);
};

#endif /* Vec3_hpp */
