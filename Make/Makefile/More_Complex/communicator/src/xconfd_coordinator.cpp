/***********************************************************************************************************************
 * Filename:      xconfd_coordinator.cpp 
 *
 * Description:   This file contains implementation of xconfd coordinator.
 *
 * History:       2019-07-26 11:37:10
***********************************************************************************************************************/

#include "xconfd_coordinator.h"


namespace comm
{

void XConfdCoordinator::registerCaredMsgs(uint32_t moduleID)
{
   switch (moduleID)
   {
      case 0:
         /* XConfdAgentModule register messages */
         break;

      case 1:
         /* XConfdAgentModule register messages */
         break;

      default:
         break;
   }
}

void XConfdCoordinator::sendMsg(const MessagePtr& msg)
{
   switch (msg->getReceiverModuleID())
   {
      case 0:
         /* XConfdAgentModule send message */
         break;

      case 1:
         break;

      default:
         break;
   }
}

} // namespace comm
