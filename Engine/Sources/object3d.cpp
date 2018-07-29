#include "../Headers/object3d.h"
#include "../Headers/transform.h"
#include "../Headers/mesh.h"

Object3D::Object3D(World* world, Transform* transform) :
        Actor(world),
        mTransform(transform)
{

}

Object3D::Object3D(World* world) :
        Actor(world)
{

}

Transform* Object3D::GetTransform() const
{
    return mTransform;
}

void Object3D::SetTransform(Transform* t)
{
    mTransform = t;
}

void Object3D::SetMesh(Mesh* mesh)
{
    mMesh = mesh;
}

void Object3D::TryProcessInput(float delta)
{
    if(this == this->GetRoot())
    {
        this->ProcessInput(delta);
    }
}

void Object3D::TryProcessMouseMovement(float delta, double x, double y)
{
    if(this == this->GetRoot())
    {
        this->ProcessMouseMovement(delta, x, y);
    }

}

void Object3D::Tick(float delta)
{
    if (mMesh!=nullptr)
    {
        mMesh->SetMatrix(mTransform->GetMatrix());
    }
}

void Object3D::ProcessInput(float delta)
{
}

void Object3D::ProcessMouseMovement(float delta, double x, double y)
{
}


