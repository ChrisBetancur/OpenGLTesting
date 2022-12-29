/*#include <glad/glad.h>
#include <glfw/glfw3.h>*/


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/bet_window.h"


int create() {

    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //glfwWindowHint(GLFW_OPENGL_FOWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // creates window, passses width and height, name of window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Demo", NULL, NULL);

    if (window == NULL) {
        printf("Failed to create window\n");
        return -1;
    }

    // Sets window as current window to display
    glfwMakeContextCurrent(window);

    // GLAD manages function pointers for OpenGL so must initialize Glad before calling any OpenGL function
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        return -1;
    }

    // Tells Opengl how to display data and the coordinates, first and second says the location, 3rd and 4th defines the size of the current rendering window in pizels which is equal to the window size
    //glViewPort(0, 0, 800, 600);

    // tells opengl to call function framebuffer_size_callback everytime user resizes window
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    // Render loop, pollevents chacks if any events are triggered like keyboard input or mouse
    // swapbuffers will swap the color buffer, which contains the color values for each pized in the window and will show the colors as the output
    while(!glfwWindowShouldClose(window)) {
        process_input(window);

        //Rendering commands will be placed here
        //Specifies the color to clear the screen with. and when clear is called the color buffer will be filled with color specified
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();

    return 0;

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// gets user input in this is case it exits
void process_input(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
