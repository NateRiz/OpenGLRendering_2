//
// Created by nathan on 7/15/18.
//

#include "../Headers/Camera.h"


Camera::Camera(World* world, Transform* transform) :
        Object3D(world, transform)
{}

void Camera::Tick(float delta)
{
    Object3D::Tick(delta);
    TryProcessInput(delta);
}


void Camera::ProcessMouseMovement(float delta, double x, double y)
{

}

void Camera::ProcessInput(float delta)
{

}

