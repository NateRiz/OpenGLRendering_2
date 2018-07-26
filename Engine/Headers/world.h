#ifndef WORLD_H
#define WORLD_H
#include <vector>
class Actor;
class GLFWwindow;
class Renderer;
class Mesh;

class World
{
public:
    virtual ~World();
    void Update();
    double GetTime() const;
    void AddActor(Actor*);
    void AddMesh(Mesh*);
    void AddInputListener(Actor*);
    void MouseCallback(GLFWwindow*, double x, double y);


    static World& GetInstance();
    static void MouseCallbackWrapper(GLFWwindow*, double x, double y);

private:
    World();
    std::vector<Actor*>mActors;
    std::vector<Actor*>mInputListeners;

    Renderer* mRenderer;
    float mWorldTime;
    float mDeltaTime;
    float mLastTime;


};

#endif // WORLD_H
