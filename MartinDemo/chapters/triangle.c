//
// Created by marti on 2022-12-27.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

// copy and pasted directly from pdf of textbook
// simplest possible vertex shader; takes in input and directly sends it to the next shader
const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";

static int triangle() {

    // evidently using every 3 points to be a different vertex (no 2D array)
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    // note the coordinate system used here is more like a cartesian math plane,
    // centered at the center of the window, with x and y axes.

    // generate a vertex buffer object, our first OpenGL object. Give buffer ID.
    unsigned int VBO;
    glGenBuffers(1, &VBO);

    // we can bind our vbo to a buffer target (a buffer within the GPU):
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // write our buffer data to the GPU (write to the buffer we are targeting)
    // arguments: type of buffer we want to copy data into, size of data in bytes,
    // the actual data we want to send, and how the graphics card manages the data
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // GL_STATIC_DRAW is one of 3 ways to manage the data:
    // GL_STREAM_DRAW is for setting data once and the GPU using it at most a few times
    // GL_STATIC_DRAW is for setting data once and the GPU using it many times
    // GL_DYNAMIC_DRAW is for changing the data a lot and the GPU using it many times
    //      -puts data in graphics card memory that allows for faster writes, etc.

    // next we need to make vertex and fragment shaders to process this data (remember
    // shaders are just the steps in the graphics pipeline leading to rendering)
    // OpenGL doesn't come with default vertex and fragment shaders, we have to make them


    // create vertex shader:

    // we can get a glsl plugin for CLion and make a triangle.glsl file, but for now we
    // can just compile the source code as a constant string above.


    return 0;
}