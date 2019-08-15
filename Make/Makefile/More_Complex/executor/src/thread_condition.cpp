/***********************************************************************************************************************
 * Filename:      thread_condition.cpp 
 *
 * Description:   This file contains implementation of thread condition.
 *
 * History:       2019-07-26 11:37:10
***********************************************************************************************************************/

#include <errno.h>
#include <sys/time.h>
#include "thread_condition.h"


namespace exec
{

ThreadCondition::ThreadCondition()
{
   pthread_mutex_init(&mutex_, nullptr);
   pthread_cond_init(&cond_, nullptr);
}

ThreadCondition::~ThreadCondition()
{
   pthread_cond_destroy(&cond_);
   pthread_mutex_destroy(&mutex_);
}

void ThreadCondition::lock()
{
   pthread_mutex_lock(&mutex_);
}

void ThreadCondition::unlock()
{
   pthread_mutex_unlock(&mutex_);
}

void ThreadCondition::wait()
{
   pthread_cond_wait(&cond_, &mutex_);
}

bool ThreadCondition::waitTmo(unsigned int ms)
{
   timeval tv;
   gettimeofday(&tv, nullptr);
   tv.tv_sec += (ms / 1000);
   tv.tv_usec += ((ms % 1000) * 1000);

   if (tv.tv_usec >= 1000000)
   {
      tv.tv_sec += (tv.tv_usec / 1000000);
      tv.tv_usec %= 1000000;
   }
   
   timespec ts;
   ts.tv_sec = tv.tv_sec;
   ts.tv_nsec = tv.tv_usec * 1000;

   return (pthread_cond_timedwait(&cond_, &mutex_, &ts) == ETIMEDOUT);
}

void ThreadCondition::signal()
{
   pthread_cond_signal(&cond_);
}

} // namespace exec
