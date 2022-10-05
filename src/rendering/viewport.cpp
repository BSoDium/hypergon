#include "viewport.hpp"

#include <iostream>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>

Viewport::Viewport()
{
    this->width = Config::get("viewport.width").asInt();
    this->height = Config::get("viewport.height").asInt();
    this->title = Config::get("viewport.title").asString();

    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        exit(1);
    }

    Color *cc = new Color(Config::get("viewport.clearColor").asString());

    float nearPlane = Config::get("viewport.nearPlane").asFloat();
    float farPlane = Config::get("viewport.farPlane").asFloat();

    glClearColor(cc->r, cc->g, cc->b, cc->a);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0f, (float)width / (float)height, nearPlane, farPlane);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Gouraud shading
    glEnable(GL_NORMALIZE);
    // Enable color material blending
    glEnable(GL_COLOR_MATERIAL);
    // Enable smooth shading
    glShadeModel(GL_SMOOTH);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    this->window = glfwCreateWindow(width, height, Config::get("viewport.title").asString().c_str(), NULL, NULL);
    if (!this->window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(1);
    }

    glfwMakeContextCurrent(this->window);
}

Viewport::~Viewport()
{
    glfwTerminate();
}

int Viewport::getWidth()
{
    return this->width;
}

int Viewport::getHeight()
{
    return this->height;
}

GLFWwindow *Viewport::getWindow()
{
    return this->window;
}