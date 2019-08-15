/***********************************************************************************************************************
 * Filename:      tasks_executor.h 
 *
 * Description:   This file contains definition of tasks executor.
 *
 * History:       2019-07-26 11:37:10
***********************************************************************************************************************/

#ifndef OAM_TASKS_EXECUTOR_H_
#define OAM_TASKS_EXECUTOR_H_

#include <signal.h>


namespace exec
{

class TasksExecutor
{
private:
   static TasksExecutor* instance_;

private:
   TasksExecutor() {}
   virtual ~TasksExecutor()     {}

   static void signalHandler(int sigNum, siginfo_t* info, void* ptr);

public:
   static TasksExecutor* get_instance()
   {
      if (instance_ == nullptr)
      {
         instance_ = new TasksExecutor();
      }
      return instance_;
   }

   void init();
   void start();
};

} // namespace exec

#endif // OAM_TASKS_EXECUTOR_H_
