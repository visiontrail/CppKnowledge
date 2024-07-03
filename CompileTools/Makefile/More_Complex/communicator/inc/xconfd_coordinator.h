/***********************************************************************************************************************
 * Filename:      xconfd_coordinator.h 
 *
 * Description:   This file contains definition of xconfd coordinator.
 *
 * History:       2019-07-26 11:37:10
***********************************************************************************************************************/

#ifndef OAM_XCONF_COORDINATOR_H_
#define OAM_XCONF_COORDINATOR_H_

#include <cstdint>
#include "message.h"


namespace comm
{

class XConfdCoordinator
{
private:
   /* XConfdAgentModules */

public:
   XConfdCoordinator() {}
   virtual ~XConfdCoordinator()      {}

   void registerCaredMsgs(uint32_t moduleID);
   void sendMsg(const MessagePtr& msg);
};

} // namespace comm

#endif // OAM_XCONF_COORDINATOR_H_
