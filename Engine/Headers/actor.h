#ifndef ACTOR_H
#define ACTOR_H

class World;
#include <vector>


class Actor
{
public:
    Actor(){}
    Actor(World* world);
    World* GetWorld();
    virtual void Tick(float delta){}
    Actor* GetRoot();
    Actor* GetParent();
    std::vector<Actor*> GetChildren();
    void AddChild(Actor*);
    void SetParent(Actor* parent);

private:
    World* mWorld;
    Actor* mParent = nullptr;
    std::vector<Actor*> mChildren;

};


#endif // ACTOR_H
