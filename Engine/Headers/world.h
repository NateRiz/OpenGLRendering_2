#ifndef WORLD_H
#define WORLD_H
#include <vector>

class Actor;
class GLFWwindow;
class Renderer;
class Mesh;
class Camera;

class World
{
public:
    virtual ~World();
    void Update();
    void SetWindow(GLFWwindow*);
    GLFWwindow* GetWindow() const;
    double GetTime() const;
    void AddActor(Actor*);
    void AddMesh(Mesh*);
    void AddInputListener(Actor*);
    void SetActiveCamera(Camera* camera);
    Camera* GetActiveCamera() const;
    void MouseCallback(GLFWwindow*, double x, double y);


    static World& GetInstance();
    static void MouseCallbackWrapper(GLFWwindow*, double x, double y);

private:
    World();
    std::vector<Actor*>mActors;
    std::vector<Actor*>mInputListeners;
    Camera* mActiveCamera;
    Renderer* mRenderer;
    GLFWwindow* mWindow;
    float mWorldTime;
    float mDeltaTime;
    float mLastTime;
    double mMouseLastX = 0;
    double mMouseLastY = 0;



};

#endif // WORLD_H
