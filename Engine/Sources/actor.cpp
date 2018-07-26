#include "../Headers/actor.h"
#include "../Headers/world.h"

Actor::Actor(World* world) :
    mWorld(world)
{
    mWorld->AddActor(this);
}

Actor::Actor(World* world, Actor* parent):
    mWorld(world),
    mParent(parent)
{
    mWorld->AddActor(this);
}

World* Actor::GetWorld()
{
    return mWorld;
}

Actor* Actor::GetParent()
{
    return mParent;
}

Actor* Actor::GetRoot(){
    if(this->GetParent() != nullptr)
        return this->GetParent();
    else
        return this;
}
