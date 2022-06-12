#include "Vec3.hpp"

#include "Constants.hpp"

Vec3::Vec3() : f{0, 0, 0}
{ }

Vec3::Vec3(float f0, float f1, float f2)
    : f{f0, f1, f2}
{ }

Vec3 Vec3::operator-() const
{
    return Vec3(-f[0], -f[1], -f[2]);
}

float Vec3::operator[](int i) const
{
    return f[i];
}

float& Vec3::operator[](int i)
{
    return f[i];
}

Vec3& Vec3::operator+=(const Vec3 &v)
{
    f[0] += v.f[0];
    f[1] += v.f[1];
    f[2] += v.f[2];
    return *this;
}

Vec3& Vec3::operator*=(const float c)
{
    f[0] *= c;
    f[1] *= c;
    f[2] *= c;
    return *this;
}

Vec3& Vec3::operator/=(const float c)
{
    return *this *= 1/c;
}

float Vec3::Magnitude() const
{
    return std::sqrt(MagnitudeSquared());
}

float Vec3::MagnitudeSquared() const
{
    return f[0] * f[0] + f[1] * f[1] + f[2] * f[2];
}

std::ostream& operator<<(std::ostream &out, const Vec3 &v)
{
    return out << v.f[0] << " " << v.f[1] << " " << v.f[2];
}

Vec3 operator+(const Vec3 &u, const Vec3 &v)
{
    return Vec3(u.f[0] + v.f[0], u.f[1] + v.f[1], u.f[2] + v.f[2]);
}

Vec3 operator-(const Vec3 &u, const Vec3 &v)
{
    return Vec3(u.f[0] - v.f[0], u.f[1] - v.f[1], u.f[2] - v.f[2]);
}

Vec3 operator*(const Vec3 &u, const Vec3 &v)
{
    return Vec3(u.f[0] * v.f[0], u.f[1] * v.f[1], u.f[2] * v.f[2]);
}

Vec3 operator*(float c, const Vec3 &v)
{
    return Vec3(c * v.f[0], c * v.f[1], c * v.f[2]);
}

Vec3 operator*(const Vec3 &v, float c)
{
    return c * v;
}

Vec3 operator/(Vec3 v, float c)
{
    return (1/c) * v;
}

float Dot(const Vec3 &u, const Vec3 &v)
{
    return u.f[0] * v.f[0] + u.f[1] * v.f[1] + u.f[2] * v.f[2];
}

Vec3 Cross(const Vec3 &u, const Vec3 &v)
{
    return Vec3(u.f[1] * v.f[2] - u.f[2] * v.f[1],
                u.f[2] * v.f[0] - u.f[0] * v.f[2],
                u.f[0] * v.f[1] - u.f[1] * v.f[0]);
}

Vec3 Normalize(Vec3 v)
{
    return v / v.Magnitude();
}

// Note: In the original this is 'WriteColor'
// This code is refactored without use of the 'color' and 'point3' aliases
void WriteVecToStream(std::ostream &out, Vec3 pixelColor, int samplesPerPixel)
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
