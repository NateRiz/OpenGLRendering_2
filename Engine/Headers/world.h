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
    /**
     * Gets the time since GLFW initialized.
     * @return Time in seconds
     */
    double GetTime() const;
    /**
     * Adds an Actor object to Vector of Actors, mActors.
     */
    void AddActor(Actor*);
    /**
     * Sends a mesh to the Renderer class' mesh vector.
     */
    void AddMesh(Mesh*);
    /**
     * Adds an actor to the list of actors to be notified for events.
     */
    void AddInputListener(Actor*);
    /**
     * Sets the passed in Camera to the active camera.
     * @param camera Camera to set as active camera.
     */
    void SetActiveCamera(Camera* camera);
    Camera* GetActiveCamera() const;
    /**
     * Sends RELATIVE mouse events to all actors that are input listeners
     * @param x Current x mouse Position
     * @param y Current y mouse Position
     */
    void MouseCallback(GLFWwindow*, double x, double y);
    /**
     * This callback calls the implemented MouseCallback().
     */
    static void MouseCallbackWrapper(GLFWwindow*, double x, double y);
    static World& GetInstance();

private:
    World();
    std::vector<Actor*>mActors; /**< All actors in the scene. Automatically added in Actor constuctor.*/
    std::vector<Actor*>mInputListeners;/**< All actors that need to be notified of input events.*/
    Camera* mActiveCamera;/**< Must be one active camera at a time.*/
    Renderer* mRenderer;/**< Handles draw calls of all mesh objects.*/
    GLFWwindow* mWindow;
    float mWorldTime;/**< Time since GLFW initialized.*/
    float mDeltaTime;/**< Time since last Tick() call.*/
    float mLastTime;
    double mMouseLastX = 0;/**< Used to calculate relative mouse X position*/
    double mMouseLastY = 0;/**< Used to calculate relative mouse Y position*/



};

#endif // WORLD_H
