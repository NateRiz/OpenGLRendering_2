#include "../Headers/world.h"
#include "../Headers/actor.h"
#include "../Headers/object3d.h"
#include "../Headers/Renderer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

World::World()
{
    mWorldTime = (float)glfwGetTime();
    mDeltaTime = mWorldTime;
    mLastTime = mWorldTime;
    mRenderer = new Renderer();
}

void World::Update()
{
    mWorldTime = (float)glfwGetTime();
    mDeltaTime = mWorldTime - mLastTime;
    mLastTime = mWorldTime;

    //Logic
    for(auto it = mActors.begin(); it != mActors.end(); it++)
    {
        (*it)->Tick(mDeltaTime);
    }

    //Drawing
    mRenderer->DrawAll();
}

double World::GetTime() const
{
    return mWorldTime;
}

void World::AddActor(Actor* actor)
{
    mActors.push_back(actor);
}

void World::AddMesh(Mesh* mesh)
{
    mRenderer->AddMesh(mesh);
}

void World::AddInputListener(Actor* actor) {
    mInputListeners.push_back(actor);
}

void World::MouseCallback(GLFWwindow *, double x, double y)
{
    for(auto listener : mInputListeners)
    {
        auto Obj3D = dynamic_cast<Object3D*>(listener);
        if(Obj3D!=nullptr)
        {
            Obj3D->TryProcessMouseMovement(mDeltaTime, x, y);
        }
    }
}

//Static Member Functions
void World::MouseCallbackWrapper(GLFWwindow* window, double x, double y)
{
    GetInstance().MouseCallback(window, x, y);
}

World &World::GetInstance() {
    static World world;
    return world;
}

World::~World()
{
    delete mRenderer;
}

