#include "../Headers/mesh.h"
#include "../Headers/world.h"
#include "../Headers/Camera.h"
#include "../Headers/transform.h"
#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "../Headers/stb_image.h"

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
    glGenTextures(1, &mTexture);

}
Mesh::Mesh(World* world, std::vector<float> v, Shader s):
        Object3D(world),
        mVertices(v),
        mAreVerticesDirty(true),
        mShader(s)
{
    world->AddMesh(this);
    glGenBuffers(1, &VBO);
    glGenTextures(1, &mTexture);

}

std::vector<float> &Mesh::GetVertices()
{
    return mVertices;
}

void Mesh::SetShader(Shader s)
{
    mShader = s;
}

void Mesh::SetTexture(string s)
{
    glBindTexture(GL_TEXTURE_2D, mTexture);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    unsigned char *data = stbi_load(("../Assets/"+s).c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
}

void Mesh::Draw()
{
    if (mVertices.empty())
        return;

    //printf("%d\n",(int)mVertices.size());

    auto camTransform = GetWorld()->GetActiveCamera()->GetTransform();
    mShader.Use();
    mShader.setMat4("model", GetTransform()->GetMatrix());
    glm::mat4 view = glm::lookAt(camTransform->GetLocation(), camTransform->GetLocation() + camTransform->GetForward(),camTransform->GetUp());
    mShader.setMat4("view", view);
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 300.0f);
    mShader.setMat4("projection",projection);
    mShader.setVec3("sunPos",GetWorld()->GetSun()->GetTransform()->GetLocation());
    mShader.setInt("tex", 0);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(float), mVertices.data(), GL_DYNAMIC_DRAW);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mTexture);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(sizeof(float)*0));
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(sizeof(float)*3));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(sizeof(float)*6));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glDrawArrays(GL_TRIANGLES, 0, (GLsizei)mVertices.size());
}
//LAYOUT
/*
 *
 *  POS.X   POS.Y   POS.Z   NORMAL.X    NORMAL.Y    NORMAL.Z
 *
 */

