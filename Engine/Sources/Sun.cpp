#include "../Headers/Sun.h"
#include "../Headers/transform.h"
#include "../Headers/world.h"
#include "glm/glm.hpp"

Sun::Sun(World* world):
    Mesh(world, mVertices, Shader("Sun.glsl","SunFragment.glsl"))
{
    auto t = new Transform();
    t->SetLocation(glm::vec3(10.f, 30.f, 10.f));
    SetTransform(t);
}
Sun::~Sun() {}


void Sun::Tick(float delta)
{
    glm::vec3 pos = GetTransform()->GetLocation();
    double time = GetWorld()->GetTime();
    pos = glm::vec3(pos.x + 2.f*cos(time),pos.y + 2.f*sin(time), pos.z);
    GetTransform()->SetLocation(pos);
}