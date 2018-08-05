#include "../Headers/world.h"
#include "../Headers/actor.h"
#include "../Headers/object3d.h"
#include "../Headers/Renderer.h"
#include "../Headers/Sun.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>
World::World()
{
    mWorldTime = (float)glfwGetTime();
    mDeltaTime = mWorldTime;
    mLastTime = mWorldTime;
    mRenderer = new Renderer();
    mSun = new Sun(this);
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
void World::SetWindow(GLFWwindow* window)
{
    mWindow = window;
}
GLFWwindow* World::GetWindow() const
{
    return mWindow;
}
double World::GetTime() const
{
    return mWorldTime;
}
Mesh* World::GetSun() const
{
    return mSun;
}

void World::AddActor(Actor* actor)
{
    mActors.push_back(actor);
}

void World::AddMesh(Mesh* mesh)
{
    mRenderer->AddMesh(mesh);
}

void World::AddInputListener(Actor* actor)
{
    mInputListeners.push_back(actor);
}

void World::SetActiveCamera(Camera* camera)
{
    mActiveCamera = camera;
}

Camera* World::GetActiveCamera() const
{
    return mActiveCamera;
}

void World::MouseCallback(GLFWwindow *, double x, double y)
{
    double mouseRelativeX = mMouseLastX - x;
    double mouseRelativeY = mMouseLastY - y;
    mMouseLastX = x;
    mMouseLastY = y;
    for(auto listener : mInputListeners)
    {
        auto Obj3D = dynamic_cast<Object3D*>(listener);
        if(Obj3D!=nullptr)
        {
            Obj3D->TryProcessMouseMovement(mDeltaTime, mouseRelativeX, mouseRelativeY);
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
    for(auto actor: mActors)
    {
        delete actor;
    }

    delete mRenderer;
}


