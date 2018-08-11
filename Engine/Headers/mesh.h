#ifndef MESH_H
#define MESH_H
#include "object3d.h"
#include "Shader.h"
#include <string>
using std::string;

class Transform;
#include "../Headers/Shader.h"

class Mesh : public Object3D
{
public:
    Mesh();
    Mesh(World*);
    Mesh(World*, std::vector<float>, Shader);
    void SetShader(Shader);
    void SetTexture(string);
    std::vector<float>& GetVertices();
    void Draw();

private:
    std::vector<float> mVertices; /**< Vertices to be passed to the rendering pipeline */
    bool mAreVerticesDirty; /**< Determines whether vertices need to be optimized*/
    unsigned int VBO;
    unsigned int mTexture;
    Shader mShader;
};

#endif // MESH_H
