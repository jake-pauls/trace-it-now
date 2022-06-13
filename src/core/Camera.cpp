#include "Camera.hpp"

Camera::Camera()
{
    float viewportHeight = 2.0f;
    float viewportWidth = ASPECT_RATIO * viewportHeight;
    float focalLength = 1.0f;

    Origin = Vec3(0.0f, 0.0f, 0.0f);
    Horizontal = Vec3(viewportWidth, 0.0f, 0.0f);
    Vertical = Vec3(0.0f, viewportHeight, 0.0f);
    LowerLeftCorner = Origin - (Horizontal / 2) - (Vertical / 2) - Vec3(0.0f, 0.0f, focalLength);
}

Ray Camera::GetRay(float u, float v) const
{
    return Ray(Origin, LowerLeftCorner + (u * Horizontal) + (v * Vertical - Origin));
}
