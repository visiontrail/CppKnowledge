/***********************************************************************************************************************
 * Filename:      module.cpp 
 *
 * Description:   This file contains implementation of module.
 *
 * History:       2019-07-26 11:37:10
***********************************************************************************************************************/

#include "module.h"


namespace exec
{

void Module::start(ProcessFunc_t func, uint8_t threadNum)
{
   for (int i = 0; i < threadNum; ++i)
   {
      auto thread = std::make_shared<Thread>(func, msgQueue_);
      thread->start();

      threads_.push_back(thread);
   }
}

void Module::stop()
{
   for (auto& thread : threads_)
   {
      thread->stop();
   }
}

void Module::pushMsg(const comm::MessagePtr& msg)
{
   msgQueue_->push(msg);
}

} // namespace exec
