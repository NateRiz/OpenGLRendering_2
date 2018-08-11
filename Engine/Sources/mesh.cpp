#include "../Headers/mesh.h"
#include "../Headers/world.h"
#include "../Headers/Camera.h"
#include "../Headers/transform.h"
#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

Mesh::Mesh() :
    Object3D(nullptr),
    mShader(Shader("DefaultVertex.glsl","DefaultFragment.glsl")),
    mAreVerticesDirty(true)
{}

Mesh::Mesh(World* world):
        Object3D(world),
        mShader(Shader("DefaultVertex.glsl","DefaultFragment.glsl")),
        mAreVerticesDirty(true)
{
    world->AddMesh(this);
    glGenBuffers(1, &VBO);

}
Mesh::Mesh(World* world, std::vector<float> v, Shader s):
        Object3D(world),
        mVertices(v),
        mAreVerticesDirty(true),
        mShader(s)
{
    world->AddMesh(this);
    glGenBuffers(1, &VBO);
}

std::vector<float> &Mesh::GetVertices()
{
    return mVertices;
}

void Mesh::SetShader(Shader s)
{
    mShader = s;
}

void Mesh::Draw()
{
    if (mVertices.empty())
        return;

    printf("%d\n",(int)mVertices.size());

    auto camTransform = GetWorld()->GetActiveCamera()->GetTransform();
    mShader.Use();
    mShader.setMat4("model", GetTransform()->GetMatrix());
    glm::mat4 view = glm::lookAt(camTransform->GetLocation(), camTransform->GetLocation() + camTransform->GetForward(),camTransform->GetUp());
    mShader.setMat4("view", view);
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 300.0f);
    mShader.setMat4("projection",projection);
    mShader.setVec3("sunPos",GetWorld()->GetSun()->GetTransform()->GetLocation());


    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(float), mVertices.data(), GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(sizeof(float)*0));
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(sizeof(float)*3));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glDrawArrays(GL_TRIANGLES, 0, (GLsizei)mVertices.size());
}
//LAYOUT
/*
 *
 *  POS.X   POS.Y   POS.Z   NORMAL.X    NORMAL.Y    NORMAL.Z
 *
 */

