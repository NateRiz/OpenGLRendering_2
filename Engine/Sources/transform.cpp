#include "../Headers/transform.h"

Transform::Transform()
{
    mMatrix = glm::mat4(1.f);
}

Transform::Transform(const Transform& transform)
{
    mMatrix = transform.mMatrix;
}
