/***********************************************************************************************************************
 * Filename:      module.h 
 *
 * Description:   This file contains definition of module.
 *
 * History:       2019-07-26 11:37:10
***********************************************************************************************************************/

#ifndef OAM_MODULE_H_
#define OAM_MODULE_H_

#include "thread.h"


namespace exec
{

#define STACK_SIZE 16 * 1024
#define MODULE_THREAD_NUM 1

class Module
{
protected:
   uint32_t id_;
   std::string name_;
   ThreadMsgQueuePtr msgQueue_;
   std::vector<ThreadPtr> threads_;

public:
   Module(uint32_t moduleID, const std::string& name, const ThreadMsgQueuePtr& msgQueue)
      : id_(moduleID), name_(name), msgQueue_(std::make_shared<ThreadMsgQueue>()) {}
   virtual ~Module()   {}

   uint32_t getModuleID() { return id_; }

   void start(ProcessFunc_t func, uint8_t threadNum = MODULE_THREAD_NUM);
   void stop();
   void pushMsg(const comm::MessagePtr& msg);
};

typedef std::shared_ptr<Module> ModulePtr;

} // namespace exec

#endif // OAM_MODULE_H_
