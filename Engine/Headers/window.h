#ifndef WINDOW_H
#define WINDOW_H
#include <thread>
#include <chrono>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
class Window
{
public:
    Window();
    ~Window();

    GLFWwindow* GetWindow() const;

    void EnforceFPS();

private:
    GLFWwindow* mWindow;
    double last_tick = glfwGetTime();
    static constexpr double FPS = 60;
};

void FrameBufferSizeCallback(GLFWwindow* window, int width, int height);


#endif // WINDOW_H

