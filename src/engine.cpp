#include <iostream>

#include "engine.hpp"

Engine::Engine()
{
  Logger::info("Initializing engine");
  this->scene = new Scene();
}

void Engine::start()
{
  Logger::debug("Starting engine");
  this->viewport = new Viewport(
      Config::get("viewport.width").asInt(),
      Config::get("viewport.height").asInt());
}

void Engine::stop()
{
  Logger::debug("Stopping engine");
}
