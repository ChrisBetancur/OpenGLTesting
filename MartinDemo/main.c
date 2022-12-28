/*
 * First ever OpenGL project.
 * Made by Martin Calcaterra, December 23rd, 2022.
 *
 * Using Learn OpenGL book by Joey de Vries so far
 * */

// < and > are for static libraries
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

// quotations are for other source files
// include the chapter 1 code
#include "chapters/window.c"

int main()
{
    createWindow();

    return 0;
}
