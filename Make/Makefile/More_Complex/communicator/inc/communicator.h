/***********************************************************************************************************************
 * Filename:      communicator.h 
 *
 * Description:   This file contains definition of communicator.
 *
 * History:       2019-07-26 11:37:10
***********************************************************************************************************************/

#ifndef OAM_COMMUNICATOR_H_
#define OAM_COMMUNICATOR_H_

#include <map>
#include "module.h"
#include "message.h"
#include "xconfd_coordinator.h"


namespace comm
{

class Communicator
{
private:
   static Communicator* instance_;
   std::map<uint32_t, exec::ModulePtr> modules_;
   XConfdCoordinator xconfdCoordinator_;

private:
   Communicator() {}
   virtual ~Communicator()     {}

public:
   static Communicator* get_instance()
   {
      if (instance_ == nullptr)
      {
         instance_ = new Communicator();
      }
      return instance_;
   }

   void registerModule(const exec::ModulePtr& module);
   void send(const MessagePtr& msg);
   void receive(const MessagePtr& msg);
};

} // namespace comm

#endif // OAM_COMMUNICATOR_H_
