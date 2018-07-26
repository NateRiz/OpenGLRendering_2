#include "../Headers/Renderer.h"
#include "../Headers/mesh.h"


void Renderer::AddMesh(Mesh *mesh)
{
    mDrawable.push_back(mesh);
}



void Renderer::DrawAll()
{
    for (auto it = mDrawable.begin(); it != mDrawable.end(); it++)
    {
        (*it)->Draw();
    }
}