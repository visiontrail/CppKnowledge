/***********************************************************************************************************************
 * Filename:      thread_msg_queue.cpp 
 *
 * Description:   This file contains implementation of thread msg queue.
 *
 * History:       2019-07-26 11:37:10
***********************************************************************************************************************/

#include "thread_msg_queue.h"


namespace exec
{

void ThreadMsgQueue::push(const comm::MessagePtr& msg)
{
   threadCond_.lock();
   
   queue_.push(msg);
   threadCond_.signal();
   
   threadCond_.unlock();
}

comm::MessagePtr ThreadMsgQueue::pop(bool& stopFlag)
{
   threadCond_.lock();

   while (queue_.empty() && (!stopFlag_))
   {
      threadCond_.wait();
   }
   
   comm::MessagePtr msg = nullptr;
   if (!stopFlag_)
   {
      msg = queue_.front();
      queue_.pop();
   }
   stopFlag = stopFlag_;
   
   threadCond_.unlock();

   return msg;
}

comm::MessagePtr ThreadMsgQueue::popWTmo(uint32_t ms, bool& stopFlag)
{
   threadCond_.lock();

   bool waitTmo = false;
   while (queue_.empty() && (!stopFlag_))
   {
      waitTmo = threadCond_.waitTmo(ms);
   }
   
   comm::MessagePtr msg = nullptr;
   if (!stopFlag_ && !waitTmo)
   {
      msg = queue_.front();
      queue_.pop();
   }
   stopFlag = stopFlag_;
   
   threadCond_.unlock();

   return msg;
}

void ThreadMsgQueue::stop()
{
   threadCond_.lock();

   stopFlag_ = true;
   threadCond_.signal();
   
   threadCond_.unlock();
}

} // namespace exec
