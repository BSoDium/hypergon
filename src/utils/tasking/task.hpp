#ifndef TASK_HPP
#define TASK_HPP

#include <vector>
#include <functional>

enum Trigger
{
  KEYBOARD,
  TIMER,
  FRAME
};


class Task
{
private:
  /** The callback. */
  std::function<void(Payload)> callback;
public:
  /**
   * Create a new task instance.
   */
  Task(std::function<void(Payload)> callback);

  /**
   * Destroy the task instance.
   */
  ~Task();

  /**
   * Run the task.
   */
  void run(Payload payload);
};
 


#endif