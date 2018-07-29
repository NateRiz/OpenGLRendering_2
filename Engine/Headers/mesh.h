#ifndef MESH_H
#define MESH_H
#include "actor.h"
#include "../../Geometry/Headers/Shader.h"

class Mesh : public Actor
{
public:
    Mesh();
    Mesh(World* world);
    Mesh(World* world, std::vector<float>&, Shader);
    void Draw();
    void SetMatrix(glm::mat4);

private:
    std::vector<float> mVertices;
    unsigned int VBO;
    Shader mShader;
    glm::mat4 mMatrix = glm::mat4(1.0);

};

#endif // MESH_H
