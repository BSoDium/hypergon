#ifndef ENGINE_HPP
#define ENGINE_HPP

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1

#include "utils/logging/logger.hpp"
#include "rendering/viewport.hpp"
#include "utils/config.hpp"
#include "scene/scene.hpp"

/**
 * Main engine class.
 */
class Engine
{
private:
  /** The root scene. */
  Scene *scene;
  /** The viewport. */
  Viewport *viewport;

public:
  /**
   * Create a new engine instance.
   */
  Engine();

  /**
   * Start the engine.
   */
  void start();

  /**
   * Stop the engine.
   */
  void stop();
};

#endif