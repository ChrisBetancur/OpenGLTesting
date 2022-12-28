# minimum required CMAKE version
cmake_minimum_required(VERSION 3.23)

# project name
project(MartinDemo C)

find_package(OpenGL REQUIRED)

# CMAKE version
set(CMAKE_C_STANDARD 23)

# variables for source and header files
set(SOURCE_FILES main.c lib/glad/src/glad.c chapters/window.c chapters/triangle.c) #source file for GLAD #consider including all source
# files in the "chapters" directory at once with some built-in function
# set(HEADER_FILES ... )

#Include GLAD
include_directories(lib/glad/include)

#Include GLFW
add_subdirectory(lib/glfw)
include_directories(lib/glfw/include)

# create an executable that is run (format: name of project, source files to run, header files to run)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})
# note that CMAKE_PROJECT_NAME is a variable referring to the name of this project

# Link the glfw and opengl libraries to this project
target_link_libraries(${CMAKE_PROJECT_NAME} glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARY})
