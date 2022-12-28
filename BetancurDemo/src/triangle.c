#include "include/opengl.h"

// defines 3 (x, y, z) coordinates for a triangle, must be normalized (0 - 1) values
float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f, 0.5f, 0.0f
}

// var defines shader
// first starts with a declaration of version of opengl, next deines all the input vertex attributes in the vertex shader with in keyword. For now we only care about  the position data for a single vertex attribute. 
const char* vertex_shader_source = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "{\n"
                                 "  gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";

int create_triangle() {
    //VBO is the id of the current buffer
    unsigned int VBO;

    // generate the id of the buffer with func
    glGenBuffers(1, &VBO);

    // bind the id of the buffer to the actual buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // func assigns vertices to the buffer, 4th param defines if data is static (data set only once used many times, dynamic (data changed overtime,  and used many times, and stream (data is once but used a few times)
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int vertex_shader;
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
    glCompileShader(vertex_shader);
}
