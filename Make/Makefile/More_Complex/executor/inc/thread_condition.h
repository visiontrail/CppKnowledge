/***********************************************************************************************************************
 * Filename:      thread_condition.h 
 *
 * Description:   This file contains definition of thread condition.
 *
 * History:       2019-07-26 11:37:10
***********************************************************************************************************************/

#ifndef OAM_THREAD_CONDITION_H_
#define OAM_THREAD_CONDITION_H_

#include <cstdint>
#include <pthread.h>


namespace exec
{

class ThreadCondition
{
private:
   pthread_mutex_t mutex_;
   pthread_cond_t cond_;

public:
   ThreadCondition();
   virtual ~ThreadCondition();

   void lock();
   void unlock();
   void wait();
   bool waitTmo(uint32_t ms);
   void signal();
};

} // namespace exec

#endif // OAM_THREAD_CONDITION_H_
