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


private:
    glm::mat4 mMatrix;

};





#endif // TRANSFORM_H
