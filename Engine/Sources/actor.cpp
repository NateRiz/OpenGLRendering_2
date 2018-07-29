#include "../Headers/actor.h"
#include "../Headers/world.h"

Actor::Actor(World* world) :
    mWorld(world)
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

void Actor::AddChild(Actor* child)
{
    child->SetParent(this);
    mChildren.push_back(child);
}

void Actor::SetParent(Actor* parent)
{
    mParent = parent;
}

std::vector<Actor*> Actor::GetChildren()
{
    return mChildren;
}

Actor* Actor::GetRoot()
{
    if(this->GetParent() != nullptr)
        return this->GetParent();
    else
        return this;
}
