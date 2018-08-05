#include "../Headers/Sun.h"
#include "../Headers/transform.h"
#include "glm/glm.hpp"

Sun::Sun(World* world):
    Mesh(world)
{
    auto t = new Transform();
    t->SetLocation(glm::vec3(10.f, 30.f, 10.f));
    SetTransform(t);
    SetVertices(mVertices);
    SetShader(Shader("Sun.glsl","SunFragment.glsl"));

}

Sun::~Sun()
{
    delete mVertices;
}
