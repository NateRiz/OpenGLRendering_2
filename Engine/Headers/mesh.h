#ifndef MESH_H
#define MESH_H
#include "object3d.h"
#include "../../Geometry/Headers/Shader.h"

class Transform;

class Mesh : public Object3D
{
public:
    Mesh();
    Mesh(World*);
    Mesh(World*, std::vector<float>*, Shader);
    void SetVertices(std::vector<float>*);

    void Draw();

private:
    std::vector<float>* mVertices; /**< Vertices to be passed to the rendering pipeline */
    bool mAreVerticesDirty; /**< Determines whether vertices need to be optimized*/
    unsigned int VBO;
    Shader mShader;
};

#endif // MESH_H
