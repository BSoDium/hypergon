#include "viewport.hpp"

#include <iostream>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>


Viewport::Viewport(int width, int height)
{
    this->width = width;
    this->height = height;

    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        exit(1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->window = glfwCreateWindow(width, height, "Hypergon", NULL, NULL);
    if (!this->window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(1);
    }

    glfwMakeContextCurrent(this->window);

    glViewport(0, 0, width, height);
}