#include <iostream>

#include "engine.hpp"

Engine *engine;

namespace core
{
  void init()
  {
    engine = new Engine();
  }

  void start()
  {
    engine->start();
  }
}