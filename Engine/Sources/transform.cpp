#include "../Headers/transform.h"
#include "glm/gtc/matrix_transform.hpp"

void PrintMatrix(glm::mat4 m);

Transform::Transform():
    mLocation(glm::vec3(0,0,0)),
    mScale(glm::vec3(1,1,1)),
    mRotation(glm::vec3(0,0,0))
{
}

Transform::Transform(const Transform& transform)
{
    mLocation = transform.mLocation;
    mScale = transform.mScale;
    mRotation = transform.mRotation;
}

glm::vec3 Transform::GetLocation()
{
    return mLocation;
}

glm::vec3 Transform::GetScale()
{
    return mScale;
}

glm::vec3 Transform::GetRotation()
{
    return mRotation;
}

void Transform::SetLocation(glm::vec3 location)
{
    mLocation = location;
}
void Transform::SetRotation(glm::vec3 rotation)
{
    mRotation = rotation;
}
glm::vec3 Transform::GetForward()
{
    glm::mat4 m = GetMatrix();
    return glm::vec3(m[2][0], m[2][1], m[2][2]);
}

glm::vec3 Transform::GetUp()
{
    glm::mat4 m = GetMatrix();
    return glm::vec3(m[1][0], m[1][1], m[1][2]);
}
glm::mat4 Transform::GetMatrix()
{
    glm::mat4 matrix(1);
    matrix = glm::translate(matrix, mLocation);
    matrix = glm::rotate(matrix, mRotation.z, glm::vec3(0.0, 0.0, 1.0));
    matrix = glm::rotate(matrix, mRotation.y, glm::vec3(0.0, 1.0, 0.0));
    matrix = glm::rotate(matrix, mRotation.x, glm::vec3(1.0, 0.0, 0.0));
    matrix = glm::scale(matrix,mScale);
    //PrintMatrix(matrix);
    return matrix;
}

void PrintMatrix(glm::mat4 m)
{
 for(unsigned int i = 0; i < 4; i ++)
 {
     printf("|");
     for (unsigned int j = 0 ; j < 4; j ++)
     {
         printf("%f",m[i][j]);
         if(j<3)
             printf("\t");
     }
     printf("|\n");
 }
 printf("\n\n");
}