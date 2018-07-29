#include "glad/glad.h"
#include <iostream>
#include <vector>
#include "../Headers/object3d.h"
#include "../Headers/window.h"
#include "../Headers/world.h"
#include "../Headers/Camera.h"
#include "../Headers/transform.h"
#include "../Headers/mesh.h"
#include "../../Geometry/Headers/FieldManager.h"

int main()
{
    Window window;
    World& world = World::GetInstance();
    World::GetInstance().SetWindow(window.GetWindow());
    glfwSetCursorPosCallback(window.GetWindow(),World::MouseCallbackWrapper);


    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    auto cam = new Camera(&world, new Transform());
    (&world)->AddInputListener(cam);
    (&world)->SetActiveCamera(cam);

    auto fm = new FieldManager(&world);


    while (!glfwWindowShouldClose(window.GetWindow()))
    {
        window.EnforceFPS();



        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        (&world)->Update();

        glfwSwapBuffers(window.GetWindow());
        glfwPollEvents();

        auto e = glGetError();
        while (e!=0)
        {
            std::cout<<"ERROR: " << e << std::endl;
            e = 0;
            e = glGetError();
        }
    }
    return 0;
}