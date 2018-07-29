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
    std::vector<float> mVertices; /**< Vertices to be passed to the rendering pipeline */
    unsigned int VBO;
    Shader mShader;
    glm::mat4 mMatrix = glm::mat4(1.0);/**< Matrix passed in from Object3D containing this. Used to pass to shaders */

};

#endif // MESH_H
