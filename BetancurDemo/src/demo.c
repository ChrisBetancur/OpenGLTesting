/*#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>*/

//#include "include/bet_window.h"
#include "include/triangle.h"

int main()
{
    //create_triangle();
    //create_rectangle();
    create_pentagon();
    // glfwWindowHint configures window with the the options we need

    /*if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return 1;
    }
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(600, 400, "Demo", NULL, NULL);

    if (!window) {
        fprintf(stderr, "Failed to create window\n");
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD\n");
        return 1;
    }

    //glViewport(0, 0, 800, 600);


    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0, 1.0, 1.0, 0.0);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    return 0;*/


}
