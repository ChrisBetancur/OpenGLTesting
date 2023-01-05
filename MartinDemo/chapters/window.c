//
// Created by marti on 2022-12-27.

// i still need to actually go through this code with the textbook to understand what
// it does

// chris got this code from online
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

// making the function static makes it so that it is only available within this file
// 3 solutions to write function in file A and call in file B
// 1: don't include file B in file A, just call file B's function directly
// 2: make file B's function static, include file B in file A, and call the function
// 3: create a header file defining the function and such, have file B include it and define the function, and have
// file A include the header file as well and call the function (most modular)
static int createWindow()
{
    // initialize glfw using glfwInit, and use the return value to tell if it succeeded
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return 1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

/*#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FOWARD_COMPAT, GLFW_TRUE);
#endif*/
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(600, 400, "First_Window", NULL, NULL);

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
        //color of the window
        glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    // terminate glfw
    //glfwTerminate();

    // this somehow stops my error in triangle.c after i uncomment it (when i do glfwTerminate above here instead of in
    // main)
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    return 0;
}
