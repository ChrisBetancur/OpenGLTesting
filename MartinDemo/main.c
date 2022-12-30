/*
 * First ever OpenGL project.
 * Made by Martin Calcaterra, December 23rd, 2022.
 *
 * Using Learn OpenGL book by Joey de Vries so far
 *
 * Note i am also learning more about C at the same time, so I am leaving notes about C specifically through my work
 * */

// < and > are for static libraries
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

// quotations are for other source files
// include the chapter 1 code (its function is static)
#include "chapters/window.c"
#include "chapters/triangle.c"

const static char *endmsg = "End of program";

int main()
{
    // this seems to have to happen before we create a triangle
    createWindow();

    triangle();

    printf("\n%s", endmsg);

    // errors have something to do with init and terminating glfw at the wrong times; maybe earlier textbook chapters
    // may help
    // i'm pretty sure right now, i'm creating a vbo after closing a window, but before terminating glfw
    glfwTerminate();

    return 0;
}
