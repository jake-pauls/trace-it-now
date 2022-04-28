#ifndef vec3_hpp
#define vec3_hpp

#include <cmath>
#include <iostream>

class vec3 
{
public:
    vec3() : f{0, 0, 0} {}
    vec3(float f0, float f1, float f2) : f{f0, f1, f2} {}

    // Points
    float x() const { return f[0]; }
    float y() const { return f[1]; }
    float z() const { return f[2]; }

    // Colors
    float r() const { return f[0]; }
    float g() const { return f[1]; }
    float b() const { return f[2]; }

    // Operator Overloads
    vec3 operator-() const;
    float operator[](int i) const;
    float& operator[](int i); 

    vec3& operator+=(const vec3 &v);
    vec3& operator*=(const float c);
    vec3& operator/=(const float c);

    // Utility Methods
    float Magnitude() const;
    float MagnitudeSquared() const;
    

public:
    float f[3];

// Additional vec3 Utilities
friend std::ostream& operator<<(std::ostream &out, const vec3 &v);
friend vec3 operator+(const vec3 &u, const vec3 &v);
friend vec3 operator-(const vec3 &u, const vec3 &v);
friend vec3 operator*(const vec3 &u, const vec3 &v);
friend vec3 operator*(float c, const vec3 &v);
friend vec3 operator*(const vec3 &v, float c);
friend vec3 operator/(vec3 v, float c);

friend float Dot(const vec3 &u, const vec3 &v);
friend vec3 Cross(const vec3 &u, const vec3 &v);
friend vec3 Normalize(vec3 v);

friend void WriteVecToStream(std::ostream &out, vec3 pixelColor);
};

#endif /* vec3_hpp */