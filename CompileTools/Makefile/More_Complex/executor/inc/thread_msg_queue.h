/***********************************************************************************************************************
 * Filename:      thread_msg_queue.h
 *
 * Description:   This file contains definition of thread msg queue.
 *
 * History:       2019-07-26 11:37:10
***********************************************************************************************************************/

#ifndef OAM_THREAD_MSG_QUEUE_H_
#define OAM_THREAD_MSG_QUEUE_H_

#include <queue>
#include "message.h"
#include "thread_condition.h"


namespace exec
{

class ThreadMsgQueue
{
private:
   std::queue<comm::MessagePtr> queue_;
   ThreadCondition threadCond_;
   bool stopFlag_;

public:
   ThreadMsgQueue() : stopFlag_(false)     {}
   virtual ~ThreadMsgQueue() {}

   void push(const comm::MessagePtr& msg);
   comm::MessagePtr pop(bool& stopFlag);
   comm::MessagePtr popWTmo(uint32_t ms, bool& stopFlag);
   void stop();
};

typedef std::shared_ptr<ThreadMsgQueue> ThreadMsgQueuePtr;

} // namespace exec

#endif // OAM_PTHREAD_MSG_QUEUE_H_
