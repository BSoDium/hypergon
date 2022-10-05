#include <iostream>

#include "engine.hpp"

void Engine::start()
{
  Logger::debug("Starting engine");

  // Initialize all the systems
  this->scene = new Scene();
  this->viewport = new Viewport();
  this->manager = new Manager();
}

void Engine::stop()
{
  Logger::debug("Stopping engine");
}
