#include "include/opengl.h"

// defines 3 (x, y, z) coordinates for a triangle, must be normalized (0 - 1) values
float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f, 0.5f, 0.0f
}

int create_triangle() {
    //VBO is the id of the current buffer
    unsigned int VBO;

    // generate the id of the buffer with func
    glGenBuffers(1, &VBO);

    // bind the id of the buffer to the actual buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // func assigns vertices to the buffer, 4th param defines if data is static (data set only once used many times, dynamic (data changed overtime,  and used many times, and stream (data is once but used a few times)
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


}
