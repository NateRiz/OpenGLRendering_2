#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "actor.h"
class Transform;
class Mesh;

class Object3D : public Actor
{
public:
    Object3D(){}
    Object3D(World*);
    Object3D(World*, Transform*);

    Transform* GetTransform() const;
    void SetTransform(Transform*);
    void SetMesh(Mesh*);
    void TryProcessInput(float delta);
    void TryProcessMouseMovement(float delta, double x, double y);

    virtual void Tick(float);

    virtual void ProcessInput(float delta)=0;
    virtual void ProcessMouseMovement(float delta, double x, double y)=0;


private:
    Transform* mTransform;
    Mesh* mMesh;
};

#endif // OBJECT3D_H
