#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <map>
#include <GLFW/glfw3.h>

#include "utils/tasking/task.hpp"

class Manager
{
private:
  /** The tasks. */
  std::map<Trigger, std::vector<Task>> tasks;

public:
  /**
   * Create a new manager instance.
   */
  Manager();

  /**
   * Destroy the manager instance.
   */
  ~Manager();

  /**
   * Add a task to the manager.
   */
  void addTask(Trigger trigger, Task task);

  /**
   * Get the tasks.
   */
  std::map<Trigger, std::vector<Task>> getTasks();

};

#endif