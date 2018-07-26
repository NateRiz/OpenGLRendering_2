#include "../Headers/window.h"

Window::Window()
{
    const unsigned int SCREEN_WIDTH = 800;
    const unsigned int SCREEN_HEIGHT = 600;
    //Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Window creation
    mWindow = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "VOXEL_3", NULL, NULL);
    if (mWindow == NULL)
    {
        std::cout<<"Could not create GLFW Window context."<<std::endl;
        return;
    }

    glfwMakeContextCurrent(mWindow);
    glfwSetFramebufferSizeCallback(mWindow, FrameBufferSizeCallback);
    //glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout<<"Failed to initialize GLAD."<<std::endl;
        return;
    }
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glEnable(GL_DEPTH_TEST);
}
Window::~Window()
{
    glfwDestroyWindow(mWindow);
    glfwTerminate();
}

GLFWwindow* Window::GetWindow() const
{
    return mWindow;
}



void FrameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0,0,width, height);
}

void Window::EnforceFPS()
{
    double delta_time = glfwGetTime() - last_tick;
    auto sleep_time = (int)(1000*((1.0/FPS) - delta_time));
    if (sleep_time > 0)
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
    last_tick = glfwGetTime();
}