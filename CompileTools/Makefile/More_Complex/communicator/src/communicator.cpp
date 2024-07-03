/***********************************************************************************************************************
 * Filename:      communicator.cpp 
 *
 * Description:   This file contains implementation of communicator.
 *
 * History:       2019-07-26 11:37:10
***********************************************************************************************************************/

#include "communicator.h"


namespace comm
{

Communicator* Communicator::instance_ = nullptr;

void Communicator::registerModule(const exec::ModulePtr& module)
{
   modules_[module->getModuleID()] = module;
   xconfdCoordinator_.registerCaredMsgs(module->getModuleID());
}

void Communicator::send(const MessagePtr& msg)
{
   auto iter = modules_.find(msg->getReceiverModuleID());
   if (iter != modules_.end())
   {
      iter->second->pushMsg(msg);
   }
   else
   {
      /* xconfd send the message */
   }
}

void Communicator::receive(const MessagePtr& msg)
{
   auto iter = modules_.find(msg->getReceiverModuleID());
   if (iter != modules_.end())
   {
      iter->second->pushMsg(msg);
   }
}

} // namespace comm
