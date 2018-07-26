#ifndef ACTOR_H
#define ACTOR_H
class World;
#include <vector>


class Actor
{
public:
    Actor(){}
    Actor(World* world);
    Actor(World* world, Actor* parent);
    World* GetWorld();
    virtual void Tick(float delta){}
    Actor* GetRoot();
    Actor* GetParent();

private:
    World* mWorld;
    Actor* mParent = nullptr;
    std::vector<Actor> mChildren;

};


#endif // ACTOR_H
