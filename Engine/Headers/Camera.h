//
// Created by nathan on 7/15/18.
//

#ifndef VOXEL3_CLION_CAMERA_H
#define VOXEL3_CLION_CAMERA_H

#include "object3d.h"
#include "glm/glm.hpp"

class Camera : public Object3D{
public:
    Camera(World*, Transform*);
    virtual void Tick(float delta);
    virtual void ProcessMouseMovement(float delta, double x, double y);
    virtual void ProcessInput(float delta);




private:
    glm::vec3 mFront;
    glm::vec3 mUp;
    glm::vec3 mRight;

    static constexpr glm::vec3 WORLD_UP = glm::vec3(0, 1, 0);
};


#endif //VOXEL3_CLION_CAMERA_H
