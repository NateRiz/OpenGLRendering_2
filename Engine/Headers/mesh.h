#ifndef MESH_H
#define MESH_H
#include "actor.h"

class Mesh : public Actor
{
public:
    Mesh();
    Mesh(World* world);
    Mesh(World* world, std::vector<float>& v);
    void Draw();

private:
    std::vector<float> mVertices;
    unsigned int VBO;

};

#endif // MESH_H
