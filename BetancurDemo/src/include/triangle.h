#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "opengl.h"

void framebuffer_size_callback_triangle(GLFWwindow* window, int width, int height);

void process_input_triangle(GLFWwindow* window);

void render_window(GLFWwindow* window, unsigned int shader_program);

GLFWwindow* init_window();

int create_triangle();

int create_rectangle();

int create_pentagon();

int init_shader_program();

int init_vertex_shader();

int init_fragment_shader();

int compilation_shader_status(unsigned int shader);

int linking_shader_status(unsigned int shader_program);

#endif
