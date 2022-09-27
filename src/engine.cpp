#include <iostream>

#include "engine.hpp"

Engine::Engine()
{
  Logger::setLevel(LogLevel::DEBUG);
  this->scene = new Scene();
}

void Engine::start()
{
  Logger::debug("Starting engine");
}

void Engine::stop()
{
  Logger::debug("Stopping engine");
}
