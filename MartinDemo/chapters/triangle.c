//
// Created by marti on 2022-12-27.

// based on chapter 5 of the textbook

// note i made up: triangles are the building blocks of graphics because they are the most elementary polygon
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

// copy and pasted directly from pdf of textbook
// simplest possible vertex shader; takes in input and directly sends it to the next shader
// C context: remember that * is for pointers. In this case, a char pointer works as a string (read more to understand)
static const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";

static int triangle() {

    // evidently using every 3 points to be a different vertex (no 2D array)
    float vertices[9] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    // note the coordinate system used here is more like a cartesian math plane,
    // centered at the center of the window, with x and y axes.

    // generate a vertex buffer object, our first OpenGL object. Give buffer ID.
    unsigned int VBO;
    // 1 means we are only giving an id for 1 buffer object (our VBO is a single int, not an array)
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
    // can just dynamically compile the source code (which is stored as a constant above) at runtime:

    // variable for shader
    unsigned int vertexShader;
    // create a shader with the GL_VERTEX_SHADER id
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    // attach the shader source code to our shader
    // first 3 arguments: shader object to compile, number of source code strings, and source code for the shader
    // 4th param is NULL for now
    // C note: read about what the & does
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    // compile the shader
    glCompileShader(vertexShader);


    // check for compilation errors: (self note: should i be using helper functions for these things???)

    // an int (1 or 0) for whether compilation succeeded
    int success;
    // a string for the info log (error info if there was failure)
    char infoLog[512];
    // store whether the compilation succeeded in the success variable:
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    // if there was not a success, get and print the info log:
    if (!success) {
        // get the error info
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        // print it (using printf because C doesn't have cout)
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s", infoLog);

    }


    // running this for the first time, i get error 0xC0000005 for accessing memory i have no permission to access
    // first investigation: infoLog array
    // using commenting, looks like the error comes from above the compile checking

    // i learned address 0x0 is the null pointer (i think)

    // different things happen if i call triangle() after createWindow()
    // the infoLog turns out to be garbage


    return 0;
}