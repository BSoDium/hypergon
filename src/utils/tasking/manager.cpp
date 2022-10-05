
#include "manager.hpp"

Manager::Manager()
{
  // Initialize the tasks map
  this->tasks = std::map<Trigger, std::vector<Task>>();
  for (int i = 0; i < 3; i++)
  {
    this->tasks.insert(std::pair<Trigger, std::vector<Task>>((Trigger)i, std::vector<Task>()));
  }

  // Set up OpenGL callbacks
  glfwSetKeyCallback(this->viewport->getWindow(), this->keyboardCallback);
}

void Manager::addTask(Trigger trigger, Task task)
{
  tasks[trigger].push_back(task);
}

