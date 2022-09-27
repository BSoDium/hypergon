#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "scene/scene.hpp"
#include "utils/logging/logger.hpp"

class Engine
{
private:
  /** The root scene. */
  Scene *scene;

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