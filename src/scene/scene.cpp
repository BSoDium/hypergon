#include "scene.hpp"

Scene::Scene() : LogEmitter("Scene")
{
  this->nodes = new Node[0];
  this->debug("Created scene");
}