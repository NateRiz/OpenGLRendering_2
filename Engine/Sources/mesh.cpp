#include "../Headers/mesh.h"
#include "../Headers/world.h"
#include "glad/glad.h"

Mesh::Mesh() :
    Actor(nullptr) {}

Mesh::Mesh(World* world) :
        Actor(world)
{
    world->AddMesh(this);
    glGenBuffers(1, &VBO);

}
Mesh::Mesh( World* world, std::vector<float>& v):
        Actor(world),
        mVertices(v)
{
    world->AddMesh(this);
    glGenBuffers(1, &VBO);
}


void Mesh::Draw()
{
    if (mVertices.empty())
        return;

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(float), mVertices.data(), GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)(sizeof(float)*0));
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLES, 0, (GLsizei)mVertices.size());
}