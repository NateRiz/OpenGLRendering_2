#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <glm/glm.hpp>
#include <stdexcept>
#include <iostream>


class Transform
{
public:
    Transform();
    Transform(const Transform&);
    glm::mat4 GetMatrix();
    glm::vec3 GetLocation();
    glm::vec3 GetRotation();
    glm::vec3 GetScale();
    void SetLocation(glm::vec3);
    void SetRotation(glm::vec3);
    glm::vec3 GetForward();
    glm::vec3 GetUp();


private:
    glm::vec3 mLocation;
    glm::vec3 mScale;
    glm::vec3 mRotation;
};





#endif // TRANSFORM_H
