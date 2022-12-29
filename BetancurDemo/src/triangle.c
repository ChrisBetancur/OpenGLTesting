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

// Fragment shader only requires one output variable which is the vector of size 4 that defines the final color output. We declare var FragColor using the out keyword. next assign a vec4 to the color output s orange with alpha value as 1.0, completely opaque
const char* fragment_shader_source = "#version 330 core\n"
                                    "out vec4 FragColor;\n"
                                    "void main () {\n"
                                    "\tFragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                    "}\0"

int create_triangle() {
    //VBO is the id of the current buffer
    unsigned int VBO;

    // generate the id of the buffer with func
    glGenBuffers(1, &VBO);

    // bind the id of the buffer to the actual buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // func assigns vertices to the buffer, 4th param defines if data is static (data set only once used many times, dynamic (data changed overtime,  and used many times, and stream (data is once but used a few times)
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Create shader object where the shader will be referneced by ID
    unsigned int vertex_shader;
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);

    // func takes the shader to compile as its first argument, second specifies how many strings we are passing as the source code which is only one, and the third is the actual source code, 4th will be NULL
    glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
    //Compile shader
    glCompileShader(vertex_shader);

    // checks if compilation was successfull

    // define integer to indicate success and infolog to store any error messages
    int success;
    char infoLog[512];
    // then check if compilation was a success by calling func and passing the shader, and the success var
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    // if it wasn't a success then get the info log by func and storing messages on to the infoLog and print out the error
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infolog);
    }

    return 1;


    // TO CREATE FRAGMENT SHADER

    unsigned int fragment_shader;
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragment_shader);

    // now with both shaders compiled we link the vertex shader (which contains the location of triangle and fragment shader (which contains the color of triangle)

    unsigned int shaderProgram;
    shadderProgram = glCreateProgram();

    glAttatchShader(shaderProgram, vertexShader);
    glAttatchShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // we can check if the linking compilation has failed or not

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader_program, 512, NULL, infoLog);
        printf("ERROR::SHADER::LINKER::COMPILATION_FAILED\n%s\n", infolog);
    }

    // activates the the program object, now after every shader and rendering call this program object will be used
    glUseProgram(shader_program);

    // delete frag and vertex shader after making the shader program
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    // Now we are linking vertex attributes
    // we must tell OpenGL how the data in each vertix should be interpreted
    // Postion data is stored as 32 bit floating point values
    // each position is composed of 3 of those values
    // there is no space between each set of 3 values

    // first param specifies which vertex attribute we want to configure, we specified the location of the postion vertex attribute with layout (location = 0). This sets location of vertex to 0 and since we want to pass the data of the vertex we set it as 0.
    // second param specifies  size of the the vertex attribute which is 3 since we are passing a vec3 is composed of 3 values
    // third param specifies the type of data which is a GL_FLOAT
    // fourth param specifies what is the data to be normalized
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}
