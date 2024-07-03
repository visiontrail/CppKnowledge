/***********************************************************************************************************************
 * Filename:      thread.cpp 
 *
 * Description:   This file contains implementation of thread.
 *
 * History:       2019-07-26 11:37:10
***********************************************************************************************************************/

#include "thread.h"


namespace exec
{

#define STACK_SIZE 4 * 1024

void Thread::start()
{
   pthread_attr_t attr;
   pthread_attr_init(&attr);
   pthread_attr_setstacksize(&attr, STACK_SIZE);

   pthread_create(&id_, &attr, Thread::main, this);
}

void Thread::stop()
{
   msgQueue_->stop();
}

void* Thread::main(void* args)
{
   auto thread = static_cast<Thread*>(args);

   bool stopFlag = false;
   while (!stopFlag)
   {
      thread->processFunc_(thread->msgQueue_->pop(stopFlag));
   }

   pthread_exit(nullptr);
}

} // namespace exec
