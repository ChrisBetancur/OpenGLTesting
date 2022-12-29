#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "opengl.h"

void framebuffer_size_callback_triangle(GLFWwindow* window, int width, int height);

void process_input_triangle(GLFWwindow* window);

void render_window(GLFWwindow* window);

GLFWwindow* init_window();

int create_triangle();

#endif
