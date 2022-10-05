#ifndef ENGINE_HPP
#define ENGINE_HPP

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1

#include "utils/logging/logger.hpp"
#include "rendering/viewport.hpp"
#include "utils/config.hpp"
#include "scene/scene.hpp"
#include "utils/tasking/task.hpp"
#include "utils/tasking/manager.hpp"

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
  /** The task manager. */
  Manager *manager;

  /** Private constructor. */
  Engine() {}
  Engine(Engine const &other) = delete;
  void operator=(Engine const &other) = delete;

public:

  /**
   * Get the engine instance. Create it if it doesn't exist.
   */
  static Engine& getInstance() {
    static Engine instance;
    return instance;
  }

  /**
   * Start the engine.
   */
  void start();

  /**
   * Stop the engine.
   */
  void stop();

  /**
   * Get the scene.
   */
  Scene *getScene();

  /**
   * Get the viewport.
   */
  Viewport *getViewport();

  /**
   * Get the task manager.
   */
  Manager *getManager();
};

#endif