#include "../Headers/mesh.h"
#include "../Headers/world.h"
#include "../Headers/Camera.h"
#include "../Headers/transform.h"
#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

Mesh::Mesh() :
    Actor(nullptr),
    mShader(Shader("DefaultVertex.glsl","DefaultFragment.glsl"))
{}

Mesh::Mesh(World* world) :
        Actor(world),
        mShader(Shader("DefaultVertex.glsl","DefaultFragment.glsl"))
{
    world->AddMesh(this);
    glGenBuffers(1, &VBO);

}
Mesh::Mesh( World* world, std::vector<float>& v, Shader s):
        Actor(world),
        mVertices(v),
        mShader(s)
{
    world->AddMesh(this);
    glGenBuffers(1, &VBO);
}

void Mesh::SetMatrix(glm::mat4 matrix)
{
    mMatrix = matrix;
}


void Mesh::Draw()
{
    if (mVertices.empty())
        return;

    auto camTransform = GetWorld()->GetActiveCamera()->GetTransform();
    mShader.Use();
    mShader.setMat4("model", mMatrix);
    glm::mat4 view = glm::lookAt(camTransform->GetLocation(), camTransform->GetLocation() + camTransform->GetForward(),camTransform->GetUp());
    mShader.setMat4("view", view);
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    mShader.setMat4("projection",projection);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(float), mVertices.data(), GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)(sizeof(float)*0));
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, (GLsizei)mVertices.size());
}