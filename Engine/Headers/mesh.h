#ifndef MESH_H
#define MESH_H
#include "actor.h"
#include "../../Geometry/Headers/Shader.h"
class Transform;

class Mesh : public Actor
{
public:
    Mesh();
    Mesh(World*);
    Mesh(World*, std::vector<float>&, Shader);
    void SetVertices(std::vector<float>&);

    void Draw();

private:
    std::vector<float> mVertices; /**< Vertices to be passed to the rendering pipeline */
    unsigned int VBO;
    Shader mShader;
};

#endif // MESH_H
