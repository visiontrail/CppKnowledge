/***********************************************************************************************************************
 * Filename:      xconfd_agent.h 
 *
 * Description:   This file contains definition of xconfd agent.
 *
 * History:       2019-07-26 11:37:10
***********************************************************************************************************************/

#ifndef OAM_XCONF_AGENT_H_
#define OAM_XCONF_AGENT_H_

#include "message.h"


namespace comm
{

class XConfdAgent
{
public:
   XConfdAgent() {}
   virtual ~XConfdAgent()     {}

   virtual void registerCaredMsgs() = 0;
   virtual void sendMsg(const MessagePtr& msg) = 0;
};

} // namespace comm

#endif // OAM_XCONF_AGENT_ALARM_H_
