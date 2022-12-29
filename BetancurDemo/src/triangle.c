#include "include/triangle.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define WIDTH 800
#define HEIGHT 600

// defines 3 (x, y, z) coordinates for a triangle, must be normalized (0 - 1) values
float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f, 0.5f, 0.0f
};

// var defines shader
// first starts with a declaration of version of opengl, next deines all the input vertex attributes in the vertex shader with in keyword. For now we only care about  the position data for a single vertex attribute.
const char* vertex_shader_source = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main() {\n"
                                 "  gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";

// Fragment shader only requires one output variable which is the vector of size 4 that defines the final color output. We declare var FragColor using the out keyword. next assign a vec4 to the color output s orange with alpha value as 1.0, completely opaque
const char* fragment_shader_source = "#version 330 core\n"
                                    "out vec4 FragColor;\n"
                                    "void main () {\n"
                                    "\tFragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                    "}\0";

int create_triangle() {
    //VBO is the id of the current buffer
    unsigned int VBO;

    // generate the id of the buffer with func
    glGenBuffers(1, &VBO);

    // bind the id of the buffer to the actual buffer
    /*glBindBuffer(GL_ARRAY_BUFFER, VBO);*/

    // func assigns vertices to the buffer, 4th param defines if data is static (data set only once, used many times), dynamic (data changed overtime,  and used many times, and stream (data is once but used a few times)
    /*glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Create shader object where the shader will be referneced by ID
    unsigned int vertex_shader;
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);

    // func takes the shader to compile as its first argument, second specifies how many strings we are passing as the source code which is only one, and the third is the actual source code, 4th will be NULL
    glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
    //Compile shader
    glCompileShader(vertex_shader);*/

    // checks if compilation was successfull

    // define integer to indicate success and infolog to store any error messages
    /*int success;
    char infoLog[512];
    // then check if compilation was a success by calling func and passing the shader, and the success var
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);

    // if it wasn't a success then get the info log by func and storing messages on to the infoLog and print out the error
    if (!success) {
        glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
    }*/



    // TO CREATE FRAGMENT SHADER

    /*unsigned int fragment_shader;
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragment_shader);

    // now with both shaders compiled we link the vertex shader (which contains the location of triangle and fragment shader (which contains the color of triangle)

    unsigned int shader_program;
    shader_program = glCreateProgram();

    glAttatchShader(shader_program, vertex_shader);
    glAttatchShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);

    // we can check if the linking compilation has failed or not

    glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader_program, 512, NULL, infoLog);
        printf("ERROR::SHADER::LINKER::COMPILATION_FAILED\n%s\n", infoLog);
    }*/

    // activates the the program object, now after every shader and rendering call this program object will be used
    //glUseProgram(shader_program);

    // delete frag and vertex shader after making the shader program
    /*glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);*/

    // Now we are linking vertex attributes
    // we must tell OpenGL how the data in each vertix should be interpreted
    // Postion data is stored as 32 bit floating point values
    // each position is composed of 3 of those values
    // there is no space between each set of 3 values

    // first param specifies which vertex attribute we want to configure, we specified the location of the postion vertex attribute with layout (location = 0). This sets location of vertex to 0 and since we want to pass the data of the vertex we set it as 0.
    // second param specifies  size of the the vertex attribute which is 3 since we are passing a vec3 is composed of 3 values
    // third param specifies the type of data which is a GL_FLOAT
    // fourth param specifies what is the data to be normalized
    // fifth argument is the stride which tells us the space between consecutive vertex attributes. Since the next set of postion data is located 3 times the size of a float we specify that value as the stride.
    // last param is a type of void*, this is the offset of where the postion data begins in the buffer since the postion data is at the start of the data array and this value is 0, later on this param will be explored mor ein detail
    /*
     * glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);*/

    // VBO is bound to GL_ARRAY_BUFFER when calling glVertexAttribPointer
    // before drawing the triangle, you must copy the vertices array in a buffer for OPengGL to use
    /*
     *
     * glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);*/
    // then set the vertex attribes pointers
    /*
     * glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);*/
    // then use the shader program to render the object
    /*
     * glUseProgram(shader_program);*/

    // vertex array object VAO can be bound like a vertex buffer object. Any subsequent vertex attribute calls now will be stored in the VAO.
    // The reason why is because when configuring vertex attribute pointers you only have to make those calls once and whenever we want to draw the object we can just bind the corresponding VAO. this makes switching between vertex data and attribute configurations as easy as binding different VAO.
    // VAO stores glEnableVertexAttribArray or glDisableVertexAtribArray, vertexAttribute configs via glVertexAttribPointer and vertex buffer objects associated with vertex attributes by calls to glVertexAttribPointer

    /*unsigned int VAO;
    glGenVertexArrays(1, &VAO);


    // bind vertex array objects
    glBindVertexArray(VAO);
    // copy our vertices array in a buffer for OpengGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // the set our vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);*/

    printf("Hello\n");

    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = init_window();


    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        return -1;
    }



    /*glUseProgram(shader_program);
    glBindVertexArray(VAO);

    glDrawArrays(GL_TRIANGLES, 0, 3);*/

    render_window(window);

    return 0;
}

GLFWwindow* init_window() {
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "demo", NULL, NULL);

    if (window == NULL) {
        printf("Failed to create window\n");
        return NULL;
    }
    glfwMakeContextCurrent(window);

    return window;
}

void render_window(GLFWwindow* window) {

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback_triangle);

    while (!glfwWindowShouldClose(window)) {
        process_input_triangle(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
}

void framebuffer_size_callback_triangle(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// gets user input in this is case it exits
void process_input_triangle(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
