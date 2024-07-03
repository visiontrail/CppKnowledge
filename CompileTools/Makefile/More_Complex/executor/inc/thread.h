/***********************************************************************************************************************
 * Filename:      thread.h 
 *
 * Description:   This file contains definition of thread.
 *
 * History:       2019-07-26 11:37:10
***********************************************************************************************************************/

#ifndef OAM_THREAD_H_
#define OAM_THREAD_H_

#include <functional>
#include "thread_msg_queue.h"


namespace exec
{

typedef std::function<void(comm::MessagePtr)> ProcessFunc_t;

class Thread
{
private:
   pthread_t id_;
   ProcessFunc_t processFunc_;
   
   ThreadMsgQueuePtr msgQueue_;

public:
   Thread(ProcessFunc_t func, const ThreadMsgQueuePtr& msgQueue) : processFunc_(func), msgQueue_(msgQueue) {}
   virtual ~Thread()   {}

   void start();
   void stop();

   static void* main(void* args);
};

typedef std::shared_ptr<Thread> ThreadPtr;

} // namespace exec

#endif // OAM_THREAD_H_
