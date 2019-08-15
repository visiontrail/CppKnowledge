/***********************************************************************************************************************
 * Filename:      xconfd_agent_alarm.h 
 *
 * Description:   This file contains definition of xconfd agent alarm.
 *
 * History:       2019-07-26 11:37:10
***********************************************************************************************************************/

#ifndef OAM_XCONF_AGENT_ALARM_H_
#define OAM_XCONF_AGENT_ALARM_H_

#include "xconfd_agent.h"


namespace comm
{

class XConfdAgentAlarm : public XConfdAgent
{
public:
   XConfdAgentAlarm() {}
   virtual ~XConfdAgentAlarm()     {}

   void registerCaredMsgs();
   void sendMsg(const MessagePtr& msg);
};

} // namespace comm

#endif // OAM_XCONF_AGENT_ALARM_H_
