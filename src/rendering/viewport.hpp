#ifndef VIEWPORT_HPP
#define VIEWPORT_HPP

// MacOs
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
// Windows
#ifdef _WIN32
#include <windows.h>
#endif
// Linux & Windows
#include <GL/gl.h>
#endif

#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>

#include "utils/color.hpp"
#include "utils/config.hpp"

class Viewport
{
private:
  /** The window. */
  GLFWwindow *window;

  /** The width. */
  int width;
  /** The height. */
  int height;
  /** The title. */
  std::string title;

public:
  /**
   * Create a new viewport instance.
   */
  Viewport();

  /**
   * Destroy the viewport instance.
   */
  ~Viewport();

  /**
   * Get the width.
   */
  int getWidth();

  /**
   * Get the height.
   */
  int getHeight();

  /**
   * Get the window.
   */
  GLFWwindow *getWindow();
};

#endif // VIEWPORT_HPP