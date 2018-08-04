#include "../Headers/Camera.h"
#include "../Headers/world.h"
#include "../Headers/transform.h"
#include <GLFW/glfw3.h>


Camera::Camera(World *world, Transform *transform) :
        Object3D(world, transform) {}

void Camera::Tick(float delta) {
    TryProcessInput(delta);
}


void Camera::ProcessMouseMovement(float delta, double x, double y)
{
    float sensitivity = delta * 2.5f;
    yaw += x * sensitivity;
    pitch -= y * sensitivity;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 rotation = GetTransform()->GetRotation();
    rotation.x = glm::radians(pitch);
    rotation.y = glm::radians(yaw);
    GetTransform()->SetRotation(rotation);
}

void Camera::ProcessInput(float delta) {
    float camSpeed = delta * 5.5f;
    glm::vec3 location = GetTransform()->GetLocation();

    if (glfwGetKey(GetWorld()->GetWindow(), GLFW_KEY_W) == GLFW_PRESS)
        location += camSpeed * GetTransform()->GetForward();
    else if (glfwGetKey(GetWorld()->GetWindow(), GLFW_KEY_S) == GLFW_PRESS)
        location -= camSpeed * GetTransform()->GetForward();

    if (glfwGetKey(GetWorld()->GetWindow(), GLFW_KEY_A) == GLFW_PRESS)
        location -= camSpeed * (glm::cross(GetTransform()->GetForward(), GetTransform()->GetUp()));
    else if (glfwGetKey(GetWorld()->GetWindow(), GLFW_KEY_D) == GLFW_PRESS)
        location += camSpeed * (glm::cross(GetTransform()->GetForward(), GetTransform()->GetUp()));

    GetTransform()->SetLocation(location);
}