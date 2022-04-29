#include "vec3.hpp"

#include "constants.hpp"

vec3::vec3() : f{0, 0, 0}
{ }

vec3::vec3(float f0, float f1, float f2)
    : f{f0, f1, f2}
{ }

vec3 vec3::operator-() const
{
    return vec3(-f[0], -f[1], -f[2]);
}

float vec3::operator[](int i) const
{
    return f[i];
}

float& vec3::operator[](int i)
{
    return f[i];
}

vec3& vec3::operator+=(const vec3 &v)
{
    f[0] += v.f[0];
    f[1] += v.f[1];
    f[2] += v.f[2];
    return *this;
}

vec3& vec3::operator*=(const float c)
{
    f[0] *= c;
    f[1] *= c;
    f[2] *= c;
    return *this;
}

vec3& vec3::operator/=(const float c)
{
    return *this *= 1/c;
}

float vec3::Magnitude() const
{
    return std::sqrt(MagnitudeSquared());
}

float vec3::MagnitudeSquared() const
{
    return f[0] * f[0] + f[1] * f[1] + f[2] * f[2];
}

std::ostream& operator<<(std::ostream &out, const vec3 &v)
{
    return out << v.f[0] << " " << v.f[1] << " " << v.f[2];
}

vec3 operator+(const vec3 &u, const vec3 &v)
{
    return vec3(u.f[0] + v.f[0], u.f[1] + v.f[1], u.f[2] + v.f[2]);
}

vec3 operator-(const vec3 &u, const vec3 &v)
{
    return vec3(u.f[0] - v.f[0], u.f[1] - v.f[1], u.f[2] - v.f[2]);
}

vec3 operator*(const vec3 &u, const vec3 &v)
{
    return vec3(u.f[0] * v.f[0], u.f[1] * v.f[1], u.f[2] * v.f[2]);
}

vec3 operator*(float c, const vec3 &v)
{
    return vec3(c * v.f[0], c * v.f[1], c * v.f[2]);
}

vec3 operator*(const vec3 &v, float c)
{
    return c * v;
}

vec3 operator/(vec3 v, float c)
{
    return (1/c) * v;
}

float Dot(const vec3 &u, const vec3 &v)
{
    return u.f[0] * v.f[0] + u.f[1] * v.f[1] + u.f[2] * v.f[2];
}

vec3 Cross(const vec3 &u, const vec3 &v)
{
    return vec3(u.f[1] * v.f[2] - u.f[2] * v.f[1],
                u.f[2] * v.f[0] - u.f[0] * v.f[2],
                u.f[0] * v.f[1] - u.f[1] * v.f[0]);
}

vec3 Normalize(vec3 v)
{
    return v / v.Magnitude();
}

// Note: In the original this is 'WriteColor'
// This code is refactored without use of the 'color' and 'point3' aliases
void WriteVecToStream(std::ostream &out, vec3 pixelColor, int samplesPerPixel)
{
    auto r = pixelColor.r();
    auto g = pixelColor.g();
    auto b = pixelColor.b();

    // Divide the color by the number of samples (antialiasing)
    auto scale = 1.0 / samplesPerPixel;

    r *= scale;
    g *= scale;
    b *= scale;

    // Write the translated value for each color component
    out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << " "
        << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << " "
        << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << "\n";
}
