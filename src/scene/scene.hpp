#ifndef SCENE_HPP
#define SCENE_HPP

#include "node.hpp"

class Scene : public Node
{
private:
  /** Array of nodes in the scene. */
  Node *nodes;

public:
  /**
   * Create a new scene instance.
   */
  Scene();

  /**
   * Add a node to the scene.
   */
  void addNode(Node node);

  /**
   * Remove a node from the scene.
   */
  void removeNode(Node node);

  /**
   * Get the nodes in the scene.
   */
  Node *getNodes();

  /**
   * Get the number of nodes in the scene.
   */
  int getNumNodes();

  /**
   * Get a node from the scene.
   */
  Node getNode(int index);
};

#endif